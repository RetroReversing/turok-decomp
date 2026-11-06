#include "common.h"

extern void ProportionalZoomVarFLOAT(float *pVar, float Target, float Speed) ;
extern float D_800B6B00;
void ProportionalZoomVarFLOAT(float *pVar, float Target, float Speed);
void ProportionalZoomVarFLOAT(float *pVar, float Target, float Speed){
 float Delta = (Target - *pVar) * Speed * D_800B6B00 ;
 if (Speed == 1)
  *pVar = Target ;
 else
 if (*pVar < Target)
 {
  *pVar += Delta ;
  if (*pVar > Target)
   *pVar = Target ;
 }
 else
 if (*pVar > Target)
 {
  *pVar += Delta ;
  if (*pVar < Target)
   *pVar = Target ;
 }
}
