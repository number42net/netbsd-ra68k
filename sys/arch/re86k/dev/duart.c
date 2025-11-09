/*	$NetBSD$	*/

/*
 * MC68681 Dual UART Driver
 * Simplified polled driver for console support
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>
#include <sys/tty.h>
#include <sys/conf.h>
#include <sys/kauth.h>

#include <machine/bus.h>
#include <machine/intr.h>

#include <dev/cons.h>

#include "duartreg.h"
#include "duartvar.h"

/* Console state */
static bus_space_tag_t mc68681_cons_iot;
bus_space_handle_t mc68681_cons_ioh;
/* Console device structure - defined at bottom of file */
extern struct consdev consdev_mc68681;
int mc68681_cons_chan = -1;
static int mc68681_cons_rate;

/* Forward declarations */
static void mc68681_chan_reset(struct mc68681_softc *, int);
static void mc68681_chan_param(struct mc68681_softc *, int, int, tcflag_t);

/*
 * Reset the DUART
 */
void
mc68681_reset(struct mc68681_softc *sc)
{
	/* Reset both channels */
	mc68681_chan_reset(sc, MC68681_CHAN_A);
	mc68681_chan_reset(sc, MC68681_CHAN_B);
	
	/* Disable all interrupts */
	MC68681_WRITE(sc, MC68681_IMR, 0x00);
}

/*
 * Reset a single channel
 */
static void
mc68681_chan_reset(struct mc68681_softc *sc, int chan)
{
	uint8_t cr_reg;
	
	if (chan == MC68681_CHAN_A) {
		cr_reg = MC68681_CRA;
	}
	
	/* Reset receiver, transmitter, and error status */
	MC68681_WRITE(sc, cr_reg, MC68681_CR_RESET_RX);
	MC68681_WRITE(sc, cr_reg, MC68681_CR_RESET_TX);
	MC68681_WRITE(sc, cr_reg, MC68681_CR_RESET_ERR);
	MC68681_WRITE(sc, cr_reg, MC68681_CR_RESET_MR);
}

/*
 * Initialize a channel with specific parameters
 */
void
mc68681_init_chan(struct mc68681_softc *sc, int chan, int rate, tcflag_t cflag)
{
	mc68681_chan_reset(sc, chan);
	mc68681_chan_param(sc, chan, rate, cflag);
	
	/* Enable transmitter and receiver */
	if (chan == MC68681_CHAN_A) {
		MC68681_WRITE(sc, MC68681_CRA, 
		    MC68681_CR_TX_ENA | MC68681_CR_RX_ENA);
	} else {
		MC68681_WRITE(sc, MC68681_CRB,
		    MC68681_CR_TX_ENA | MC68681_CR_RX_ENA);
	}
}

/*
 * Set channel parameters (baud rate, data bits, parity, stop bits)
 */
