#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight);
void func_800141A8(CVector3 *pvThis, float u, CVector3 *pvLeft, CVector3 *pvRight){
 pvThis->x = ((pvLeft->x) + (u)*(((float)(pvRight->x)) - (pvLeft->x)));
 pvThis->y = ((pvLeft->y) + (u)*(((float)(pvRight->y)) - (pvLeft->y)));
 pvThis->z = ((pvLeft->z) + (u)*(((float)(pvRight->z)) - (pvLeft->z)));
}
