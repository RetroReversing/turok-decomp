#include "common.h"

void *func_800A5170(void);
s32 func_800A5068(void *, s32);
typedef struct { s32 x,y; s16 type,pad; s32 data,p,val; } O;
void func_800ACF50(void *a, void *b, s16 c, s32 d) {
    O *v;
    void *q;
    if (!*(void **)((char *)b+8)) return;
    v=func_800A5170();
    if (!v) return;
    v->y=*(s32*)((char*)*(void**)((char*)b+8)+0xd8)+*(s32*)((char*)a+0x1c);
    v->type=11;
    v->data=c;
    v->p=func_800A5068(a,d);
    v->x=0;
    q=*(void**)((char*)*(void**)((char*)b+8)+0xc);
    ((void(*)(void*,s32,O*))*(void**)((char*)q+8))(q,3,v);
}
