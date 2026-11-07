#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
typedef struct {u32 *data; s32 flag;} Set;
typedef struct {u8 pad[0x6abc]; void *address; u8 pad2[0x30]; void *cache; void *target;} Obj;
extern void *CCacheEntry__GetData(void *);
extern void CIndexedSet__ConstructFromRawData(Set*,void*,s32);
extern void func_8003433C();
extern void CCartCache__RequestBlock(void*,void*,void*,void (*)(),void*,void*,u32,void*);
extern u8 D_800F1ADC[];
void CScene__ObjectsHeaderReceived(Obj *pThis,void *ppceTarget) {
 Set out;
 register u32 n;
 CIndexedSet__ConstructFromRawData(&out,CCacheEntry__GetData(pThis->cache),0);
 n=out.data[0];
 CCartCache__RequestBlock(pThis,pThis,0,func_8003433C,&pThis->target,pThis->address,(n*4+15)&~7U,D_800F1ADC);
}
