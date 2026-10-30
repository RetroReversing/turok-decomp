#include "common.h"

typedef struct 
{
  u32 index;
  u32 id;
  u8 b[8];
  u16 w0;
  u16 w1;
} Src;
typedef struct 
{
  u32 id;
  u8 pad4[4];
  u32 x;
  u8 padC[4];
  u8 b[8];
  u16 w0;
  u16 w1;
} Dst;
typedef struct 
{
  u8 pad[8];
  s32 id;
} A2;
extern s32 CCacheEntry__GetData(void *);
extern void CIndexedSet__ConstructFromRawData(void *, s32, s32);
extern s32 func_8002DBF8(void *, s32, s32, s32 *);
extern void func_80026DA4(void *, s32, s32);
void func_8001E550(Dst *o, Src *s, A2 *a)
{
  u8 *new_var2;
  s32 tmp;
  s32 val;
  s32 size;
  u8 *new_var;
  o->id = s->id;
  o->b[0] = s->b[0];
  o->b[1] = s->b[1];
  new_var2 = s->b;
  o->b[2] = new_var2[2];
  o->b[3] = s->b[3];
  o->b[4] = s->b[4];
  new_var = s->b;
  o->b[5] = new_var[5];
  o->b[6] = new_var[6];
  o->b[7] = new_var[7];
  o->w0 = s->w0;
  o->w1 = s->w1;
  val = CCacheEntry__GetData(a);
  CIndexedSet__ConstructFromRawData(&tmp, val, 0);
  if (s->index == (-1))
  {
    o->x = 0;
  }
  else
  {
    val = func_8002DBF8(&tmp, a->id, s->index, &size);
    func_80026DA4(((u8 *) o) + 4, val, size);
  }
}
