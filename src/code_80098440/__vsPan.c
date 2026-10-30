#include "common.h"

typedef struct{u8 pad[0x20];u8*unk20;u8 pad2[0x0D];u8 id31;}A724;typedef struct{u8 pad[0x60];u8*unk60;}B724;typedef struct Entry{struct Entry*next;u8 p[0x30];u8 id31,id32,id33,p34,state35;}Entry;typedef struct{u8 p[0x64];Entry*head,*tail,*free;}List;typedef struct{u8 p[0x14];f32 scale;}Scale;typedef struct{u8 p[0x18];Scale*scale;u8 gap[8];s32 val;}Out;
s32 __vsPan(A724*a,B724*b){s32 v;v=a->unk20[12]+((u8*)b->unk60+(a->id31<<4))[7]-0x40;if(v<=0)v=0;if(v>=0x7f)v=0x7f;return v&255;}
Entry*__lookupVoice(List*a,s32 x,s32 y);                                                                                                                                                        
void func_800AB6AC(u8*a,Out*b);                                                                                                                                         
Entry*__mapVoice(List*a,s32 x,s32 y,s32 z);
