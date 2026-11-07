#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
extern s32 CCacheEntry__GetData(s32); extern void CUnindexedSet__ConstructFromRawData(void*,s32,s32); extern void CCartCache__RequestBlock(void*,s32,s32,s32,void*,s32,s32,void*); extern u8 D_800F1A78[];
void CScene__BinaryTypesReceived(void *pThis,s32 ppceTarget){u8 temp[12];s32 x; s32 n; void *p=pThis; x=CCacheEntry__GetData(*(s32*)((u8*)pThis+0x6B34));CUnindexedSet__ConstructFromRawData(temp,x,0);n=*(s32*)(*(u32*)temp+4);CCartCache__RequestBlock(p,0,0,0,(u8*)p+0x6B30,*(s32*)((u8*)p+0x6AE4),((n*4+15)&~7),D_800F1A78);}
