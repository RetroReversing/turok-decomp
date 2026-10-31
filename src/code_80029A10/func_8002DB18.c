#include "common.h"
#line 1 "func.c"
typedef struct {void *data;s32 automatic;s32 allocated;} LocalSet;
void *func_80011FA0(s32);
static __inline void local_set_size(LocalSet *p,u32 BlockSize)
{
 u32 *pdwData;
 pdwData=(u32*)p->data;
 pdwData[0]=BlockSize;
}
static __inline void local_set_count(LocalSet *p,u32 BlockSize)
{
 u32 *pdwData;
 pdwData=(u32*)p->data;
 pdwData[1]=BlockSize;
}
void func_8002DB18(LocalSet *p,s32 blockSize,s32 blockCount,s32 autoDelete)
{
 s32 newSize;
 newSize=8+blockSize*blockCount;
 p->data=func_80011FA0(newSize);
 local_set_size(p,blockSize);
 local_set_count(p,blockCount);
 p->allocated=newSize;
 p->automatic=autoDelete;
}

