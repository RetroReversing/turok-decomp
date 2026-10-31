#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct 
{
  f32 x;
  f32 y;
  f32 z;
} V3;
extern void func_8005F228(void *, void *);
extern void func_80060A54(void *, s32);
extern void func_800619EC(void *, void *, V3, f32);
void func_8006905C(void *a, void *b, V3 pos, f32 f)
{
  void *v;
  long long x;
  s32 new_var;
  v = b;
  new_var = (*((u8 *) b)) != 1;
  if (new_var)
  {
    if ((*((u8 *) b)) != 2)
    {
      v = 0;
    }
    else
    {
      {
        void *p = *((void **) (((char *) b) + 0xB8));
        if ((*((u8 *) p)) == 1)
        {
          v = p;
        }
        else
        {
          v = 0;
        }
      }
    }
  }
  if ((*((u8 *) a)) == 1)
  {
    if ((v == 0) || (((*((u8 *) a)) == 1) && ((*((u16 *) (((char *) a) + 2))) != (*((u16 *) (((char *) v) + (new_var = 2)))))))
    {
      new_var = (s32) f;
      x = new_var;
      func_80060A54(a, x);
      if (v)
      {
      }
    }
    func_8005F228(a, b);
    func_800619EC(a, b, pos, 15.0f);
  }
}

