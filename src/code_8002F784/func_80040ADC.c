#include "common.h"

extern float func_80040ADC(float Var, float Target, float Speed) ;
extern float D_800B6B00;
float func_80040ADC(float Var, float Target, float Speed);
float func_80040ADC(float Var, float Target, float Speed){
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
