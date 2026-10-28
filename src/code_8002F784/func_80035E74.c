#include "common.h"

typedef struct { u8 p0[0x180]; f32 value; u8 p1[0x10]; void *next; } Node;
extern void func_8002007C(void *, void *, s32, void *);
extern s32 D_800B9878;
extern struct { u8 pad[0xC]; f32 value; } D_800B987C;
extern f64 D_800F1D68;
void func_80035E74(void *arg0, void *arg1, void *arg2)
{
  u8 *root = (u8 *) arg0;
  Node *n = *((Node **) (root + 0x3304));
  f64 scale;
  int new_var;
  new_var = 0;
  if (n)
  {
    D_800B9878 = new_var;
    scale = D_800F1D68;
    do
    {
      f32 v = (new_var, n->value);
      if ((v > 0.0f) && (((f64) v) <= 7.5))
      {
        D_800B9878 = 1;
        D_800B987C.value = (f32) ((((f64) n->value) * scale) / 7.5);
      }
      func_8002007C(n, arg1, *((s32 *) (root + 0x330C)), arg2);
      D_800B9878 = 0;
      n = n->next;
    }
    while (n);
  }
}
