#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  u32 w0;
  u32 w1;
} Gfx;
typedef struct Node Node;
struct Node
{
  void *pad;
  Gfx *(*draw)(Node *, void *, s32, void *, Gfx *);
};
typedef struct 
{
  char pad[0x14];
  s32 count;
  char pad2[4];
  Node **nodes;
} Group;
Gfx *alMainBusPull(Group *group, void *arg1, s32 arg2, void *arg3, Gfx *arg4)
{
  s32 i;
  Node **node;
  Gfx *p;
  Node **first = group->nodes;
  Group *new_var;
  u32 width = arg2 << 1;
  new_var = group;
  arg4[width * 0].w0 = 0x02000440;
  arg4[0].w1 = width;
  arg4[1].w0 = 0x02000580;
  arg4[1].w1 = width;
  i = 0;
  p = arg4 + 2;
  if (group->count > 0)
  {
    node = first;
    do
    {
      Node *entry = *node;
      Gfx *q = entry->draw(entry, arg1, arg2, arg3, p);
      q[0].w0 = 0x08000000;
      q[0].w1 = width & 0xffff;
      q[1].w1 = 0x06c00440;
      q[1].w0 = 0x0c007fff;
      q[2].w1 = 0x08000580;
      q[2].w0 = 0x0c007fff;
      i++;
      node++;
      p = q + 3;
    }
    while (i < new_var->count);
  }
  return p;
}

