#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
extern float sqrtf(float value);
struct CQuatern_t;
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__MultScaler(CVector3 *pvThis, CVector3 *pvIn, float Scaler);
extern void CVector3__Cross(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
extern void CVector3__Normalize(CVector3 *pvThis);
struct CQuatern_t CVector3__GetDirectionRotation(CVector3 *pvThis);
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern float D_80119CB0,
     inv_mag_squared;
extern float acos(float x);
extern float D_80119CB0,
   inv_mag_squared;
void CVector3__MultScaler(CVector3 *pvThis, CVector3 *pvIn, float Scaler);
void CVector3__Cross(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void CVector3__Normalize(CVector3 *pvThis);
CQuatern CVector3__GetDirectionRotation(CVector3 *pvThis);
float acos(float x);
CQuatern CVector3__GetDirectionRotation(CVector3 *pvThis){
 CQuatern qRot;
 CVector3 vUnitVelocity,
    vZ,
    vAxis;
 float mag,
    theta, cosTheta;
 mag = sqrtf(((pvThis)->x*(pvThis)->x + (pvThis)->y*(pvThis)->y + (pvThis)->z*(pvThis)->z));
 if (mag == 0)
 {
  { (&qRot)->x = (&qRot)->y = (&qRot)->z = 0; (&qRot)->t = 1; };
 }
 else
 {
  CVector3__MultScaler(&vUnitVelocity, pvThis, 1/mag);
  vZ.x = 0;
  vZ.y = 0;
  vZ.z = 1;
  cosTheta = ((&vUnitVelocity)->x*(&vZ)->x + (&vUnitVelocity)->y*(&vZ)->y + (&vUnitVelocity)->z*(&vZ)->z);
  theta = acos(cosTheta);
  CVector3__Cross(&vAxis, &vZ, &vUnitVelocity);
  CVector3__Normalize(&vAxis);
  D_80119CB0 = __sinf((theta)/2); (&qRot)->x = (vAxis.x)*D_80119CB0; (&qRot)->y = (vAxis.y)*D_80119CB0; (&qRot)->z = (vAxis.z)*D_80119CB0; (&qRot)->t = __cosf((theta)/2);;
 }
 return qRot;
}
