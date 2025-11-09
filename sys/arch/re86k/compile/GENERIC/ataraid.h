#define	NATARAID	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NATARAID
 .global _KERNEL_OPT_NATARAID
 .equiv _KERNEL_OPT_NATARAID,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NATARAID\n .global _KERNEL_OPT_NATARAID\n .equiv _KERNEL_OPT_NATARAID,0x0\n .endif");
#endif
