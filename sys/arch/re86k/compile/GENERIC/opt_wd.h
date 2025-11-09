/* option `WD_SOFTBADSECT' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_WD_SOFTBADSECT
 .global _KERNEL_OPT_WD_SOFTBADSECT
 .equiv _KERNEL_OPT_WD_SOFTBADSECT,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_WD_SOFTBADSECT\n .global _KERNEL_OPT_WD_SOFTBADSECT\n .equiv _KERNEL_OPT_WD_SOFTBADSECT,0x6e074def\n .endif");
#endif
/* option `WD_CHAOS_MONKEY' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_WD_CHAOS_MONKEY
 .global _KERNEL_OPT_WD_CHAOS_MONKEY
 .equiv _KERNEL_OPT_WD_CHAOS_MONKEY,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_WD_CHAOS_MONKEY\n .global _KERNEL_OPT_WD_CHAOS_MONKEY\n .equiv _KERNEL_OPT_WD_CHAOS_MONKEY,0x6e074def\n .endif");
#endif
