#include "common.h"

typedef struct 
{
  u8 pad[0x3C];
  s32 index;
  void *items;
} A3;
typedef struct 
{
  s16 type;
  u16 pad;
  void *entry;
  u8 extra[4];
} Cmd3;
extern void func_800ACBAC(void *, Cmd3 *, s32);
void func_800A3F60(A3 *a)
{
  s32 *new_var2;
  Cmd3 cmd;
  void *base = a->items;
  s32 *new_var;
  new_var2 = &a->index;
  new_var = &a->index;
  if ((*((s32 *) ((((u8 *) base) + ((*new_var2) * 0x30)) + 0x28))) == 0)
  {
    cmd.type = 0;
    new_var = &a->index;
    cmd.entry = ((u8 *) base) + ((*new_var) * 0x30);
    func_800ACBAC(((u8 *) a) + (0x14 & 0xFFFFFFFFFFFFFFFFu), &cmd, 0);
  }
}
