#include "common.h"

typedef struct {void *data;int autoDelete;} IS;
static __inline u32 Offset(IS *p,int n,u32 *len) {u32 *offsets=(u32*)((u8*)p->data+4);*len=offsets[n+1]-offsets[n];return offsets[n];}
u32 func_8002DC3C(IS *p,u32 base,int n,u32 *len){u32 offset;offset=Offset(p,n,len);return base+offset;}
