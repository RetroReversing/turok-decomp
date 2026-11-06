#include "common.h"

extern float AccelerateFLOAT(float Var, float Accel, float MaxSpeed) ;
extern float D_800B6B00;
float AccelerateFLOAT(float Var, float Accel, float MaxSpeed);
float AccelerateFLOAT(float Var, float Accel, float MaxSpeed){
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
