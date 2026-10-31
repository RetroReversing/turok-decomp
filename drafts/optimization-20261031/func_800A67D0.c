#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define W(p,o) (*(s32*)((u8*)(p)+(o)))
#define H(p,o) (*(u16*)((u8*)(p)+(o)))
extern s32 D_800EE4DC;
extern s32 D_800EE4E0;
extern u8 *D_8013A1D4;
extern volatile s32 D_A4600010;
extern volatile s32 D_A5000508;
extern volatile s32 D_A5000510;
extern void func_800A6EB4(void);
extern void __osLeoResume(void);
extern void func_800A7380(void *, s32, s32, s32, s32);
s32 func_800A67D0(void)
{
  u8 *p;
  u8 **new_var2;
  unsigned long new_var;
  u8 *q;
  u8 *base;
  u8 *tmp;
  volatile s32 status;
  s32 io;
  s32 ctrl;
  s32 i;
  if (!D_800EE4E0)
  {
    return 0;
  }
  base = D_8013A1D4;
  p = base + 0x14;
  q = (p + (H(base, 0x1A) * 0x24)) + 0x18;
  status = (status = D_A4600010);
  if (status & 1)
  {
    D_A4600010 = 3;
    status = D_A4600010;
    if (status & 2)
    {
      do
      {
        status = D_A4600010;
      }
      while (status & 2);
    }
    io = D_A5000508;
    if (io & 0x2000000)
    {
      status = D_A4600010;
      if (status & 2)
      {
        do
        {
          status = D_A4600010;
        }
        while (status & 2);
      }
      new_var2 = &p;
      D_A5000510 = W(*new_var2, 0x10) | 0x1000000;
    }
    W(q, 0) = 0x4B;
    func_800A6EB4();
    return 1;
  }
  if (status & 2)
  {
    do
    {
      status = D_A4600010;
    }
    while (status & 2);
  }
  new_var = 0x14;
  io = D_A5000508;
  if (io & 0x2000000)
  {
    status = D_A4600010;
    if (status & 2)
    {
      do
      {
        status = D_A4600010;
      }
      while (status & 2);
    }
    D_A5000510 = W(*new_var2, 0x10) | 0x1000000;
    W(q, 0) = 0;
    return 0;
  }
  if (io & 0x8000000)
  {
    W(q, 0) = 3;
    __osLeoResume();
    D_A4600010 = 2;
    D_800EE4DC |= 0x100401;
    return 1;
  }
  if (W(base + 0x14, 0) == 1)
  {
    if (!(io & 0x40000000))
    {
      if ((W(base + 0x14, 8) + 1) != (H(base + 0x14, 4) * 0x55))
      {
        W(q, 0) = 6;
        func_800A6EB4();
      }
      else
      {
        D_A4600010 = 2;
        D_800EE4DC |= 0x100401;
        W(q, 0) = 0;
        __osLeoResume();
      }
    }
    else
    {
u8 *__repair_cached_pointer = D_8013A1D4;

      W(q, 4) += W(q, 12);
      W(base + 0x14, 8)++;
      func_800A7380(__repair_cached_pointer, 1, 0x5000400, W(q, 4), W(q, 12));
    }
    return 1;
  }
  if (W(base + 0x14, 0) == 0)
  {
    if (H(base + 0x14, 4) == 3)
    {
      if ((W(q, 16) + 17) < W(base + 0x14, 8))
      {
        W(q, 0) = 0;
        func_800A6EB4();
        return 1;
      }
      if (!(io & 0x40000000))
      {
        W(q, 0) = 17;
        func_800A6EB4();
        return 1;
      }
    }
    else
    {
      W(q, 4) += W(q, 12);
    }
    ctrl = D_A5000510;
    if (((ctrl & 0x200000) && (ctrl & 0x400000)) || (ctrl & 0x2000000))
    {
      if (((u32) W(q, 16)) >= 4)
      {
        if ((H(base + 0x14, 4) != 3) || (W(base + 0x14, 8) >= 0x53))
        {
          W(q, 0) = 17;
          func_800A6EB4();
          return 1;
        }
      }
      else
      {
        i = W(q, 16);
        W(q, 0x14 + (i * 4)) = W(base + 0x14, 8) + 1;
      }
      W(q, 16)++;
    }
    if (io & 0x10000000)
    {
      if (W(base + 0x14, 8) != 0x57)
      {
        W(q, 0) = 6;
        func_800A6EB4();
      }
      if ((H(*new_var2, 4) == 2) && (H(*new_var2, 6) == 0))
      {
        H(*new_var2, 6) = 1;
        W(*new_var2, 8) = -1;
        W(*new_var2, 0x40) -= W(*new_var2, 0x48);
      }
      else
      {
        D_A4600010 = 2;
        D_800EE4DC |= 0x100401;
      }
      func_800A7380(D_8013A1D4, 0, 0x5000000, W(q, 8), W(q, 12) * 4);
      W(q, 0) = 0;
      return 1;
    }
    if (((W(base + 0x14, 8) == (-1)) && (H(base + 0x14, 4) == 2)) && (H(base + new_var, 6) == 1))
    {
      tmp = (*new_var2) + 0x18;
      if (W(base + 0x14, 0x28) == 0)
      {
        u8 *v = (u8 *) W(base + 0x14, 0x20);
        if (((W(v, 0) | W(v, 4)) | W(v, 8)) | W(v, 12))
        {
          W(q, 0) = 6;
          func_800A6EB4();
          return 1;
        }
      }
      W(q, 0) = 0;
      __osLeoResume();
    }
    W(base + 0x14, 8)++;
    if (io & 0x40000000)
    {
      if (W(base + 0x14, 8) >= 0x55)
      {
        W(q, 0) = 6;
        func_800A6EB4();
        return 1;
      }
      func_800A7380(D_8013A1D4, 0, 0x5000400, W(q, 4), W(q, 12));
      W(q, 0) = 0;
      return 1;
    }
    if (W(base + 0x14, 8) < 0x55)
    {
      W(q, 0) = 6;
      func_800A6EB4();
    }
    return 1;
  }
  W(q, 0) = 0x4B;
  func_800A6EB4();
  return 1;
}

