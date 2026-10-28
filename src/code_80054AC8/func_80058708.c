#include "common.h"

struct A{char pad[0x178];s32 f[15];}; s32 func_80058708(struct A*a,s32 x){switch(x){case 0x64:return a->f[0];case 0x65:return a->f[1];case 0x66:return a->f[2];case 0x67:return a->f[3];case 0x68:return a->f[6];case 0x69:return a->f[7];case 0x6a:return a->f[4];case 0x6b:return a->f[5];case 0x6c:return a->f[8];case 0x6d:return a->f[9];case 0x6e:return a->f[10];case 0x6f:return a->f[11];case 0x70:return a->f[12];case 0x71:return a->f[13];case 0x72:return a->f[14];default:return 0;}}
