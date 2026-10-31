#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {s32 status;void *queue;s32 channel;u8 id[32];u8 rest[57];u8 activebank;} LocalPfs;
s32 __osPfsSelectBank(LocalPfs*);s32 __osContRamRead(void*,s32,s32,u8*);
s32 __osCheckId(LocalPfs *pfs)
{
 int i;
 u8 temp[32];
 s32 ret;
 if(pfs->activebank != 0) {
  pfs->activebank=0;
  ret=__osPfsSelectBank(pfs);
  if(ret) return ret;
 }
 ret=__osContRamRead(pfs->queue,pfs->channel,1,temp);
 if(ret) {
  if(ret != 2) return ret;
  ret=__osContRamRead(pfs->queue,pfs->channel,1,temp);
  if(ret) return ret;
 }
 for(i=0;i<32;i++) {
  if(pfs->id[i] != temp[i]) return 2;
 }
 return 0;
}