static void
mc68681_chan_param(struct mc68681_softc *sc, int chan, int rate, tcflag_t cflag)
{
	uint8_t mr1, mr2, csr;
	uint8_t mr_reg, csr_reg;
	
	if (chan == MC68681_CHAN_A) {
		mr_reg = MC68681_MRA;
		csr_reg = MC68681_CSRA;
	} else {
		mr_reg = MC68681_MRB;
		csr_reg = MC68681_CSRB;
	}
	
	/* Mode Register 1: data bits and parity */
	mr1 = 0;
	
	/* Data bits */
	switch (cflag & CSIZE) {
	case CS5:
		mr1 |= MC68681_MR1_BITS_5;
		break;
	case CS6:
		mr1 |= MC68681_MR1_BITS_6;
		break;
	case CS7:
		mr1 |= MC68681_MR1_BITS_7;
		break;
	case CS8:
	default:
		mr1 |= MC68681_MR1_BITS_8;
		break;
	}
	
	/* Parity */
	if (cflag & PARENB) {
		if (cflag & PARODD)
			mr1 |= MC68681_MR1_PARITY_ODD;
		else
			mr1 |= MC68681_MR1_PARITY_EVEN;
	} else {
		mr1 |= MC68681_MR1_PARITY_NONE;
	}
	
	/* Mode Register 2: stop bits */
	mr2 = MC68681_MR2_MODE_NORMAL;
	if (cflag & CSTOPB)
		mr2 |= MC68681_MR2_STOP_2;
	else
		mr2 |= MC68681_MR2_STOP_1;
	
	/* Baud rate */
	switch (rate) {
	case 50:
		csr = MC68681_CSR_50;
		break;
	case 110:
		csr = MC68681_CSR_110;
		break;
	case 300:
		csr = MC68681_CSR_300;
		break;
	case 600:
		csr = MC68681_CSR_600;
		break;
	case 1200:
		csr = MC68681_CSR_1200;
		break;
	case 2400:
		csr = MC68681_CSR_2400;
		break;
	case 4800:
		csr = MC68681_CSR_4800;
		break;
	case 9600:
	default:
		csr = MC68681_CSR_9600;
		break;
	case 19200:
		csr = MC68681_CSR_19200;
		break;
	case 38400:
		/* 38400 requires ACR bit 7 set */
		MC68681_WRITE(sc, MC68681_ACR, MC68681_ACR_BRGSET);
		csr = MC68681_CSR_38400;
		break;
	}
	
	/* Write mode registers (must write MR1 then MR2) */
	MC68681_WRITE(sc, mr_reg, mr1);
	MC68681_WRITE(sc, mr_reg, mr2);
	
	/* Write clock select register */
	MC68681_WRITE(sc, csr_reg, csr);
	
	/* Store in channel state */
	sc->sc_chans[chan].ch_mr1 = mr1;
	sc->sc_chans[chan].ch_mr2 = mr2;
	sc->sc_chans[chan].ch_csr = csr;
}

/*
 * Polled character output
 */
int
mc68681_putc(struct mc68681_softc *sc, int chan, int c)
{
	uint8_t sr_reg, tb_reg;
	int timeout = 10000;
	
	if (chan == MC68681_CHAN_A) {
		sr_reg = MC68681_SRA;
		tb_reg = MC68681_TBA;
	} else {
		sr_reg = MC68681_SRB;
		tb_reg = MC68681_TBB;
	}
	
	/* Wait for transmitter ready */
	while (timeout-- > 0) {
		if (MC68681_READ(sc, sr_reg) & MC68681_SR_TXRDY)
			break;
		delay(1);
	}
	
	if (timeout <= 0)
		return -1;
	
	/* Write character */
	MC68681_WRITE(sc, tb_reg, c);
	
	return 0;
}

/*
 * Polled character input (non-blocking)
 */
int
mc68681_getc(struct mc68681_softc *sc, int chan)
{
	uint8_t sr_reg, rb_reg;
	
	if (chan == MC68681_CHAN_A) {
		sr_reg = MC68681_SRA;
		rb_reg = MC68681_RBA;
	} else {
		sr_reg = MC68681_SRB;
		rb_reg = MC68681_RBB;
	}
	
	/* Check if character available */
	if ((MC68681_READ(sc, sr_reg) & MC68681_SR_RXRDY) == 0)
		return -1;
	
	/* Read character */
	return MC68681_READ(sc, rb_reg);
}

/*
 * Poll for character (blocking)
 */
int
mc68681_poll(struct mc68681_softc *sc, int chan)
{
	int c;
	
	while ((c = mc68681_getc(sc, chan)) == -1)
		;
	
	return c;
}

/*
 * Console attachment
 */
