#include "common.h"

void func_80013190(f32 *a,f32 x, f32 y,f32 z ) {
 a[12]+=x*a[0]+y*a[4]+z*a[8];
 a[13]+=x*a[1]+y*a[5]+z*a[9];
 a[14]+=x*a[2]+y*a[6]+z*a[10];}
