#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void func_80012E6C(CMtxF mfThis, float Theta) ;
void func_80012E6C(CMtxF mfThis, float Theta);
void func_80012E6C(CMtxF mfThis, float Theta){
 float sine ;
 float cosine ;
 sine = __sinf(Theta) ;
 cosine = __cosf(Theta) ;
 mfThis[0][3] = mfThis[1][3] = mfThis[2][3] =
 mfThis[3][0] = mfThis[3][1] = mfThis[3][2] =
 mfThis[2][1] = mfThis[1][2] = mfThis[1][0] = mfThis[0][1] = 0 ;
 mfThis[1][1] = mfThis[3][3] = 1 ;
 mfThis[2][0] = sine ;
 mfThis[0][2] = -sine ;
 mfThis[0][0] = mfThis[2][2] = cosine ;
}