void
mc68681_cnattach(bus_space_tag_t iot, bus_addr_t addr, int chan, 
    int rate, tcflag_t cflag)
{
	struct mc68681_softc sc;
	
	mc68681_cons_iot = iot;
	mc68681_cons_chan = chan;
	mc68681_cons_rate = rate;
	
	/* Map console registers */
	if (bus_space_map(iot, addr, 0x10, 0, &mc68681_cons_ioh) != 0)
		panic("mc68681_cnattach: couldn't map registers");
	
	/* Initialize temporary softc for setup */
	sc.sc_iot = iot;
	sc.sc_ioh = mc68681_cons_ioh;
	mc68681_init_chan(&sc, chan, rate, cflag);
/* Forward declaration */
extern struct consdev consdev_mc68681;
	/* Mark as console */
	cn_tab = &consdev_mc68681;
	cn_set_magic("+++++");
}

/*
 * Console probe
 */
void
mc68681_cnprobe(struct consdev *cp)
{
	cp->cn_pri = CN_NORMAL;
}

/*
 * Console init
 */
void
mc68681_cninit(struct consdev *cp)
{
	/* Nothing to do, already initialized in cnattach */
}

/*
 * Console getc
 */
int
mc68681_cngetc(dev_t dev)
{
	struct mc68681_softc sc;
	
	sc.sc_iot = mc68681_cons_iot;
	sc.sc_ioh = mc68681_cons_ioh;
	
	return mc68681_poll(&sc, mc68681_cons_chan);
}

/*
 * Console putc
 */
void
mc68681_cnputc(dev_t dev, int c)
{
	struct mc68681_softc sc;
	
	sc.sc_iot = mc68681_cons_iot;
	sc.sc_ioh = mc68681_cons_ioh;
	
	/* Convert LF to CR+LF */
	if (c == '\n')
		mc68681_putc(&sc, mc68681_cons_chan, '\r');
	
	mc68681_putc(&sc, mc68681_cons_chan, c);
}

/*
 * Console pollc (for debugger)
 */
void
mc68681_cnpollc(dev_t dev, int on)
{
	/* Nothing to do for polled console */
}

/* Console device structure */
struct consdev consdev_mc68681 = {
	.cn_probe = mc68681_cnprobe,
	.cn_init = mc68681_cninit,
	.cn_getc = mc68681_cngetc,
	.cn_putc = mc68681_cnputc,
	.cn_pollc = mc68681_cnpollc,
	.cn_dev = NODEV,
	.cn_pri = CN_NORMAL,
};

/*
 * Attach driver to device tree
 */
void
mc68681_attach_subr(struct mc68681_softc *sc)
{
	int chan;
	
	aprint_naive("\n");
	aprint_normal(": MC68681 Dual UART\n");
	
	/* Reset the DUART */
	mc68681_reset(sc);
	
	/* Initialize channels if not console */
	for (chan = 0; chan < MC68681_NCHAN; chan++) {
		if (sc->sc_chans[chan].ch_flags & MC68681_CH_CONSOLE) {
			aprint_normal_dev(sc->sc_dev, "channel %c: console\n",
			    'A' + chan);
		} else {
			/* Initialize to 9600 8N1 */
			mc68681_init_chan(sc, chan, 9600, CS8);
			aprint_normal_dev(sc->sc_dev, "channel %c: 9600 baud\n",
			    'A' + chan);
		}
	}
}

/*
 * Interrupt handler (stub for now)
 */
int
mc68681_intr(void *arg)
{
	struct mc68681_softc *sc = arg;
	uint8_t isr;
	
	isr = MC68681_READ(sc, MC68681_ISR);
	
	/* For now, just clear interrupts */
	/* TODO: Handle RX/TX interrupts */
	
	return (isr != 0);
}

/* Character device switch */
const struct cdevsw duart_cdevsw = {
	.d_open = noopen,
	.d_close = noclose,
	.d_read = noread,
	.d_write = nowrite,
	.d_ioctl = noioctl,
	.d_stop = nostop,
	.d_tty = notty,
	.d_poll = nopoll,
	.d_mmap = nommap,
	.d_kqfilter = nokqfilter,
	.d_discard = nodiscard,
	.d_flag = D_TTY
};
