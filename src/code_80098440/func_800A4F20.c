#include "common.h"

extern s32 D_A450000C;
s32 func_800A4F20(void)
{
  return D_A450000C & 0xFFFFFFFFFFFFFFFFu;
}

s32 func_800AD5C0(u32);
s32 func_800A4F30(u32 arg0);
struct Node_800A4E90
{
  struct Node_800A4E90 *next;
  struct Node_800A4E90 *prev;
};
void func_800A4E90(struct Node_800A4E90 *arg0, struct Node_800A4E90 **arg1);
s32 func_800AD680(void);
extern u8 D_800EF270;
extern s32 D_A4500000;
extern s32 D_A4500004;
s32 func_800A4FB0(s32 arg0, s32 arg1);
