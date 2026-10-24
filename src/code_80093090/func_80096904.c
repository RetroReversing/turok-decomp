#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
int func_80096904(CVector3 vCorners[], CVector3 *pvA, CVector3 *pvB);
int func_80096904(CVector3 vCorners[], CVector3 *pvA, CVector3 *pvB){
 int e;
 CVector3 *pvCornerA, *pvCornerB;
 float vNX, vNY;
 for (e=0; e<4; e++)
 {
  pvCornerA = &vCorners[e];
  pvCornerB = &vCorners[(e == 3) ? 0 : (e + 1)];
  vNX = pvCornerB->y - pvCornerA->y;
  vNY = pvCornerA->x - pvCornerB->x;
  if ( ((vNX*(pvA->x - pvCornerA->x) + vNY*(pvA->z - pvCornerA->y)) > 0)
    && ((vNX*(pvB->x - pvCornerA->x) + vNY*(pvB->z - pvCornerA->y)) > 0) )
  {
   return 0;
  }
 }
 return 1;
}
