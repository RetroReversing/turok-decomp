#include "common.h"

extern f32 func_800409AC(f32, f32, f32);
extern f32 func_80040A0C(f32, f32);
extern f32 func_80040ADC(f32, f32, u32);
extern void func_8004463C(void *, s32);
extern s32 func_80045624(void *, void *);
extern void func_80046934(void *, void *);
extern void func_8004016C(void *, void *, u32, f32);
extern f32 func_8009E630(f32);
extern f32 func_8009E7A0(f32);
extern f32 func_8009E7B0(f32);
extern f32 D_800B6B00;
extern f32 D_800F28A0;
extern f32 D_800F28B0;
extern f32 D_800F28C0;
extern f32 D_800F28D0;
extern f64 D_800F2898;
extern f64 D_800F28A8;
extern f64 D_800F28B8;
extern f64 D_800F28C8;
typedef struct 
{
  u8 pad[0x1c];
  f32 velX;
  u8 pad20[4];
  f32 velZ;
  u8 pad28[0x3c];
  f32 rotY;
} MantisObject;
typedef struct 
{
  u8 pad[0x20];
  s32 mode;
  u8 pad24[0x18];
  s32 animPlayed;
  u8 pad40[0x90];
  f32 modeAnimSpeed;
  u8 pD4[8];
  f32 rotX;
  f32 rotZ;
  u8 pE4[0x24];
  s16 action;
  u8 pad10a[0xA];
  f32 deltaAngle;
  u8 pad118[0xC];
  f32 atTargetDist;
  u8 pad128[0x28];
  f32 distFromTarget;
  u8 pad154[0x34];
  void *stageInfo;
  u8 pad18c[0x54];
  s32 gotoFloor;
  u8 pad1e4[4];
  f32 flySpeed;
} MantisState;
/* Update the mantis's flight velocity, hover and turn, tilt, and animation speed while it chases its target. */
void func_80046AC4(MantisObject *object, MantisState *mantis)
{
  f32 deltaAngle = mantis->deltaAngle;
  f32 targetRotation;
  f32 speedSquared;
  f32 target;
  f32 result;
  f32 stageFlySpeed;
  if ((mantis->gotoFloor != 0) && (mantis->action == 2))
  {
    func_8004463C(object, 9);
    return;
  }
  speedSquared = (object->velX * object->velX) + (object->velZ * object->velZ);
  if (speedSquared != 0)
  {
    speedSquared = func_8009E7A0(speedSquared);
  }
  stageFlySpeed = *((f32 *) (((char *) mantis->stageInfo) + 8));
  if (mantis->mode == 8)
  {
    if ((mantis->distFromTarget < mantis->atTargetDist) || (mantis->action == 1))
    {
      mantis->flySpeed = func_800409AC(mantis->flySpeed, stageFlySpeed / ((f32) 16), stageFlySpeed);
    }
    else
    {
      mantis->flySpeed = func_80040A0C(mantis->flySpeed, stageFlySpeed / ((f32) 8));
    }
    object->velX = ((func_8009E7B0(object->rotY) * (-mantis->flySpeed)) * D_800B6B00) * 15.0f;
    object->velZ = ((func_8009E630(object->rotY) * (-mantis->flySpeed)) * D_800B6B00) * 15.0f;
  }
  func_80046934(object, mantis);
  func_8004016C(object, mantis, 0x3DD67750, deltaAngle);
  if (((mantis->animPlayed != 0) && (mantis->atTargetDist < mantis->distFromTarget)) && func_80045624(object, mantis))
  {
    func_8004463C(object, 9);
  }
  target = (-speedSquared) / 20.0f;
  targetRotation = target;
  if (target != 0)
  {
    if (((f64) target) < D_800F2898)
    {
      targetRotation = D_800F28A0;
    }
    else
      if (D_800F28A8 < ((f64) target))
    {
      targetRotation = D_800F28B0;
    }
    result = func_80040ADC(mantis->rotX, targetRotation, 0x3C8EFA35);
  }
  else
  {
    result = func_80040ADC(mantis->rotX, target, 0x3C0EFA35);
  }
  mantis->rotX = result;
  target = 10.0f;
  target = deltaAngle * target;
  targetRotation = target;
  if (target != 0)
  {
    if (((f64) target) < D_800F28B8)
    {
      targetRotation = D_800F28C0;
    }
    else
      if (D_800F28C8 < ((f64) target))
    {
      targetRotation = D_800F28D0;
    }
    result = func_80040ADC(mantis->rotZ, targetRotation, 0x3C8EFA35);
  }
  else
  {
    result = func_80040ADC(mantis->rotZ, target, 0x3C0EFA35);
  }
  mantis->rotZ = result;
 goto dummy_label_614559; dummy_label_614559: ;
  result = (f32) (((f64) (speedSquared / 5.f)) + 1.5);
  mantis->modeAnimSpeed = result;
  if (((f64) result) > 2.5)
  {
    mantis->modeAnimSpeed = 2.5f;
  }
}
