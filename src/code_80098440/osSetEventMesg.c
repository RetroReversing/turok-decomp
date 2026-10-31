#include "common.h"

extern s32 func_800A5750(void);
extern void func_800A5770(s32);
extern volatile s32 D_801369A0[];
typedef struct 
{
  s32 a;
  s32 b;
} Pair;
void osSetEventMesg(s32 arg0, s32 arg1, s32 arg2)
{
  register s32 temp;
  Pair *p;
  temp = func_800A5750();
  p = (Pair *) (((u8 *) D_801369A0) + (arg0 * 8));
  p->a = arg1;
 p->b = arg2; func_800A5770(temp);
}
