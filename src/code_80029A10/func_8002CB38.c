#include "common.h"

void func_80011DDC(s32);
void func_8002E1C0(void *);
typedef struct { char pad0[0x18]; void *head; s32 x1C; void *list; s32 x24; char pad28[0x682C - 0x28]; void *pool; char pad6830[0x6AB0 - 0x6830]; void *free; } Big;
typedef struct N { struct N *next; char pad4[0x1C]; struct N *link2; char pad24[8]; struct N *link3; } N;
void func_8002CB38(Big *a)
{
  N *new_var3;
  char *new_var2;
  N *new_var;
  N *n = (N *) a->list;
  N *t;
  while (n)
  {
    t = n;
    new_var3 = t;
    n = n->link3;
    if (*((s32 *) new_var3))
    {
      func_80011DDC(*((s32 *) new_var3));
    }
    *((s32 *) (((char *) new_var3) + 0x20)) = 0x15D0B;
    new_var2 = ((char *) new_var3) + 0x30;
    *((void **) new_var2) = a->pool;
    a->pool = new_var3;
  }

  t = (N *) a->head;
  a->x24 = 0;
  a->list = 0;
  while (t)
  {
    n = t;
    new_var = n;
    t = t->link2;
    *((void **) (((char *) new_var) + 0x24)) = a->free;
    a->free = new_var;
  }

  a->x1C = 0;
  a->head = 0;
  func_8002E1C0(a);
}
