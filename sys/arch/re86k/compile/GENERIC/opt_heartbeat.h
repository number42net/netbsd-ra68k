/* option `HEARTBEAT' not defined */
#ifdef _LOCORE
 .ifndef _KERNEL_OPT_HEARTBEAT
 .global _KERNEL_OPT_HEARTBEAT
 .equiv _KERNEL_OPT_HEARTBEAT,0x6e074def
 .endif
#else
__asm(" .ifndef _KERNEL_OPT_HEARTBEAT\n .global _KERNEL_OPT_HEARTBEAT\n .equiv _KERNEL_OPT_HEARTBEAT,0x6e074def\n .endif");
#endif
