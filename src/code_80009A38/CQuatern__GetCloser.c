#include "common.h"

extern const double D_800F0D38; struct CQuatern_t;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void D_800145DC(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
extern void CQuatern__GetCloser(CQuatern *pqThis, CQuatern *pqTarget);
extern float acos(float x);
extern float D_800B6B00;
void D_800145DC(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void CQuatern__GetCloser(CQuatern *pqThis, CQuatern *pqTarget);
float acos(float x);
void CQuatern__GetCloser(CQuatern *pqThis, CQuatern *pqTarget){
 CQuatern qResult;
 float dot, theta, deltaTheta, u;
 dot = ((pqThis)->x*(pqTarget)->x + (pqThis)->y*(pqTarget)->y + (pqThis)->z*(pqTarget)->z + (pqThis)->t*(pqTarget)->t);
 theta = acos(dot);
 if (theta != 0)
 {
  deltaTheta = (theta*(D_800F0D38) + ((0.01)*(3.14159265358979323846/180)))*D_800B6B00;
  u = ((0) > (((1) < (1 - (theta - deltaTheta)/theta) ? (1) : (1 - (theta - deltaTheta)/theta))) ? (0) : (((1) < (1 - (theta - deltaTheta)/theta) ? (1) : (1 - (theta - deltaTheta)/theta))));
  D_800145DC(&qResult, u, pqThis, pqTarget);
  *pqThis = qResult;
 }
}
