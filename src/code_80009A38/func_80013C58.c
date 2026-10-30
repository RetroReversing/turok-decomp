#include "common.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
extern float func_8009E7A0(float value);
struct CQuatern_t;
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_80013C2C(CVector3 *pvThis, CVector3 *pvIn, float Scaler);
extern void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
extern void func_80013B2C(CVector3 *pvThis);
struct CQuatern_t func_80013C58(CVector3 *pvThis);
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern float D_80119CB0,
     inv_mag_squared;
extern float func_8001349C(float x);
extern float D_80119CB0,
   inv_mag_squared;
void func_80013C2C(CVector3 *pvThis, CVector3 *pvIn, float Scaler);
void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013B2C(CVector3 *pvThis);
CQuatern func_80013C58(CVector3 *pvThis);
float func_8001349C(float x);
CQuatern func_80013C58(CVector3 *pvThis){
 CQuatern qRot;
 CVector3 vUnitVelocity,
    vZ,
    vAxis;
 float mag,
    theta, cosTheta;
 mag = func_8009E7A0(((pvThis)->x*(pvThis)->x + (pvThis)->y*(pvThis)->y + (pvThis)->z*(pvThis)->z));
 if (mag == 0)
 {
  { (&qRot)->x = (&qRot)->y = (&qRot)->z = 0; (&qRot)->t = 1; };
 }
 else
 {
  func_80013C2C(&vUnitVelocity, pvThis, 1/mag);
  vZ.x = 0;
  vZ.y = 0;
  vZ.z = 1;
  cosTheta = ((&vUnitVelocity)->x*(&vZ)->x + (&vUnitVelocity)->y*(&vZ)->y + (&vUnitVelocity)->z*(&vZ)->z);
  theta = func_8001349C(cosTheta);
  func_80013BBC(&vAxis, &vZ, &vUnitVelocity);
  func_80013B2C(&vAxis);
  D_80119CB0 = __sinf((theta)/2); (&qRot)->x = (vAxis.x)*D_80119CB0; (&qRot)->y = (vAxis.y)*D_80119CB0; (&qRot)->z = (vAxis.z)*D_80119CB0; (&qRot)->t = __cosf((theta)/2);;
 }
 return qRot;
}
