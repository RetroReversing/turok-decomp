#include "common.h"

extern const float D_800F61D8; extern float func_8008CB48(float PitchCents);
extern float D_800ED23C[121] ;
float func_8008CB48(float PitchCents);

float func_8008CB48(float PitchCents){
 float u, Value1, Value2, TableIndex2;
 signed short TableIndex1, TableIndex3;
 TableIndex2 = (PitchCents+D_800F61D8)/60;
 TableIndex1 = (signed short)(TableIndex2);
 if((float)(TableIndex1) != TableIndex2)
 {
  TableIndex3 = TableIndex1+1;
  Value1 = D_800ED23C[TableIndex1];
  Value2 = D_800ED23C[TableIndex3];
  u = TableIndex2-TableIndex1;
  return ((Value1) + (u)*(((float)(Value2)) - (Value1)));
 }
 else
 {
  return D_800ED23C[TableIndex1];
 }
}
