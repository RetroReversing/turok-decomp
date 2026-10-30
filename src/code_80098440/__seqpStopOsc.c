#include "common.h"

typedef struct { u8 pad[0x80]; } Arg0; typedef struct { u8 pad00[0x8]; s32 value; u8 pad0C[0x14]; } Node; typedef struct { u8 pad00[0xC]; s16 type; u8 pad0E[2]; void *owner; void *callbackArg; s32 amount; u8 pad1C[0x20]; } Entry;
void __seqpStopOsc(Arg0 *arg0, u8 *arg1) {
 s16 type; Node *next; Entry *entry; 
 entry = *((Entry **)(((u8 *)arg0)+0x50));
 if(entry != 0) do {
  type=entry->type; next=*((Node **)entry);
  if(((type==0x16)||(type==0x17))&&(arg1==((u8*)entry->owner))) {
   ((s32 (*)(s32))(*((void **)(((u8*)arg0)+0x78))))(*((s32 *)(((u8*)entry)+0x14)));
   alUnlink(entry);
   if(next!=0) next->value += *((s32 *)(((u8*)entry)+8));
   alLink(entry,((u8*)arg0)+0x48);
   if(type==0x16) arg1[0x37]&=0xFE; else arg1[0x37]&=0xFD;
   if(arg1[0x37]==0) break;
  }
  entry=(Entry*)next;
 } while(next!=0);
}
