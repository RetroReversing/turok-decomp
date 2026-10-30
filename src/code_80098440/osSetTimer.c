#include "common.h"

typedef struct S8640 {void *next,*prev; u64 a,b; s32 c,d;} S8640;
extern S8640 **D_800EF2C0;
u64 __osInsertTimer(S8640*); void __osSetTimerIntr(u64);
s32 osSetTimer(S8640 * volatile p,u64 a,u64 b,s32 c,s32 d) {
u64 result;
p->next=0;p->prev=0;p->a=b;
if(a)p->b=a;else p->b=b;
p->c=c;p->d=d;
result=__osInsertTimer(p);
if(*D_800EF2C0==p)__osSetTimerIntr(result);
return 0;
}
