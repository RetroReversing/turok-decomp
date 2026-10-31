#include "common.h"

typedef struct { s32 pad,a,b; u8 pad2[0x59]; u8 value; } A940;
s32 __osContRamWrite(s32,s32,s32,u8*,s32);
s32 __osPfsSelectBank(A940 *p) {
 u8 buf[32];
 s32 i;
 s32 result=0;
 i=0;
 do { buf[i]=p->value; } while(++i<32);
 result=__osContRamWrite(p->a,p->b,0x400,buf,0);
 return result;
}
