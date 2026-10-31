#include "context_8d698fdff8b3.h"
#line 1 "func.c"
void *func_80011FA0(int); typedef struct { void *data; int count; int size; } S;
void func_8002DB18(S *arg0,s32 arg1,s32 arg2,s32 arg3) {
 volatile char padding[32]; s32 size;
 size=arg1*arg2+8;
 arg0->data=func_80011FA0(size);
 *(s32 *)arg0->data=arg1;
 *((s32 *)arg0->data+1)=arg2;
 arg0->size=size; arg0->count=arg3;
}
