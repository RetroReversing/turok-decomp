#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern void osRecvMesg(void *, void **, int);
extern void osSendMesg(void *, void *, int);
extern void __osResetGlobalIntMask(int);
extern void func_800AFF50(void *, int, void *);
extern void osYieldThread(void);
void func_800A7460(void ** volatile ctx)
{
  int new_var4;
  void * volatile cmd = 0;
  void *tmp = 0;
  void *new_var2;
  void *a = 0;
  void *b = 0;
  volatile int flag = 0;
  volatile int result = 0;
  int new_var;
  void **new_var3;
  unsigned char *p;
  unsigned char *q;
  for (;;)
  {
    osRecvMesg(ctx[2], &cmd, 1);
    p = (unsigned char *) cmd;
    q = *((unsigned char **) (p + 0x14));
    new_var4 = *((int *) (q + 0x14));
    if ((q && (q[4] == 2)) && (new_var4 <= 1))
    {
      unsigned char *h = q + 0x14;
      unsigned char *item = (h + 0x18) + (36 * (*((unsigned short *) (h + 6))));
      *((int *) (h + 8)) = -1;
      if ((*((unsigned short *) (h - -4))) != 3)
      {
        *((int *) (item + 4)) -= *((int *) (item + 12));
      }
      flag = ((*((unsigned short *) (h + 4))) == 2) && (new_var4 == 0);
      osRecvMesg(ctx[4], &a, 1);
      __osResetGlobalIntMask(0x100401);
      func_800AFF50(q, (int) 0x5000510, (void *) ((*((int *) (h + 0x10))) | 0x80000000));
      do
      {
        osRecvMesg(ctx[3], &b, 1);
        osSendMesg(*(new_var3 = &(*((void **) (p + 4)))), cmd, 0);
        if (flag && ((*((int *) (q + 0x2c))) == 0))
        {
          flag = 0;
          continue;
        }
        break;
      }
      while (1);
      osSendMesg(ctx[4], 0, 0);
      if ((*((unsigned short *) (q + 0x1a))) == 1)
      {
        osYieldThread();
      }
    }
    else
    {
      new_var = (*((unsigned short *) p)) - 10;
      switch (*((unsigned short *) p))
      {
        case 10:

        case 11:
          osRecvMesg(ctx[4], &a, 1);
          result = ((int (*)(int, int, int, int)) ctx[5])(new_var, *((int *) (p + 12)), *((int *) (p + 8)), *((int *) (p + 16)));
          break;

        case 12:

        case 13:

        case 16:
          osRecvMesg(ctx[4], &a, 1);
          result = ((int (*)(int, int, int, int, int)) ctx[6])(((*((unsigned short *) p)) ^ 0) - 12, *((int *) (p + 20)), *((int *) (p + 12)), *((int *) (p + 8)), *((int *) (p + 16)));
          break;

        case 14:
          osSendMesg(*new_var3, cmd, 0);
          result = -1;
          break;

        default:
          result = -1;

      }

      if (result == 0)
      {
        osRecvMesg(ctx[3], &b, 1);
        new_var2 = ctx[4];
        osSendMesg(*new_var3, cmd, 0);
        osSendMesg(new_var2, 0, 0);
      }
    }
  }

}

