#include "common.h"

typedef struct {void *data;int autoDelete,size;} Set;
static __inline u32 GetSize(Set *p){return 8+((u32*)p->data)[0]*((u32*)p->data)[1];}
void* func_8002D950(Set *p,u32 *size){*size=GetSize(p)-8;return (u8*)p->data+8;}
