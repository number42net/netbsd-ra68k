#define	NWD	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NWD
 .global _KERNEL_OPT_NWD
 .equiv _KERNEL_OPT_NWD,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NWD\n .global _KERNEL_OPT_NWD\n .equiv _KERNEL_OPT_NWD,0x0\n .endif");
#endif
