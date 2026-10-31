#include "common.h"

typedef struct {u8 filter[0x14];void *state;f32 ratio;s32 motion;f32 delta;s32 first;void *ctrlList,*ctrlTail;s32 upitch;} Resampler;
void func_800B1580(void*,void*,void*,s32);
void *alHeapDBAlloc(void*,s32,void*,s32,s32);
extern s32 alResamplePull,alResampleParam;
void alResampleNew(Resampler *r,void *hp)
{
 func_800B1580(r,&alResamplePull,&alResampleParam,1);
 r->state=alHeapDBAlloc(0,0,hp,1,32);
 r->delta=0.0;
 r->first=1;
 r->upitch=0;
 r->ratio=1.0;
 r->motion=0;
 r->ctrlList=0;
 r->ctrlTail=0;
}
