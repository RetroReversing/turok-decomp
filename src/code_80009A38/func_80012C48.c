#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void func_80012C48(CMtxF mfThis, float RotX) ;
void func_80012C48(CMtxF mfThis, float RotX);
void func_80012C48(CMtxF mfThis, float RotX){
 float SinRotX = __sinf(RotX), CosRotX = __cosf(RotX) ;
 float a ;
 a = mfThis[0][1] ;
 mfThis[0][1] = (a * CosRotX) + (mfThis[0][2] * -SinRotX) ;
 mfThis[0][2] = (a * SinRotX) + (mfThis[0][2] * CosRotX) ;
 a = mfThis[1][1] ;
 mfThis[1][1] = (a * CosRotX) + (mfThis[1][2] * -SinRotX) ;
 mfThis[1][2] = (a * SinRotX) + (mfThis[1][2] * CosRotX) ;
 a = mfThis[2][1] ;
 mfThis[2][1] = (a * CosRotX) + (mfThis[2][2] * -SinRotX) ;
 mfThis[2][2] = (a * SinRotX) + (mfThis[2][2] * CosRotX) ;
 a = mfThis[3][1] ;
 mfThis[3][1] = (a * CosRotX) + (mfThis[3][2] * -SinRotX) ;
 mfThis[3][2] = (a * SinRotX) + (mfThis[3][2] * CosRotX) ;
}
