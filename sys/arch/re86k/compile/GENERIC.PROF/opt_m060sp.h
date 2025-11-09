/* option `M060SP' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M060SP
 .global _KERNEL_OPT_M060SP
 .equiv _KERNEL_OPT_M060SP,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M060SP\n .global _KERNEL_OPT_M060SP\n .equiv _KERNEL_OPT_M060SP,0x6e074def\n .endif");
#endif
