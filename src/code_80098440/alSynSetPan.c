#include "common.h"

void *__allocParam(void);
typedef struct 
{
  s32 p[7];
  s32 off1c;
} A;
typedef struct 
{
  s32 p[2];
  void *obj;
} B;
typedef struct 
{
  s32 x;
  s32 y;
  s16 type;
  s16 pad;
  s32 data;
  s32 p;
  s32 val;
} O;
void alSynSetPan(A *a, B *b, u8 c)
{
  O *v;
  void *q;
  if (b->obj == 0)
  {
    return;
  }
  v = __allocParam();
  if (v)
  {
  }
  if (v == 0)
  {
    return;
  }
  v->y = (*((s32 *) (((char *) b->obj) + 0xd8))) + (*((volatile s32 *) (&a->off1c)));
  v->type = 12;
  v->x = 0;
  v->data = c;
  v->x = 0;
  q = *((void **) (((char *) b->obj) + 0xc));
  if (q)
  {
  }
  ((void (*)(void *, s32, O *, B *)) (*((void **) (((char *) q) + 8))))(q, 3, v, b);
}
