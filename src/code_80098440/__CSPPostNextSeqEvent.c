#include "common.h"

extern s32 __alCSeqNextDelta(s32, s32 *); extern void alEvtqPostEvent(void *, s16 *, s32); void __CSPPostNextSeqEvent(void *p){struct {s32 n;s16 z;u8 pad[12];} local; if (*(s32*)((u8*)p+0x2c)==1){s32 v=*(s32*)((u8*)p+0x18); if(v && __alCSeqNextDelta(v,&local.n)){local.z=0;alEvtqPostEvent((u8*)p+0x48,&local.z,*(s32*)((u8*)p+0x24)*local.n);}}}
