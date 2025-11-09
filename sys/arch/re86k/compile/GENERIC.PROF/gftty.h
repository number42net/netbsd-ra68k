#define	NGFTTY	0
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_NGFTTY
 .global _KERNEL_OPT_NGFTTY
 .equiv _KERNEL_OPT_NGFTTY,0x0
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_NGFTTY\n .global _KERNEL_OPT_NGFTTY\n .equiv _KERNEL_OPT_NGFTTY,0x0\n .endif");
#endif
