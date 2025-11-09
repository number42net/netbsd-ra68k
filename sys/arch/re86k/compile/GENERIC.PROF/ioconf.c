#include "ioconf.h"
/*
 * MACHINE GENERATED: DO NOT EDIT
 *
 * ioconf.c, from "GENERIC"
 */

#include <sys/param.h>
#include <sys/conf.h>
#include <sys/device.h>
#include <sys/mount.h>

static const struct cfiattrdata mainbuscf_iattrdata = {
	"mainbus", 1, {
		{ "addr", "-1", -1 },
	}
};

CFDRIVER_DECL(swwdog, DV_DULL, NULL);

CFDRIVER_DECL(vnd, DV_DISK, NULL);

CFDRIVER_DECL(fss, DV_DISK, NULL);

static const struct cfiattrdata * const mainbus_attrs[] = { &mainbuscf_iattrdata, NULL };
CFDRIVER_DECL(mainbus, DV_DULL, mainbus_attrs);

CFDRIVER_DECL(duart, DV_TTY, NULL);


struct cfdriver * const cfdriver_list_initial[] = {
	&swwdog_cd,
	&vnd_cd,
	&fss_cd,
	&mainbus_cd,
	&duart_cd,
	NULL
};

extern struct cfattach mainbus_ca;
extern struct cfattach duart_mainbus_ca;

/* locators */
static int loc[1] = {
	0xa00000,
};

static const struct cfparent pspec0 = {
	"mainbus", "mainbus", DVUNIT_ANY
};

#define NORM FSTATE_NOTFOUND
#define STAR FSTATE_STAR

struct cfdata cfdata[] = {
    /* driver           attachment    unit state      loc   flags  pspec */
/*  0: mainbus0 at root */
    { "mainbus",	"mainbus",	 0, NORM,    NULL,      0, NULL },
/*  1: duart* at mainbus? addr 0xa00000 */
    { "duart",		"duart_mainbus",	 0, STAR, loc+  0,      0, &pspec0 },
    { NULL,		NULL,		 0,    0,    NULL,      0, NULL }
};

static struct cfattach * const mainbus_cfattachinit[] = {
	&mainbus_ca, NULL
};
static struct cfattach * const duart_cfattachinit[] = {
	&duart_mainbus_ca, NULL
};

const struct cfattachinit cfattachinit[] = {
	{ "mainbus", mainbus_cfattachinit },
	{ "duart", duart_cfattachinit },
	{ NULL, NULL }
};

const short cfroots[] = {
	 0 /* mainbus0 */,
	-1
};

/* pseudo-devices */

const struct pdevinit pdevinit[] = {
	{ cpuctlattach, 1 },
	{ rndattach, 1 },
	{ putterattach, 1 },
	{ accf_dataattach, 1 },
	{ accf_httpattach, 1 },
	{ slattach, 1 },
	{ pppattach, 1 },
	{ loopattach, 1 },
	{ bpfilterattach, 1 },
	{ gifattach, 1 },
	{ stfattach, 1 },
	{ ptyattach, 1 },
	{ vndattach, 1 },
	{ fssattach, 1 },
	{ clockctlattach, 1 },
	{ ksymsattach, 1 },
	{ swwdogattach, 1 },
	{ drvctlattach, 1 },
	{ cryptoattach, 1 },
	{ swcryptoattach, 1 },
	{ 0, 0 }
};
