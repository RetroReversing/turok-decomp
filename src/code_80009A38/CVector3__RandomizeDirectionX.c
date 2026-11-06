#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern const double D_800F0D28; typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
extern void CVector3__Normalize(CVector3 *pvThis);
extern CVector3 CVector3__RandomizeDirectionX(CVector3 *pvThis, float uRandom);
extern int D_800137A0();
void CVector3__Blend(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void CVector3__Normalize(CVector3 *pvThis);
CVector3 CVector3__RandomizeDirectionX(CVector3 *pvThis, float uRandom);
int D_800137A0();
/* uRandom should range from 0 to 1 (1 is completely random) */ /* output is not normalized (fine for direction) */ CVector3 CVector3__RandomizeDirectionX(CVector3 *pvThis, float uRandom){
 CVector3 vRandom, vOut;
 vRandom.x = ((D_800137A0() % (20000)) - 10000) * D_800F0D28;
 vRandom.y = pvThis->y;
 vRandom.z = pvThis->z;
 CVector3__Normalize(&vRandom);
 CVector3__Normalize(pvThis);
 CVector3__Blend(&vOut, uRandom, pvThis, &vRandom);
 return vOut;
}
