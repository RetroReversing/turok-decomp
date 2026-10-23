#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef float CMtxF[4][4];
extern void func_80015624(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void func_80015624(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void func_80015624(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut){
   float divisor, invDivisor;
 pvOut->x = mfThis[0][0]*pvIn->x + mfThis[1][0]*pvIn->y
               + mfThis[2][0]*pvIn->z + mfThis[3][0];
   pvOut->y = mfThis[0][1]*pvIn->x + mfThis[1][1]*pvIn->y
               + mfThis[2][1]*pvIn->z + mfThis[3][1];
   pvOut->z = mfThis[0][2]*pvIn->x + mfThis[1][2]*pvIn->y
               + mfThis[2][2]*pvIn->z + mfThis[3][2];
 divisor = mfThis[0][3]*pvIn->x + mfThis[1][3]*pvIn->y
     + mfThis[2][3]*pvIn->z + mfThis[3][3];
   if (divisor != 0)
 {
  invDivisor = 1/divisor;
  pvOut->x *= invDivisor;
  pvOut->y *= invDivisor;
  pvOut->z *= invDivisor;
 }
}
