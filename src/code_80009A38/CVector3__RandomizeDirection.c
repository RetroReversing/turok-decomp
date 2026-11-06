#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
extern void CVector3__Normalize(CVector3 *pvThis);
extern CVector3 CVector3__RandomizeDirection(CVector3 *pvThis, float uRandom);
extern int D_800137A0();
void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void CVector3__Normalize(CVector3 *pvThis);
CVector3 CVector3__RandomizeDirection(CVector3 *pvThis, float uRandom);
int D_800137A0();
CVector3 CVector3__RandomizeDirection(CVector3 *pvThis, float uRandom){
 CVector3 vRandom, vOut;
 vRandom.x = (D_800137A0() % (20000)) - 10000;
 vRandom.y = (D_800137A0() % (20000)) - 10000;
 vRandom.z = (D_800137A0() % (20000)) - 10000;
 CVector3__Normalize(&vRandom);
 CVector3__Normalize(pvThis);
 CVector3__Blend(&vOut, uRandom, pvThis, &vRandom);
 return vOut;
}
