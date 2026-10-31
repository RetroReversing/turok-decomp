#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
typedef struct 
{
  char pad[0x14];
  u32 base;
  char pad2[4];
  u32 count;
} Range;
extern u32 osVirtualToPhysical(u32);
Gfx *_loadBuffer(Range *r, u32 pos, s32 tile, s32 len, Gfx *g)
{
  u32 new_var;
  u32 end = r->base + (r->count * 2);
  u32 bytes = len * 2;
  u32 stop;
  u32 savedTile = tile;
  u32 savedPos = pos;
  Gfx *new_var3;
  u32 savedEnd = end;
  Gfx *cur = g;
  int new_var2;
  if (pos < r->base)
  {
    pos += r->count * 2;
  }
  stop = bytes & 0xFFFFFFFFFFFFFFFFu;
  stop = pos + (stop ^ 0);
  if (end < stop)
  {
    u32 first = (((s32) (end - pos)) >> 1) * 2;
    new_var = savedTile & 65535;
    cur->w0 = 0x08000000 | new_var;
    cur->w1 = first & 65535;
    cur++;
    new_var3 = cur;
    new_var3->w0 = 0x04000000;
    new_var3->w1 = osVirtualToPhysical(pos);
    new_var = first;
    new_var2 = 0x04000000;
    cur++;
    cur->w0 = 0x08000000 | ((new_var + savedTile) & 65535);
    cur->w1 = ((((s32) (stop - end)) >> 1) * 2) & 65535;
    cur++;
    cur->w0 = new_var2;
    cur->w1 = osVirtualToPhysical(r->base);
    cur++;
  }
  else
  {
    cur->w0 = 0x08000000 | (savedTile & 65535);
    cur->w1 = bytes & 65535;
    cur++;
    cur->w0 = 0x04000000;
    cur->w1 = osVirtualToPhysical(pos);
    cur++;
  }
  cur->w0 = 0x08000000;
  cur->w1 = bytes & 65535;
  return cur + 1;
}

