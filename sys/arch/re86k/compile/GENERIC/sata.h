#define	NSATA	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NSATA
 .global _KERNEL_OPT_NSATA
 .equiv _KERNEL_OPT_NSATA,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NSATA\n .global _KERNEL_OPT_NSATA\n .equiv _KERNEL_OPT_NSATA,0x0\n .endif");
#endif
