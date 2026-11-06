#include "common.h"

extern s32 __osDisableInt(void);
extern void __osRestoreInt(s32);
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
  temp = __osDisableInt();
  p = (Pair *) (((u8 *) D_801369A0) + (arg0 * 8));
  p->a = arg1;
 p->b = arg2; __osRestoreInt(temp);
}
