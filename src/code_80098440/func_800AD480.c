#include "common.h"

extern void *func_800A5170(void);
void func_800AD480(void *a, void *b, s32 x) {
 void *v; s32 value;
 if (*(void**)((u8*)b+8)==0) return;
 v=func_800A5170();
 if (!v) return;
 *(s32*)((u8*)v+4)=*(s32*)((u8*)*(void**)((u8*)b+8)+0xd8)+*(s32*)((u8*)a+0x1c);
 *(s16*)((u8*)v+8)=16;
 value=*(u8*)((u8*)&x+3);
 if(value<0) *(s32*)((u8*)v+0xc)=-value;
 else *(s32*)((u8*)v+0xc)=value;
 *(s32*)v=0;
 ((void (*)(void*,s32,void*,void*))(*(void**)((u8*)*(void**)((u8*)*(void**)((u8*)b+8)+0xc)+8)))(*(void**)((u8*)*(void**)((u8*)b+8)+0xc),3,v,b);
}
