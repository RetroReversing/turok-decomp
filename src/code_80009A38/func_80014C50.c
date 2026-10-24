#include "common.h"

struct CQuatern_t;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void func_80014C50(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void func_80014C50(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void func_80014C50(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB){
 pqThis->x = ((pqA->x) + (u)*(((float)(pqB->x)) - (pqA->x)));
 pqThis->y = ((pqA->y) + (u)*(((float)(pqB->y)) - (pqA->y)));
 pqThis->z = ((pqA->z) + (u)*(((float)(pqB->z)) - (pqA->z)));
 pqThis->t = ((pqA->t) + (u)*(((float)(pqB->t)) - (pqA->t)));
}
