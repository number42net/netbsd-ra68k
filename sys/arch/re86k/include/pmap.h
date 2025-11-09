/*	$NetBSD: pmap.h,v 1.2 2025/11/08 08:26:08 thorpej Exp $	*/

#ifndef _RE86K_PMAP_H_
#define	_RE86K_PMAP_H_

#ifdef __HAVE_NEW_PMAP_68K
#include <m68k/pmap_68k.h>
#else
// #error oink - using motorola pmap
#include <m68k/pmap_motorola.h>
#endif /* __HAVE_NEW_PMAP_68K */

#include <m68k/mmu_30.h>
#include <m68k/mmu_40.h>

/*
 * Qemu places the virtual devices in the last 16MB of physical
 * address space (0xff00.0000).  We use a Transparent Translation
 * register to map these VA==PA for convenience.
 */

#define	RE86K_IO_BASE		0xff000000

#define	RE86K_TT30_IO		(RE86K_IO_BASE |			\
				 TT30_E | TT30_CI | TT30_RWM |		\
				 TT30_SUPERD)

#define	RE86K_TT40_IO		(RE86K_IO_BASE |			\
				 TTR40_E | TTR40_SUPER |		\
				 PTE40_CM_NC_SER)

#endif /* _RE86K_PMAP_H_ */
