#include "common.h"

typedef struct 
{
  float x;
  float y;
  float z;
} V3;
typedef struct 
{
  int a0;
  int a4;
  char p8[4];
  int aC;
  int a10;
  int a14;
  int a18;
  int a1C;
  char p20[4];
  int a24;
  char p28[4];
  float a2C;
  char p30[0xA8];
  float aD8;
  char pDC[8];
  V3 pos;
  V3 delta;
  V3 dir;
  char p108[0x38];
  float a140;
  char p144[0x24];
  void (*cb)(void *, void *);
} S;
typedef struct 
{
  int a0;
  V3 vec;
} G;
typedef struct 
{
  int a0;
  V3 pos;
  char pad[0x16C];
  S *state;
  char pad2[0x5C];
  short val;
  char pad3[0x46];
  void *ptr;
} P;
extern G *D_8010201C;
extern float D_800B6B00;
extern float D_80112BE4;
extern V3 D_80112C00;
extern V3 D_80112C0C;
extern float D_80128C20[];
extern void func_8003FB8C(void);
extern void func_8003FF88(P *, S *);
extern void func_8003F9C0(P *);
extern float func_8009E7A0(float);
extern float func_8005F34C(P *, V3);
extern void func_800144C8(V3 *, V3 *, V3 *);
extern void func_80013B2C(V3 *);
/* Update boss motion, health, animation and its tracking of Turok. */
void func_8003FC00(P *p)
{
  S *s = p->state;
  float f;
  G *g = D_8010201C;
  V3 *v;
  func_8003FB8C();
  p->ptr = D_8010201C;
  f = (D_80128C20[12] * D_80128C20[12]) + (D_80128C20[0] * D_80128C20[0]);
  if (f != 0.0f)
  {
    f = func_8009E7A0(f);
  }
  D_80112BE4 = f;
  if (!s->a4)
  {
    s->a4 = 1;
    s->a24 = -1;
    s->a2C = 0.0f;
  }
  s->a2C += D_800B6B00;
  s->delta.x = p->pos.x - s->pos.x;
  s->delta.y = p->pos.y - s->pos.y;
  s->delta.z = p->pos.z - s->pos.z;
  f = ((s->delta.x * s->delta.x) + (s->delta.y * s->delta.y)) + (s->delta.z * s->delta.z);
  if (f != 0.0f)
  {
    f = func_8009E7A0(f);
    s->aD8 = f;
  }
  else
  {
    f = 1.0f;
    s->aD8 = 0.0f;
  }
  s->dir.x = s->delta.x / f;
  s->dir.y = s->delta.y / f;
  s->dir.z = s->delta.z / f;
  s->a140 = func_8005F34C(p, D_8010201C->vec);
  if (s->a140 != 0.0f)
  {
    s->a140 = func_8009E7A0(s->a140);
  }
  func_8003FF88(p, s);
  s->a14 = s->a18;
  if (p->val > 0)
  {
 do { s->a18 = (p->val * 100) / s->aC; if (s->a18 == 0) { s->a18 = 1; } } while (0);
  }
  else
  {
    s->a18 = 0;
  }
  if (s->cb)
  {
    s->cb(p, s);
  }
  func_8003F9C0(p);
  s->a10 = p->val;
  if (s->a0 && (p->val <= 0))
  {
    s->a0 = 0;
  }
  s->pos.x = p->pos.x;
  s->pos.y = p->pos.y;
  s->pos.z = p->pos.z;
  s->a1C = 0;
  v = &g->vec;
  func_800144C8(&D_80112C0C, v, &D_80112C00);
  func_80013B2C(&D_80112C0C);
  D_80112C00 = *v;
}
