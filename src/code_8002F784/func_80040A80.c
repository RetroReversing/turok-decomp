#include "common.h"

extern signed long func_80040A80(signed long Var, signed long Accel, signed long MaxSpeed) ;
extern float D_800B6B00;
signed long func_80040A80(signed long Var, signed long Accel, signed long MaxSpeed);
signed long func_80040A80(signed long Var, signed long Accel, signed long MaxSpeed){
 Var += Accel * D_800B6B00 ;
 if (Accel < 0)
 {
  if (Var < -MaxSpeed)
   Var = -MaxSpeed ;
 }
 else
 {
  if (Var > MaxSpeed)
   Var = MaxSpeed ;
 }
 return Var ;
}
