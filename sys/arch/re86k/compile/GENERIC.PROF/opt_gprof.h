#define	GPROF	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_GPROF
 .global _KERNEL_OPT_GPROF
 .equiv _KERNEL_OPT_GPROF,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_GPROF\n .global _KERNEL_OPT_GPROF\n .equiv _KERNEL_OPT_GPROF,0x1\n .endif");
#endif
