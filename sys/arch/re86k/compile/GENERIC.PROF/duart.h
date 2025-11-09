#define	NDUART	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NDUART
 .global _KERNEL_OPT_NDUART
 .equiv _KERNEL_OPT_NDUART,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NDUART\n .global _KERNEL_OPT_NDUART\n .equiv _KERNEL_OPT_NDUART,0x1\n .endif");
#endif
