#define	NCD	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NCD
 .global _KERNEL_OPT_NCD
 .equiv _KERNEL_OPT_NCD,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NCD\n .global _KERNEL_OPT_NCD\n .equiv _KERNEL_OPT_NCD,0x0\n .endif");
#endif
