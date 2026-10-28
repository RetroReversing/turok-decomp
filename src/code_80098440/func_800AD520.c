#include "common.h"

extern void *func_800A5170(void);
void func_800AD520(void *a, void *b, s32 c)
{
  void *p;
  void *q;
  u16 code;
  if (!(*((void **) (((char *) b) + 8)))) return;
  p = func_800A5170();
  if (p)
  {
    code = 14;
    *((s32 *) (((char *) p) + 4)) = (*((s32 *) (((char *) (*((void **) (((char *) b) + 8)))) + 0xd8))) + (*((s32 *) (((char *) a) + 0x1c)));
    *((u16 *) (((char *) p) + 8)) = code;
    *((s32 *) (((char *) p) + 0xc)) = c;
    *((s32 *) p) = 0;
    *((s16 *) (0xa + ((char *) p))) = *((s16 *) (((char *) b) + 0x1a));
    q = *((void **) (((char *) (*((void **) (((char *) b) + 8)))) + 0xc));
    ((void (*)(void *, s32, void *, void *)) (*((void **) (((char *) q) + 8))))(q, 3, p, b);
  }
}
