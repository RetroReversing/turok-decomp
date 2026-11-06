#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {void *data;s32 automatic;s32 allocated;} RawSet;
void i3D_free(void*);
static __inline void raw_attach(RawSet*p,void *data,s32 automatic)
{
 if(p->data && p->automatic) i3D_free(p->data);
 p->data=data;
 p->allocated=0;
 p->automatic=automatic;
}
static __inline void raw_size(RawSet*p,u32 size)
{
 u32 *words;
 words=p->data;
 words[0]=size;
}
static __inline void raw_count(RawSet*p,u32 count)
{
 u32 *words;
 words=p->data; words[1]=count;
}
void func_8002DA18(RawSet*p,void*data,s32 size,s32 count,s32 automatic)
{
 p->automatic=0;
 raw_attach(p,data,automatic);
 raw_size(p,size);
 raw_count(p,count);
}

