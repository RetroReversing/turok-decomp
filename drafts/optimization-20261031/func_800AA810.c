#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  u32 v[12];
} Block;
extern u8 *D_800EF330;
extern u8 *D_800EF334;
extern volatile u32 D_A4400000;
extern volatile u32 D_A4400004;
extern int D_A4400008;
extern volatile u32 D_A440000c;
extern volatile u32 D_A4400010;
extern volatile u32 D_A4400014;
extern volatile u32 D_A4400018;
extern volatile u32 D_A440001c;
extern volatile u32 D_A4400020;
extern volatile u32 D_A4400024;
extern volatile u32 D_A4400028;
extern volatile u32 D_A440002c;
extern volatile u32 D_A4400030;
extern volatile u32 D_A4400034;
extern s32 osVirtualToPhysical(s32);
void func_800AA810(void)
{
  u8 *cur;
  s32 chan;
  s32 __repair_chan_1;
  u32 length;
  u32 rate;
  s32 address;
  s32 vol;
  u32 new_var;
  u32 i;
  chan = 0;
  cur = D_800EF334;
  cur = *((u8 **) (cur + 8));
  __repair_chan_1 = D_A4400010 & 1;
  address = (*((s32 *) ((cur + 0x28) + (__repair_chan_1 * 20)))) + osVirtualToPhysical(*((s32 *) (cur + 4)));
  new_var = *((u32 *) (cur + 16));
  if ((*((u16 *) cur)) & 2)
  {
    *((u32 *) (cur + 0x20)) = (*((u32 *) (cur + 0x20))) | ((*((u32 *) (cur + 0x20))) & (~0xfff));
  }
  else
  {
    *((u32 *) (cur + 0x20)) = *((u32 *) (cur + 0x20));
  }
  if ((*((u16 *) cur)) & 4)
  {
    rate = (*((u32 *) ((cur + 0x2c) + (__repair_chan_1 * 20)))) & 0xfff;
    *((u32 *) (cur + 0x2c)) = (u32) ((*((f32 *) (cur + 0x24))) * ((f32) rate));
    *((u32 *) (cur + 0x2c)) |= (*((u32 *) ((cur + 0x2c) + (__repair_chan_1 * 20)))) & (~0xfff);
  }
  else
  {
    *((u32 *) (cur + 0x2c)) = *((u32 *) ((cur + 0x2c) + (__repair_chan_1 * 20)));
  }
  length = *((u32 *) (cur + 0x1c));
  if ((*((u16 *) cur)) & 0x20)
  {
    length = 0;
  }
  if (((*((u16 *) cur)) & 0x40) != 0)
  {
    *((u32 *) (cur + 0x2c)) = 0;
    address = osVirtualToPhysical(*((s32 *) (cur + 4)));
  }
  if ((*((u16 *) cur)) & 0x80)
  {
    *((u32 *) (cur + 0x2c)) = ((*((u16 *) (cur + 0x28))) << 16) & 0x3ff0000;
    address = osVirtualToPhysical(*((s32 *) (cur + 4)));
  }
  D_A4400004 = address;
  D_A4400008 = *((u32 *) (cur + 8));
  D_A4400014 = *((u32 *) (cur + 12));
  D_A4400018 = new_var;
  D_A440001c = *((u32 *) (cur + 20));
  D_A4400020 = *((u32 *) (cur + 24));
  D_A4400024 = length;
  D_A4400028 = *((u32 *) ((cur + 0x30) + (__repair_chan_1 * 20)));
  D_A440002c = *((u32 *) ((cur + 0x34) + (__repair_chan_1 * 20)));
  D_A440000c = *((u32 *) ((cur + 0x38) + (__repair_chan_1 * 20)));
  D_A4400030 = *((u32 *) (cur + 0x20));
  D_A4400034 = *((u32 *) (cur + 0x2c));
  D_A4400000 = *((u32 *) (cur + 0xc));
  D_800EF334 = D_800EF330;
  D_800EF330 = cur;
  *((Block *) D_800EF334) = *((Block *) D_800EF330);
}

