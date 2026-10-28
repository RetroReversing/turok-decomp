#include "common.h"

typedef unsigned short U16; typedef signed int S32;
extern void *func_800A5170(void);
void func_800ACFF0(void *a, void *b, f32 c)
{
  void *p;
  void *q;
  U16 code;
  if (*((void **) (((char *) b) + 8)))
  {
    p = func_800A5170();
    if (p)
    {
      code = 7;
      *((S32 *) (((char *) p) + 4)) = (*((S32 *) (((char *) (*((void **) (((char *) b) + 8)))) + 0xd8))) + (*((S32 *) (((char *) a) + 0x1c)));
      *((U16 *) (((char *) p) + 8)) = code;
      *((f32 *) (((char *) p) + 0xc)) = c;
      *((S32 *) ((char *) p)) = 0;
      q = *((void **) (((char *) (*((void **) (((char *) b) + 8)))) + 0xc));
      ((void (*)(void *, S32, void *, void *))(*((void **)((char *)q + 8))))(q, 3, p, b);
    }
  }
}
