#include "common.h"

extern s32 osVirtualToPhysical(s32); extern void _bcopy(void*,void*,s32); extern s32 D_80138EF0[];
s32 *func_800A1350(void *arg0) {
 s32 *p = D_80138EF0;
 _bcopy(arg0, p, 0x40);
 if (p[4]) p[4] = osVirtualToPhysical(p[4]);
 if (p[6]) p[6] = osVirtualToPhysical(p[6]);
 if (p[8]) p[8] = osVirtualToPhysical(p[8]);
 if (p[10]) p[10] = osVirtualToPhysical(p[10]);
 if (p[11]) p[11] = osVirtualToPhysical(p[11]);
 if (p[12]) p[12] = osVirtualToPhysical(p[12]);
 if (p[14]) p[14] = osVirtualToPhysical(p[14]);
 return p;
}
