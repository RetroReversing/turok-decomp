#include "common.h"

void func_8001302C(f32 *a,f32 *b,f32 x,f32 y,register f32 z)
{
a[0]=b[0]*x;
a[1]=b[1]*x;
a[2]=b[2]*x;
a[4]=b[4]*y;
a[5]=b[5]*y;
a[6]=b[6]*y;
a[8]=b[8]*z;
a[9]=b[9]*z;
a[10]=b[10]*z;
a[12]=b[12];
a[13]=b[13];
a[14]=b[14];
a[3]=a[7]=a[11]=0.0f; a[15]=1.0f;
}
