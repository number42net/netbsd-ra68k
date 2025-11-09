/*	$NetBSD$	*/

/*
 * MC68681 Dual UART Driver Interface
 */

#ifndef _RE86K_MC68681VAR_H_
#define _RE86K_MC68681VAR_H_

#include <sys/tty.h>
#include <sys/bus.h>

/* Forward declaration for console */
struct consdev;

/* Channel A = 0, Channel B = 1 */
#define MC68681_CHAN_A		0
#define MC68681_CHAN_B		1
#define MC68681_NCHAN		2

/* Per-channel state */
struct mc68681_channel {
	struct tty		*ch_tty;
	uint8_t			ch_mr1;		/* Mode register 1 */
	uint8_t			ch_mr2;		/* Mode register 2 */
	uint8_t			ch_csr;		/* Clock select */
	int			ch_flags;
#define MC68681_CH_CONSOLE	0x01		/* This is the console */
};

/* Softc structure */
struct mc68681_softc {
	device_t		sc_dev;
	bus_space_tag_t		sc_iot;
	bus_space_handle_t	sc_ioh;
	void			*sc_ih;		/* Interrupt handler */
	
	struct mc68681_channel	sc_chans[MC68681_NCHAN];
	
	int			sc_console_chan;  /* Console channel (-1 = none) */
};

/* Console support */
void	mc68681_cnattach(bus_space_tag_t, bus_addr_t, int, int, tcflag_t);
void	mc68681_cnprobe(struct consdev *);
void	mc68681_cninit(struct consdev *);
int	mc68681_cngetc(dev_t);
void	mc68681_cnputc(dev_t, int);
void	mc68681_cnpollc(dev_t, int);

/* Driver functions */
void	mc68681_attach_subr(struct mc68681_softc *);
void	mc68681_reset(struct mc68681_softc *);
int	mc68681_intr(void *);

/* Channel operations */
void	mc68681_init_chan(struct mc68681_softc *, int, int, tcflag_t);
int	mc68681_param(struct tty *, struct termios *);
void	mc68681_start(struct tty *);
int	mc68681_putc(struct mc68681_softc *, int, int);
int	mc68681_getc(struct mc68681_softc *, int);
int	mc68681_poll(struct mc68681_softc *, int);

/* Register access macros */
#define MC68681_READ(sc, reg) 	bus_space_read_1((sc)->sc_iot, (sc)->sc_ioh, (reg))
#define MC68681_WRITE(sc, reg, val) 	bus_space_write_1((sc)->sc_iot, (sc)->sc_ioh, (reg), (val))

#endif /* _RE86K_MC68681VAR_H_ */
