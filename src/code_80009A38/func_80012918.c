#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void func_80012918(CMtxF mfThis, float RotZ) ;
void func_80012918(CMtxF mfThis, float RotZ);
void func_80012918(CMtxF mfThis, float RotZ){
 float SinRotZ = __sinf(RotZ), CosRotZ = __cosf(RotZ) ;
 float a ;
 a = mfThis[0][0] ;
 mfThis[0][0] = (a * CosRotZ) + (mfThis[0][1] * -SinRotZ) ;
 mfThis[0][1] = (a * SinRotZ) + (mfThis[0][1] * CosRotZ) ;
 a = mfThis[1][0] ;
 mfThis[1][0] = (a * CosRotZ) + (mfThis[1][1] * -SinRotZ) ;
 mfThis[1][1] = (a * SinRotZ) + (mfThis[1][1] * CosRotZ) ;
 a = mfThis[2][0] ;
 mfThis[2][0] = (a * CosRotZ) + (mfThis[2][1] * -SinRotZ) ;
 mfThis[2][1] = (a * SinRotZ) + (mfThis[2][1] * CosRotZ) ;
 a = mfThis[3][0] ;
 mfThis[3][0] = (a * CosRotZ) + (mfThis[3][1] * -SinRotZ) ;
 mfThis[3][1] = (a * SinRotZ) + (mfThis[3][1] * CosRotZ) ;
}
