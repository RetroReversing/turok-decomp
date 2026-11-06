#include "common.h"

typedef struct 
{
  s32 a;
  s32 flags;
} Link;
typedef struct 
{
  unsigned char pad0[0x20];
  s32 state;
  unsigned char pad24[0xE4];
  s16 mode;
  unsigned char pad10A[6];
  f32 v110;
  f32 v114;
  unsigned char pad118[0xC];
  f32 v124;
  unsigned char pad128[0xA8];
  f32 v1D0;
  unsigned char pad1D4[0x28];
  Link *p1FC;
} Obj;
extern f64 D_800F2A30;
extern f64 D_800F2A38;
extern f64 D_800F2A40;
extern f64 D_800F2A48;
extern f64 D_800F2A50;
extern f64 D_800F2A58;
extern f64 D_800F2A60;
extern f64 D_800F2A68;
extern f64 D_800F2A70;
extern f64 D_800F2A78;
extern f64 D_800F2A80;
extern f64 D_800F2A88;
extern f64 D_800F2A90;
extern s32 TRex_CheckForMaxRunTime(s32, Obj *);
extern s32 TRex_CheckForMaxTurnTime(s32, Obj *);
extern void BOSS_PerformTurn(s32, Obj *, u32, f32);
extern void TRex_SetupMode(s32, s32);
extern void TRex_RunScriptCommand(s32, Obj *, void *, s32);
void TRex_Code_Movement(s32 arg0, Obj *arg1)
{
  f32 angleDelta = arg1->v114;
  /* Update directional movement states using the current angular deltas. */
  f32 absAngleDelta;
  if (!(arg1->p1FC->flags & 32))
  {
    if ((arg1->v1D0 < arg1->v124) && (TRex_CheckForMaxRunTime(arg0, arg1) == 0))
    {
      BOSS_PerformTurn(arg0, arg1, 0x3E0EFA35, angleDelta);
      if (((f64) angleDelta) < D_800F2A30)
      {
        if (!TRex_CheckForMaxTurnTime(arg0, arg1))
        {
          arg1->state = 10;
        }
      }
      else
        if (D_800F2A38 < ((f64) angleDelta))
      {
        if (!TRex_CheckForMaxTurnTime(arg0, arg1))
        {
          arg1->state = 11;
        }
      }
      absAngleDelta = (angleDelta < 0) ? (-angleDelta) : (angleDelta);
      if (D_800F2A40 >= ((f64) absAngleDelta))
      {
        if (((arg1->mode == 2) && (((f64) arg1->v124) <= D_800F2A48)) && (((f64) ((angleDelta < 0) ? (-angleDelta) : (angleDelta))) <= D_800F2A50))
        {
          TRex_SetupMode(arg0, 12);
        }
        else
          if (!TRex_CheckForMaxRunTime(arg0, arg1))
        {
          arg1->state = 9;
        }
      }
    }
  }
  else
    if ((arg1->v1D0 < arg1->v124) && (!TRex_CheckForMaxRunTime(arg0, arg1)))
  {
    BOSS_PerformTurn(arg0, arg1, 0x3E0EFA35, angleDelta);
    if (((f64) angleDelta) < D_800F2A58)
    {
      if (!TRex_CheckForMaxTurnTime(arg0, arg1))
      {
        arg1->state = 14;
        BOSS_PerformTurn(arg0, arg1, 0x3E0EFA35, angleDelta);
      }
    }
    else
      if (D_800F2A60 < ((f64) angleDelta))
    {
      if (!TRex_CheckForMaxTurnTime(arg0, arg1))
      {
        arg1->state = 15;
        BOSS_PerformTurn(arg0, arg1, 0x3E0EFA35, angleDelta);
      }
    }
    if (((f64) ((angleDelta < 0) ? (-angleDelta) : (angleDelta))) <= D_800F2A68)
    {
      arg1->state = 13;
    }
  }
  if (arg1->v124 <= arg1->v1D0)
  {
    angleDelta = arg1->v110;
    if (arg1->state != 8)
    {
      BOSS_PerformTurn(arg0, arg1, 0x3D8EFA35, angleDelta);
      if (D_800F2A70 < ((f64) ((angleDelta < 0) ? (-angleDelta) : (angleDelta))))
      {
        if (!TRex_CheckForMaxTurnTime(arg0, arg1))
        {
          arg1->state = 8;
        }
      }
      else
        if (((f64) angleDelta) < D_800F2A78)
      {
        if (!TRex_CheckForMaxTurnTime(arg0, arg1))
        {
          arg1->state = 6;
        }
      }
      else
        if (D_800F2A80 < ((f64) angleDelta))
      {
        if (!TRex_CheckForMaxTurnTime(arg0, arg1))
        {
          arg1->state = 7;
        }
      }
    }
    if (((f64) ((angleDelta < 0) ? (-angleDelta) : (angleDelta))) <= D_800F2A88)
    {
      switch (arg1->mode)
      {
        case 2:
          if (((f64) arg1->v124) <= D_800F2A90)
        {
          TRex_RunScriptCommand(arg0, arg1, ((char *) arg1) + 0x194, 4);
        }
        else
        {
          TRex_RunScriptCommand(arg0, arg1, ((char *) arg1) + 0x18C, 4);
        }
          break;

        case 3:
          TRex_RunScriptCommand(arg0, arg1, ((char *) arg1) + 0x1AC, 4);
          break;

        case 4:
          TRex_SetupMode(arg0, 0x1B);
          break;

      }

    }
  }
}
