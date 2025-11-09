#define	NSATA_PMP	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NSATA_PMP
 .global _KERNEL_OPT_NSATA_PMP
 .equiv _KERNEL_OPT_NSATA_PMP,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NSATA_PMP\n .global _KERNEL_OPT_NSATA_PMP\n .equiv _KERNEL_OPT_NSATA_PMP,0x0\n .endif");
#endif
