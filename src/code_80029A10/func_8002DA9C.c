#include "common.h"

typedef struct {void *data;s32 automatic;s32 allocated;} Set;
int func_80011DDC(void*);
void *func_80011FA0(s32);
static __inline void set_size(Set *p,u32 BlockSize)
{
 u32 *pdwData;
 pdwData=(u32*)p->data;
 pdwData[0]=BlockSize;
}
static __inline void set_count(Set *p,u32 BlockSize)
{
 u32 *pdwData;
 pdwData=(u32*)p->data;
 pdwData[1]=BlockSize;
}
void func_8002DA9C(Set *p,s32 blockSize,s32 blockCount)
{
 s32 newSize;
 if(p->data)func_80011DDC(p->data);
 newSize=8+blockSize*blockCount;
 p->data=func_80011FA0(newSize);
 set_size(p,blockSize);
 set_count(p,0);
 p->allocated=newSize;
}
