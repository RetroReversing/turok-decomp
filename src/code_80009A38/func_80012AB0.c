#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void func_80012AB0(CMtxF mfThis, float RotY) ;
void func_80012AB0(CMtxF mfThis, float RotY);
void func_80012AB0(CMtxF mfThis, float RotY){
 float SinRotY = __sinf(RotY), CosRotY = __cosf(RotY) ;
 float a ;
 a = mfThis[0][0] ;
 mfThis[0][0] = (a * CosRotY) + (mfThis[0][2] * SinRotY) ;
 mfThis[0][2] = (a * -SinRotY) + (mfThis[0][2] * CosRotY) ;
 a = mfThis[1][0] ;
 mfThis[1][0] = (a * CosRotY) + (mfThis[1][2] * SinRotY) ;
 mfThis[1][2] = (a * -SinRotY) + (mfThis[1][2] * CosRotY) ;
 a = mfThis[2][0] ;
 mfThis[2][0] = (a * CosRotY) + (mfThis[2][2] * SinRotY) ;
 mfThis[2][2] = (a * -SinRotY) + (mfThis[2][2] * CosRotY) ;
 a = mfThis[3][0] ;
 mfThis[3][0] = (a * CosRotY) + (mfThis[3][2] * SinRotY) ;
 mfThis[3][2] = (a * -SinRotY) + (mfThis[3][2] * CosRotY) ;
}
