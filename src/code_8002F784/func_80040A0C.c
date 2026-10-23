#include "common.h"

extern float func_80040A0C(float Var, float Decel) ;
extern float D_800B6B00;
float func_80040A0C(float Var, float Decel);
float func_80040A0C(float Var, float Decel){
 if (Var > 0)
 {
  Var -= Decel * D_800B6B00 ;
  if (Var < 0)
   Var = 0 ;
 }
 else
 if (Var < 0)
 {
  Var += Decel * D_800B6B00 ;
  if (Var > 0)
   Var = 0 ;
 }
 return Var ;
}
