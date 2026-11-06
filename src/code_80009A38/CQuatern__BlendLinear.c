#include "common.h"

struct CQuatern_t;
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void CQuatern__BlendLinear(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void CQuatern__BlendLinear(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB);
void CQuatern__BlendLinear(CQuatern *pqThis, float u, CQuatern *pqA, CQuatern *pqB){
 pqThis->x = ((pqA->x) + (u)*(((float)(pqB->x)) - (pqA->x)));
 pqThis->y = ((pqA->y) + (u)*(((float)(pqB->y)) - (pqA->y)));
 pqThis->z = ((pqA->z) + (u)*(((float)(pqB->z)) - (pqA->z)));
 pqThis->t = ((pqA->t) + (u)*(((float)(pqB->t)) - (pqA->t)));
}
