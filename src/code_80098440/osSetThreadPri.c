#include "common.h"

typedef struct 
{
  s32 pad0;
  s32 field4;
  s32 field8;
  s32 padC;
  u16 field10;
} Obj;
extern s32 func_800A5750(void);
extern void func_800A5770(s32);
extern void __osDequeueThread(s32, Obj *);
extern void func_800A5DEC(Obj **);
extern void __osEnqueueThread(s32, Obj *);
extern Obj *D_800EF288;
extern Obj *D_800EF290;
void osSetThreadPri(Obj *arg0, s32 arg1)
{
  volatile s32 pad[1];
  register s32 saved = func_800A5750();
 if (!arg0) { arg0 = D_800EF290;
  }
  if (arg0->field4 != arg1)
  {
    arg0->field4 = arg1;
    if ((arg0 != D_800EF290) && (arg0->field10 != 1))
    {
      __osDequeueThread(arg0->field8, arg0);
      __osEnqueueThread(arg0->field8, arg0);
    }
    if (D_800EF290->field4 < D_800EF288->field4)
    {
      D_800EF290->field10 = 2;
      func_800A5DEC(&D_800EF288);
    }
  }
  func_800A5770(saved);
  (void) pad;
}
