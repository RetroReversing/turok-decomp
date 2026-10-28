#include "common.h"

extern s32 func_800A4F30(s32); extern void func_800AAB80(void*,void*,s32); extern s32 D_80138EF0[];
s32 *func_800A1350(void *arg0) {
 s32 *p = D_80138EF0;
 func_800AAB80(arg0, p, 0x40);
 if (p[4]) p[4] = func_800A4F30(p[4]);
 if (p[6]) p[6] = func_800A4F30(p[6]);
 if (p[8]) p[8] = func_800A4F30(p[8]);
 if (p[10]) p[10] = func_800A4F30(p[10]);
 if (p[11]) p[11] = func_800A4F30(p[11]);
 if (p[12]) p[12] = func_800A4F30(p[12]);
 if (p[14]) p[14] = func_800A4F30(p[14]);
 return p;
}
