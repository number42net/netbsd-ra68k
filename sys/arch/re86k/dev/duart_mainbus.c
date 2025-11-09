/*	$NetBSD$	*/

/*
 * MC68681 Dual UART - Mainbus attachment for RE86K
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD$");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/device.h>
#include <sys/tty.h>

#include <machine/bus.h>
#include <machine/intr.h>

#include <re86k/dev/mainbusvar.h>

#include "duartreg.h"
#include "duartvar.h"

/* Console state from duart.c */
extern bus_space_handle_t mc68681_cons_ioh;
extern int mc68681_cons_chan;

static int mc68681_mainbus_match(device_t, cfdata_t, void *);
static void mc68681_mainbus_attach(device_t, device_t, void *);

CFATTACH_DECL_NEW(duart_mainbus, sizeof(struct mc68681_softc),
    mc68681_mainbus_match, mc68681_mainbus_attach, NULL, NULL);

static const struct device_compatible_entry compat_data[] = {
	{ .compat = "motorola,mc68681" },
	DEVICE_COMPAT_EOL
};

static int
mc68681_mainbus_match(device_t parent, cfdata_t cf, void *aux)
{
	struct mainbus_attach_args * const ma = aux;
	
	return mainbus_compatible_match(ma, compat_data);
}

static void
mc68681_mainbus_attach(device_t parent, device_t self, void *aux)
{
	struct mc68681_softc * const sc = device_private(self);
	struct mainbus_attach_args * const ma = aux;
	
	sc->sc_dev = self;
	sc->sc_iot = ma->ma_st;
	sc->sc_console_chan = -1;
	
	/* Check if this is the console device */
	if (mc68681_cons_chan >= 0 && ma->ma_addr == 0x00a00000) {
		/* Console was already mapped in mc68681_cnattach */
		sc->sc_ioh = mc68681_cons_ioh;
		sc->sc_console_chan = mc68681_cons_chan;
		sc->sc_chans[mc68681_cons_chan].ch_flags |= MC68681_CH_CONSOLE;
	} else {
		/* Map registers */
		if (bus_space_map(ma->ma_st, ma->ma_addr, 0x10, 0,
		    &sc->sc_ioh) != 0) {
			aprint_error(": couldn't map registers\n");
			return;
		}
	}
	
	/* Attach the driver */
	mc68681_attach_subr(sc);
	
	/* Set up interrupt handler if interrupt specified */
	if (ma->ma_irq != -1) {
		char strbuf[INTR_STRING_BUFSIZE];
		
		sc->sc_ih = intr_establish(mc68681_intr, sc,
		    ma->ma_irq, IPL_TTY, 0);
		if (sc->sc_ih == NULL) {
			aprint_error_dev(self,
			    "couldn't install interrupt handler\n");
			return;
		}
		aprint_normal_dev(self, "interrupting at %s\n",
		    intr_string(sc->sc_ih, strbuf, sizeof(strbuf)));
		
		/* Enable receive interrupts on both channels */
		MC68681_WRITE(sc, MC68681_IMR,
		    MC68681_INT_RXRDYA | MC68681_INT_RXRDYB);
	} else {
		aprint_normal_dev(self, "polled mode\n");
	}
}
