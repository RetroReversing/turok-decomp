#include "context_8d698fdff8b3.h"
#line 1 "func.c"
#define P(b,o) (*(char **)((char *)(b)+(o)))
#define I(b,o) (*(int *)((char *)(b)+(o)))
#define F(b,o) (*(float *)((char *)(b)+(o)))
#define H(b,o) (*(unsigned short *)((char *)(b)+(o)))
extern void func_80013588(float *);
extern float func_80013620(float, float);
extern float func_80019D3C(void *, void *, void *);
extern int func_80019ED8(void *);
extern int func_8001E21C(void *, int, int);
extern void *func_8001E2F8(void *, int, int, int);
extern float func_800206E4(void *, int);
extern float func_80021348(void *, int, int);
extern double D_800F6BB0;
extern double D_800F6BB8;
extern double D_800F6BC0;
extern double D_800F6BC8;
void *func_80099208(char *a0, char *a1, int n, char *a3)
{
  char *sp80 = P(a0, 0);
  char **new_var;
  char *t1 = *((char **) ((a1 + (n * 4)) + 0x10));
  int flags;
  int x;
  int y;
  int new_var2;
  unsigned short new_var3;
  int q;
  int j;
  int found = 0;
  float v;
  float w;
  if (!t1)
  {
    return 0;
  }
  if (H(a1, 2) & 0x20)
  {
    char *p = t1;
    for (j = 0; j < 3; j++)
    {
      if (P(p, 0x10) == a1)
      {
        found = 1;
        break;
      }
      p += 4;
    }

    new_var = &a3;
    if (!found)
    {
      if (!func_8001E21C(t1, I(*new_var, 0), I(*new_var, 8)))
      {
        volatile float xyz[3];
        xyz[0] = F(*new_var, 0);
        xyz[1] = F(sp80, 8);
        xyz[2] = F(*new_var, 8);
        t1 = func_8001E2F8(a1, *((int *) (&xyz[0])), *((int *) (&xyz[1])), *((int *) (&xyz[2])));
        if (!t1)
        {
          return 0;
        }
      }
    }
  }
  flags = I(P(a0, 4), 0);
  if ((flags & 0x40000) && (((((int) H(t1, 2)) << 15) < 0) || (((((int) H(t1, 2)) << 12) << 2) < 0)))
  {
    return 0;
  }
  if ((H(t1, 2) & 0x1000) && (!(flags & 0x10000)))
  {
    return 0;
  }
  if (((!((flags << 7) < 0)) && (!(H(t1, 2) & 1))) && (H(a1, 2) & 1))
  {
    return 0;
  }
  if (((!((flags << 8) < 0)) && (H(t1, 2) & 1)) && (!(H(a1, 2) & 1)))
  {
    return 0;
  }
  if ((H(t1, 2) & 0x80) && (!(flags & 0x8000)))
  {
    return 0;
  }
  if (((!(flags & 0x400)) && (H(t1, 2) & 2)) && (!(H(t1, 2) & 4)))
  {
    return 0;
  }
  if ((H(t1, 2) & 0x40) && (!(H(a1, 2) & 0x40)))
  {
    if (func_80021348(t1, I(*new_var, 0), I(*new_var, 8)) < F(*new_var, 4))
    {
      return 0;
    }
  }
  new_var2 = func_80019ED8(t1);
  x = func_80019ED8(a1);
  y = new_var2;
  new_var2 = I(P(a0, 4), 0);
  if (new_var2 & 0x2000)
  {
    if (y)
    {
      return t1;
    }
    return 0;
  }
  if (((((new_var2 & 0x1000) && x) && y) && (H(a1, 2) & 0x10)) && (!(H(t1, 2) & 0x10)))
  {
    if (((double) F(sp80, 8)) < (((double) func_80019D3C(a1, P(sp80, 4), P(sp80, 12))) + D_800F6BB0))
    {
      return 0;
    }
  }
  if (y && (!x))
  {
    new_var2 = I(P(a0, 4), 0);
    q = new_var2 & 0x200000;
    j = new_var2 & 0x400000;
    if ((H(t1, 2) & 0x10) && (new_var2 & 0x1000))
    {
      v = (float) (((double) func_800206E4(a1, n)) + D_800F6BB8);
      func_80013588(&v);
      w = func_80013620(v, F(sp80, 0x64));
      if (((double) ((w < 0) ? (-w) : (w))) <= D_800F6BC0)
      {
        q = 1;
      }
    }
    if (q && j)
    {
      return t1;
    }
    v = func_80019D3C(a1, P(sp80, 4), P(sp80, 12));
    new_var3 = j;
    if (v < func_80019D3C(t1, P(a0, 0x4c), P(a0, 0x54)))
    {
      if (q)
      {
        return t1;
      }
      w = (float) (((double) F(sp80, 8)) + D_800F6BC8);
      if (((F(P(t1, 4), 4) < w) && (F(P(t1, 8), 4) < w)) && (F(P(t1, 12), 4) < w))
      {
        return t1;
      }
      return 0;
    }
    return (new_var3) ? (t1) : (0);
  }
  return t1;
}

