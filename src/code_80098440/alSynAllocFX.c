#include "common.h"
#line 1 "func.c"
typedef struct {u8 prefix[0x20];u8 fx[0x2c];} LiveAuxBus;
typedef struct {u8 prefix[0x30];void *mainBus;LiveAuxBus *auxBus;} LiveSynth;
void alFxNew(void*,void*,void*);
void func_800B1E94(void*,s32,void*);
void func_800ADEF0(void*,s32,void*);
void *alSynAllocFX(LiveSynth *s,s16 bus,void *c,void *hp)
{
 alFxNew(&s->auxBus[bus].fx[0],c,hp);
 func_800B1E94(&s->auxBus[bus].fx[0],1,&s->auxBus[bus]);
 func_800ADEF0(s->mainBus,2,&s->auxBus[bus].fx[0]);
 return &s->auxBus[bus].fx[0];
}

