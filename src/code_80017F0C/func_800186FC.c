#include "common.h"

extern s32 func_8002D1F8(void*,s32,s32,s32,void*,s32,s32,void*);
extern s32 CCacheEntry__GetData(s32);
extern void CIndexedSet__ConstructFromRawData(s32*,s32,s32);
extern s32 CIndexedSet__GetBlock(s32*,s32,s32);
extern void func_8002DA8C(void**,s32,s32);
extern s32 func_80083BF4(void*,s32,s32);
extern s32 D_800FA3C8, D_800F0DD8;
s32 func_800186FC(void *p,s32 arg1){
 s32 v=*(s32*)((char*)p+0x100); s32 sp50; void *sp44[3]; s32 x; volatile s32 pad[4];
 if(v==0)return -1;
 *(s32*)((char*)p+0x10c)=0;
 func_8002D1F8(&D_800FA3C8,0,0,0,(char*)p+0x10c,v,*(u16*)((char*)p+0x118),&D_800F0DD8);
 if(*(s32*)((char*)p+0x10c)==0)return -1;
 x=CCacheEntry__GetData(*(s32*)((char*)p+0x10c));
 CIndexedSet__ConstructFromRawData(&sp50,x,0);
 x=CIndexedSet__GetBlock(&sp50,sp50,1);
 func_8002DA8C(sp44,x,0);
 x=*(s32*)((char*)sp44[0]+4);
 return func_80083BF4((char*)sp44[0]+8,x,arg1);
}
