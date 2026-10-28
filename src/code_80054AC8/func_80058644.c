#include "common.h"

struct B{char p[0x140];s32 f[13];char q[0x2be-0x174];u8 id;}; s32 func_80058644(struct B*a){s32 v=-1;switch(a->id){case 0x64:return a->f[5];case 0x65:return a->f[6];case 0x66:if(a->f[3])return a->f[3];return a->f[7];case 0x67:return a->f[0];case 0x68:return a->f[2];case 0x69:if(a->f[4])return a->f[4];return a->f[1];case 0x6a:return a->f[8]*4;case 0x6b:return a->f[12];case 0x6c:return a->f[9];case 0x6d:return a->f[10]*4;case 0x6e:case 0x6f:case 0x70:case 0x71:case 0x72:return a->f[11];default:return v;}}
