#include "common.h"

extern float func_8009E7B0(float angle);
extern float func_8009E630(float angle);
typedef float CMtxF[4][4];
extern void func_80012B90(CMtxF mfThis, float RotY) ;
void func_80012B90(CMtxF mfThis, float RotY);
void func_80012B90(CMtxF mfThis, float RotY){
 float SinRotY = func_8009E7B0(RotY), CosRotY = func_8009E630(RotY) ;
 float a ;
 a = mfThis[0][0] ;
 mfThis[0][0] = (CosRotY * a) + (-SinRotY * mfThis[2][0]) ;
 mfThis[2][0] = (SinRotY * a) + (CosRotY * mfThis[2][0]) ;
 a = mfThis[0][1] ;
 mfThis[0][1] = (CosRotY * a) + (-SinRotY * mfThis[2][1]) ;
 mfThis[2][1] = (SinRotY * a) + (CosRotY * mfThis[2][1]) ;
 a = mfThis[0][2] ;
 mfThis[0][2] = (CosRotY * a) + (-SinRotY * mfThis[2][2]) ;
 mfThis[2][2] = (SinRotY * a) + (CosRotY * mfThis[2][2]) ;
}
