#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Add(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void CVector3__Add(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight);
void CVector3__Add(CVector3 *pvThis, CVector3 *pvLeft, CVector3 *pvRight){
 pvThis->x = pvLeft->x + pvRight->x;
 pvThis->y = pvLeft->y + pvRight->y;
 pvThis->z = pvLeft->z + pvRight->z;
}
