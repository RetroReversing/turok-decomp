#include "common.h"

typedef struct {u32 *data; s32 flag;} Set;
typedef struct {u8 pad[0x6ac4]; void *address; u8 pad2[0x40]; void *cache; void *target;} Obj;
extern void *CCacheEntry__GetData(void *);
extern void CIndexedSet__ConstructFromRawData(Set*,void*,s32);
extern void func_8003417C();
extern void func_8002D1F8(void*,void*,void*,void (*)(),void*,void*,u32,void*);
extern u8 D_800F1B24[];
void func_800341A8(Obj *a,void *b) {
 Set out;
 register u32 n;
 CIndexedSet__ConstructFromRawData(&out,CCacheEntry__GetData(a->cache),0);
 n=out.data[0];
 func_8002D1F8(a,a,0,func_8003417C,&a->target,a->address,(n*4+15)&~7U,D_800F1B24);
}
