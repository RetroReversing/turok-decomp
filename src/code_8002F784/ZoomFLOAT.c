#include "common.h"

extern float ZoomFLOAT(float Var, float Target, float Speed) ;
extern float D_800B6B00;
float ZoomFLOAT(float Var, float Target, float Speed);
float ZoomFLOAT(float Var, float Target, float Speed){
 if (Var < Target)
 {
  Var += Speed * D_800B6B00 ;
  if (Var > Target)
   Var = Target ;
 }
 else
 if (Var > Target)
 {
  Var -= Speed * D_800B6B00 ;
  if (Var < Target)
   Var = Target ;
 }
 return Var ;
}
