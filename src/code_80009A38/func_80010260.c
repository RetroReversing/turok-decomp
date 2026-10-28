#include "common.h"

extern s32 func_80011224(void);
extern volatile unsigned int func_800113A8(s32);
extern u8 D_800B86D4;
extern s32 D_80119734;
extern s32 D_80119970;
typedef struct 
{
  s32 ptr;
  u8 rest[24];
} Rec;
extern Rec D_80119AE0[];
void func_80010260(void *a)
{
  s32 r;
  func_80011224();
  r = func_80011224();
  if (D_800B86D4 && (r == 0))
  {
    *((s32 *) (((u8 *) a) + 0xC)) = 0;
    *((s32 *) (((u8 *) a) + 0x10)) = 0;
    *((s16 *) (((u8 *) a) + 4)) = 1;
    *((s32 *) (((u8 *) a) + 8)) = 1;
    *((f32 *) a) = 0.0f;
    D_80119734 = 1;
    func_800113A8(1);
    if (D_80119AE0[*((s32 *) (((u8 *) a) + 0xC))].ptr == 0)
    {
      D_80119970 = 0;
    }
    else
    {
      D_80119970 = 1;
    }
  }
  else
  {
    *((s32 *) (((u8 *) a) + 8)) = 0;
  }
}
