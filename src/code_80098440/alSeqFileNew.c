#include "common.h"

typedef struct { s16 pad; s16 count; s32 value; } A2368;
void alSeqFileNew(A2368 *p,s32 add) { s32 i=0; A2368 *q=p; if(p->count>0){ do { q->value += add; i++; q++; } while(i<p->count); } }
