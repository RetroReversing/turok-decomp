#include "common.h"

struct CQuatern_t;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void func_80014CB8(CQuatern *pqThis, const CQuatern *pqLeft, const CQuatern *pqRight);
void func_80014CB8(CQuatern *pqThis, const CQuatern *pqLeft, const CQuatern *pqRight);
void func_80014CB8(CQuatern *pqThis, const CQuatern *pqLeft, const CQuatern *pqRight){
   pqThis->x = pqRight->t*pqLeft->x - pqRight->z*pqLeft->y + pqRight->y*pqLeft->z + pqRight->x*pqLeft->t;
   pqThis->y = pqRight->z*pqLeft->x + pqRight->t*pqLeft->y - pqRight->x*pqLeft->z + pqRight->y*pqLeft->t;
   pqThis->z = -pqRight->y*pqLeft->x + pqRight->x*pqLeft->y + pqRight->t*pqLeft->z + pqRight->z*pqLeft->t;
   pqThis->t = -pqRight->x*pqLeft->x - pqRight->y*pqLeft->y - pqRight->z*pqLeft->z + pqRight->t*pqLeft->t;
}
