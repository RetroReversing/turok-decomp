#include "common.h"

extern const double D_800F0D20;
typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
extern void func_80013B2C(CVector3 *pvThis);
extern CVector3 func_800142A0(CVector3 *pvThis, float uRandom);
extern int D_800137A0();
void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013B2C(CVector3 *pvThis);
CVector3 func_800142A0(CVector3 *pvThis, float uRandom);
int D_800137A0();
CVector3 func_800142A0(CVector3 *pvThis, float uRandom){
 CVector3 vRandom, vOut;
 vRandom.x = pvThis->x;
 vRandom.y = ((D_800137A0() % (20000)) - 10000) * D_800F0D20;
 vRandom.z = pvThis->z;
 func_80013B2C(&vRandom);
 func_80013B2C(pvThis);
 func_800141A8(&vOut, uRandom, pvThis, &vRandom);
 return vOut;
}
