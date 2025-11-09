/* option `M68K_MMU_HP' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_HP
 .global _KERNEL_OPT_M68K_MMU_HP
 .equiv _KERNEL_OPT_M68K_MMU_HP,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_HP\n .global _KERNEL_OPT_M68K_MMU_HP\n .equiv _KERNEL_OPT_M68K_MMU_HP,0x6e074def\n .endif");
#endif
/* option `M68K_MMU_SUN' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_SUN
 .global _KERNEL_OPT_M68K_MMU_SUN
 .equiv _KERNEL_OPT_M68K_MMU_SUN,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_SUN\n .global _KERNEL_OPT_M68K_MMU_SUN\n .equiv _KERNEL_OPT_M68K_MMU_SUN,0x6e074def\n .endif");
#endif
/* option `M68K_MMU_SUN2' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_SUN2
 .global _KERNEL_OPT_M68K_MMU_SUN2
 .equiv _KERNEL_OPT_M68K_MMU_SUN2,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_SUN2\n .global _KERNEL_OPT_M68K_MMU_SUN2\n .equiv _KERNEL_OPT_M68K_MMU_SUN2,0x6e074def\n .endif");
#endif
/* option `M68K_MMU_SUN3' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_SUN3
 .global _KERNEL_OPT_M68K_MMU_SUN3
 .equiv _KERNEL_OPT_M68K_MMU_SUN3,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_SUN3\n .global _KERNEL_OPT_M68K_MMU_SUN3\n .equiv _KERNEL_OPT_M68K_MMU_SUN3,0x6e074def\n .endif");
#endif
#define	M68K_MMU_MOTOROLA	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_MOTOROLA
 .global _KERNEL_OPT_M68K_MMU_MOTOROLA
 .equiv _KERNEL_OPT_M68K_MMU_MOTOROLA,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_MOTOROLA\n .global _KERNEL_OPT_M68K_MMU_MOTOROLA\n .equiv _KERNEL_OPT_M68K_MMU_MOTOROLA,0x1\n .endif");
#endif
/* option `M68K_MMU_68851' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_68851
 .global _KERNEL_OPT_M68K_MMU_68851
 .equiv _KERNEL_OPT_M68K_MMU_68851,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_68851\n .global _KERNEL_OPT_M68K_MMU_68851\n .equiv _KERNEL_OPT_M68K_MMU_68851,0x6e074def\n .endif");
#endif
#define	M68K_MMU_68030	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_68030
 .global _KERNEL_OPT_M68K_MMU_68030
 .equiv _KERNEL_OPT_M68K_MMU_68030,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_68030\n .global _KERNEL_OPT_M68K_MMU_68030\n .equiv _KERNEL_OPT_M68K_MMU_68030,0x1\n .endif");
#endif
#define	M68K_MMU_68040	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_68040
 .global _KERNEL_OPT_M68K_MMU_68040
 .equiv _KERNEL_OPT_M68K_MMU_68040,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_68040\n .global _KERNEL_OPT_M68K_MMU_68040\n .equiv _KERNEL_OPT_M68K_MMU_68040,0x1\n .endif");
#endif
/* option `M68K_MMU_68060' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68K_MMU_68060
 .global _KERNEL_OPT_M68K_MMU_68060
 .equiv _KERNEL_OPT_M68K_MMU_68060,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68K_MMU_68060\n .global _KERNEL_OPT_M68K_MMU_68060\n .equiv _KERNEL_OPT_M68K_MMU_68060,0x6e074def\n .endif");
#endif
/* option `M68010' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68010
 .global _KERNEL_OPT_M68010
 .equiv _KERNEL_OPT_M68010,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68010\n .global _KERNEL_OPT_M68010\n .equiv _KERNEL_OPT_M68010,0x6e074def\n .endif");
#endif
/* option `M68020' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68020
 .global _KERNEL_OPT_M68020
 .equiv _KERNEL_OPT_M68020,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68020\n .global _KERNEL_OPT_M68020\n .equiv _KERNEL_OPT_M68020,0x6e074def\n .endif");
#endif
#define	M68030	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68030
 .global _KERNEL_OPT_M68030
 .equiv _KERNEL_OPT_M68030,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68030\n .global _KERNEL_OPT_M68030\n .equiv _KERNEL_OPT_M68030,0x1\n .endif");
#endif
#define	M68040	1
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68040
 .global _KERNEL_OPT_M68040
 .equiv _KERNEL_OPT_M68040,0x1
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68040\n .global _KERNEL_OPT_M68040\n .equiv _KERNEL_OPT_M68040,0x1\n .endif");
#endif
/* option `M68060' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_M68060
 .global _KERNEL_OPT_M68060
 .equiv _KERNEL_OPT_M68060,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_M68060\n .global _KERNEL_OPT_M68060\n .equiv _KERNEL_OPT_M68060,0x6e074def\n .endif");
#endif
