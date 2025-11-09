#define	NPCKBD	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NPCKBD
 .global _KERNEL_OPT_NPCKBD
 .equiv _KERNEL_OPT_NPCKBD,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NPCKBD\n .global _KERNEL_OPT_NPCKBD\n .equiv _KERNEL_OPT_NPCKBD,0x0\n .endif");
#endif
