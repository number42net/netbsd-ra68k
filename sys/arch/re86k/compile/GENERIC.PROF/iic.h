#define	NIIC	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NIIC
 .global _KERNEL_OPT_NIIC
 .equiv _KERNEL_OPT_NIIC,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NIIC\n .global _KERNEL_OPT_NIIC\n .equiv _KERNEL_OPT_NIIC,0x0\n .endif");
#endif
