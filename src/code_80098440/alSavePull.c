#include "common.h"

typedef struct {s32 unused; s32 (*alloc_commands)(void *, s32, s32, s32, s32);} DisplayVtable;
typedef struct {DisplayVtable *vptr; s32 unused[4]; s32 final_word;} DisplayOwner;
s32 alSavePull(DisplayOwner *owner, s32 arg1, s32 count, s32 arg3, s32 arg4)
{
  s32 *commands;
  commands = (s32 *) owner->vptr->alloc_commands(owner->vptr, arg1, count, arg3, arg4);
  commands[1] = (count << 1) & 0xffff;
  commands[0] = 0x08000000;
  commands[2] = 0x0D000000; commands[3] = 0x04400580;
  commands[5] = (count << 2) & 0xffff;
  commands[4] = 0x08000000;
  commands[6] = 0x06000000;
  commands[7] = owner->final_word;
  return (s32) (commands + 8);
}
