#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  int pad[5];
  int count;
  int pad18;
  void **items;
} S_func_800AFB20_arg0;
void *alAuxBusPull(S_func_800AFB20_arg0 *arg0, void *arg1, s32 arg2, void *arg3, s32 *arg4)
{
  void **start = arg0->items;
  void **items;
  s32 i = 0;
  void *out;
  s32 twice;
  twice = arg2 << 1;
  arg4[0] = 0x020006C0;
  arg4[1] = twice;
  arg4[2] = 0x02000800;
  arg4[3] = twice;
  out = arg4 + 4;
  items = start;
  if (arg0->count > ((i < arg0->count) * 0))
  {
    do
    {
      void *item = *items;
      out = ((void *(*)(void *, void *, s32, void *, void *)) (*((void **) (((u8 *) item) + 4))))(item, arg1, arg2, arg3, out);
      items++;
      i++;
    }
    while (i < arg0->count);
  }
  return out;
}

