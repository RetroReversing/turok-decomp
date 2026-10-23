#include "common.h"

extern float func_8009E7B0(float angle);
extern float func_8009E630(float angle);
typedef float CMtxF[4][4];
extern void func_800129F8(CMtxF mfThis, float RotZ) ;
void func_800129F8(CMtxF mfThis, float RotZ);
void func_800129F8(CMtxF mfThis, float RotZ){
 float SinRotZ = func_8009E7B0(RotZ), CosRotZ = func_8009E630(RotZ) ;
 float a ;
 a = mfThis[0][0] ;
 mfThis[0][0] = (CosRotZ * a) + (SinRotZ * mfThis[1][0]) ;
 mfThis[1][0] = (-SinRotZ * a) + (CosRotZ * mfThis[1][0]) ;
 a = mfThis[0][1] ;
 mfThis[0][1] = (CosRotZ * a) + (SinRotZ * mfThis[1][1]) ;
 mfThis[1][1] = (-SinRotZ * a) + (CosRotZ * mfThis[1][1]) ;
 a = mfThis[0][2] ;
 mfThis[0][2] = (CosRotZ * a) + (SinRotZ * mfThis[1][2]) ;
 mfThis[1][2] = (-SinRotZ * a) + (CosRotZ * mfThis[1][2]) ;
}
