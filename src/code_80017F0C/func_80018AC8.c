#include "common.h"

extern void func_800188C8(f32 *, s32, f32 *); void func_80018AC8(f32 *a, s32 n, f32 *p) { if (n) { f32 x=*p; n--; p+=3; a[2]=x; a[0]=x; x=p[-1]; a[3]=x; a[1]=x; func_800188C8(a,n,p); } }
