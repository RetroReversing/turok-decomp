#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct Thread {struct Thread *next;s32 priority;struct Thread **queue;struct Thread *tlnext;u16 state;} OSThread;
u32 func_800A5750(void);void func_800A5770(u32);void __osDequeueThread(OSThread**,OSThread*);void func_800A5F44(void);
extern OSThread *D_800EF28C,*D_800EF290;
void osDestroyThread(OSThread *t)
{
 register u32 saveMask;
 register OSThread *pred,*succ;
 saveMask=func_800A5750();
 if(t==(OSThread*)0) t=D_800EF290;
 else if(t->state!=1) __osDequeueThread(t->queue,t);
 if(D_800EF28C==t) D_800EF28C=D_800EF28C->tlnext;
 else {
  pred=D_800EF28C;
  succ=pred->tlnext;
  while(succ!=(OSThread*)0) {
   if(succ==t) {pred->tlnext=t->tlnext;break;}
   pred=succ;
   succ=pred->tlnext;
  }
 }
 if(t==D_800EF290) func_800A5F44();
 func_800A5770(saveMask);
}

