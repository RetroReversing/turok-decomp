#include "common.h"

typedef struct A
{
  char p0[8];
  float x8;
  char p1[0x130 - 0xc];
  int f130;
  char p2[0x1dc - 0x134];
  short h1dc;
} A;
typedef struct B
{
  char p0[0x18];
  int v18;
  char p1[4];
  int v20;
  char p2[0x34 - 0x24];
  int f34;
  char p3[0x48 - 0x38];
  int v48;
  char p4[0xcc - 0x4c];
  float vcc;
  char p5[0x108 - 0xd0];
  short h108;
  char p6[2];
  float f10c;
  char p7[0x170 - 0x110];
  char *p170;
  char p8[0x188 - 0x174];
  char *p188;
  char p9[0x1d4 - 0x18c];
  int v1d4;
  char p10[4];
  float f1dc;
  float f1e0;
  char p11[0x1fc - 0x1e4];
  char *p1fc;
} B;
extern void TRex_UpdateSound(A *, B *);
extern int CCamera__InCinemaMode(void *);
extern void CFxSystem__StopSwooshesOnObject(void *, A *);
extern void TRex_CheckHitByExplosion(A *, B *);
extern volatile short TRex_SetupMode(A *, int);
extern void TRex_CheckForTurokInCave(A *, B *);
extern void TRex_GetTarget(A *, B *);
extern void TRex_SetupStageInfo(A *, B *, void *);
extern double D_800F2950;
extern double D_800F2958;
extern float D_800B6B00;
extern char *D_8010201C;
extern int D_80112C18;
extern int D_80112E10;
void TRex_Update(A *trexObject, B *trex)
{
  /* Update the T-Rex boss's combat state, action and scripted attacks. */
  char *sp24;
  int n;
  void (*callback)(A *, B *);
  TRex_UpdateSound(trexObject, trex);
  if (!(trex->f34 & 0x02000000))
  {
    CFxSystem__StopSwooshesOnObject(&D_80112E10, trexObject);
  }
  if (CCamera__InCinemaMode(&D_80112C18) == 0)
  {
    if (trexObject->h1dc > 0)
    {
      TRex_CheckHitByExplosion(trexObject, trex);
      if (!(trex->f34 & 0x2001))
      {
        char *p = trex->p1fc;
        if (trex->v18 < (*((short *) p)))
        {
          trex->p1fc = p + 8;
          TRex_SetupMode(trexObject, 0x26);
        }
      }
    }
    if (!(trexObject->f130 & 0x20000))
    {
      if ((trexObject->h1dc <= 0) && (trex->v20 != 0x28))
      {
        TRex_SetupMode(trexObject, 0x28);
      }
      sp24 = D_8010201C;
      TRex_CheckForTurokInCave(trexObject, trex);
      if (trex->h108 == 0)
      {
        trex->f10c += D_800B6B00;
        if (D_800F2950 <= ((double) trex->f10c))
        {
          trex->h108 = 2;
          trex->f10c = 0.0f;
          TRex_SetupMode(trexObject, 0x10);
          trex->v48 = 1;
          return;
        }
      }
      else
        if (trex->h108 == 1)
      {
        if (trex->v20 == 3)
        {
          trex->f10c += D_800B6B00;
          if (trex->f10c >= 30.0f)
          {
            trex->h108 = 2;
            trex->f10c = 0.0f;
            TRex_SetupMode(trexObject, 0x10);
            trex->v48 = 1;
            return;
          }
        }
      }
      else
        if (trex->v1d4 && (trex->f1e0 <= trex->f1dc))
      {
        if (trex->h108 != 4)
        {
          TRex_SetupMode(trexObject, 5);
        }
        if (trex->h108 != 4)
        {
          trex->h108 = 4;
        }
      }
      else
        if (D_800F2958 < ((double) ((*((float *) (sp24 + 8))) - trexObject->x8)))
      {
        trex->h108 = 3;
      }
      else
      {
        trex->h108 = 2;
      }
      TRex_GetTarget(trexObject, trex);
      n = trex->v20;
      if (n >= 0)
      {
        callback = *((void (**)(A *, B *)) ((trex->p170 + (n * 20)) + 4));
        if (callback)
        {
          callback(trexObject, trex);
        }
      }
      if (trex->v18 < (*((int *) trex->p188)))
      {
        trex->p188 += 0x24;
        TRex_SetupStageInfo(trexObject, trex, trex->p188);
      }
      trex->vcc = *((float *) (trex->p188 + 4));
    }
  }
}
