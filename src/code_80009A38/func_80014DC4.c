#include "common.h"

struct CQuatern_t;
typedef float CMtxF[4][4];
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void func_80014DC4(CQuatern *pqThis, CMtxF mfRotate);
void func_80014DC4(CQuatern *pqThis, CMtxF mfRotate);
void func_80014DC4(CQuatern *pqThis, CMtxF mfRotate){
 float x, x2,
    y, y2,
    z, z2,
    t, t2;
 float xy2,
    tz2,
    xz2,
    ty2,
    yz2,
    tx2 ;
 x = pqThis->x;
 x2 = x*x;
 y = pqThis->y;
 y2 = y*y;
 z = pqThis->z;
 z2 = z*z;
 t = pqThis->t;
 t2 = t*t;
 xy2 = 2*x*y ;
 tz2 = 2*t*z ;
 xz2 = 2*x*z ;
 ty2 = 2*t*y ;
 yz2 = 2*y*z ;
 tx2 = 2*t*x ;
 mfRotate[0][0] = t2 + x2 - y2 - z2;
   mfRotate[0][1] = xy2 + tz2 ;
   mfRotate[0][2] = xz2 - ty2 ;
   mfRotate[0][3] = 0;
 mfRotate[1][0] = xy2 - tz2 ;
   mfRotate[1][1] = t2 - x2 + y2 - z2;
   mfRotate[1][2] = yz2 + tx2 ;
   mfRotate[1][3] = 0;
   mfRotate[2][0] = xz2 + ty2 ;
   mfRotate[2][1] = yz2 - tx2 ;
   mfRotate[2][2] = t2 - x2 - y2 + z2;
   mfRotate[2][3] = 0;
   mfRotate[3][0] = 0;
   mfRotate[3][1] = 0;
   mfRotate[3][2] = 0;
 mfRotate[3][3] = 1;
}
