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
extern void BOSS_UpdateSounds(void);
extern void BOSS_CalculateAngles(P *, S *);
extern void BOSS_UpdateAnimation(P *);
extern float sqrtf(float);
extern float AI_DistanceSquared(P *, V3);
extern void CVector3__Subtract(V3 *, V3 *, V3 *);
extern void CVector3__Normalize(V3 *);
/* Update boss motion, health, animation and its tracking of Turok. */
void func_8003FC00(P *p)
{
  S *s = p->state;
  float f;
  G *g = D_8010201C;
  V3 *v;
  BOSS_UpdateSounds();
  p->ptr = D_8010201C;
  f = (D_80128C20[12] * D_80128C20[12]) + (D_80128C20[0] * D_80128C20[0]);
  if (f != 0.0f)
  {
    f = sqrtf(f);
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
    f = sqrtf(f);
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
  s->a140 = AI_DistanceSquared(p, D_8010201C->vec);
  if (s->a140 != 0.0f)
  {
    s->a140 = sqrtf(s->a140);
  }
  BOSS_CalculateAngles(p, s);
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
  BOSS_UpdateAnimation(p);
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
  CVector3__Subtract(&D_80112C0C, v, &D_80112C00);
  CVector3__Normalize(&D_80112C0C);
  D_80112C00 = *v;
}
