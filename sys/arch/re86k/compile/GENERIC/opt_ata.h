/* option `ATADEBUG' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_ATADEBUG
 .global _KERNEL_OPT_ATADEBUG
 .equiv _KERNEL_OPT_ATADEBUG,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_ATADEBUG\n .global _KERNEL_OPT_ATADEBUG\n .equiv _KERNEL_OPT_ATADEBUG,0x6e074def\n .endif");
#endif
/* option `ATADEBUG_MASK' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_ATADEBUG_MASK
 .global _KERNEL_OPT_ATADEBUG_MASK
 .equiv _KERNEL_OPT_ATADEBUG_MASK,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_ATADEBUG_MASK\n .global _KERNEL_OPT_ATADEBUG_MASK\n .equiv _KERNEL_OPT_ATADEBUG_MASK,0x6e074def\n .endif");
#endif
/* option `ATA_NO_DOWNGRADE_MODE' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE
 .global _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE
 .equiv _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE\n .global _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE\n .equiv _KERNEL_OPT_ATA_NO_DOWNGRADE_MODE,0x6e074def\n .endif");
#endif
/* option `ATADEBUG_WD_MASK' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_ATADEBUG_WD_MASK
 .global _KERNEL_OPT_ATADEBUG_WD_MASK
 .equiv _KERNEL_OPT_ATADEBUG_WD_MASK,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_ATADEBUG_WD_MASK\n .global _KERNEL_OPT_ATADEBUG_WD_MASK\n .equiv _KERNEL_OPT_ATADEBUG_WD_MASK,0x6e074def\n .endif");
#endif
