#include "common.h"

typedef struct {s32 pad[5];s32 count;s32 pad2; s32 *items;} SolQueue;
s32 func_800ADEF0(SolQueue *a,s32 b,s32 c){s32 *p=a->items;if(b==2){p[a->count]=c;a->count++;}return 0;}
