#include "common.h"

s32 __osProbeTLB(u32); s32 osVirtualToPhysical(volatile u32 arg0) { u32 x = ((arg0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF; if (x >= 0x80000000U && x < 0xA0000000U) return x & 0x1FFFFFFF; x = ((arg0 & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF) & 0xFFFFFFFFFFFFFFFF; if (x >= 0xA0000000U && x < 0xC0000000U) return x & 0x1FFFFFFF; return __osProbeTLB(arg0); }
