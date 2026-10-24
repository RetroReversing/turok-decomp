#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void func_80013BBC(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight){
 pvThis->x = pvLeft->y*pvRight->z - pvLeft->z*pvRight->y;
 pvThis->y = pvLeft->z*pvRight->x - pvLeft->x*pvRight->z;
 pvThis->z = pvLeft->x*pvRight->y - pvLeft->y*pvRight->x;
}
