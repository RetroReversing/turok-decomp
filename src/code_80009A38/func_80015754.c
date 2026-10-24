#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef float CMtxF[4][4];
extern void func_80015754(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void func_80015754(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut);
void func_80015754(CMtxF mfThis, const CVector3 *pvIn, CVector3 *pvOut){
   pvOut->x = mfThis[0][0]*pvIn->x + mfThis[1][0]*pvIn->y
               + mfThis[2][0]*pvIn->z + mfThis[3][0];
   pvOut->y = mfThis[0][1]*pvIn->x + mfThis[1][1]*pvIn->y
               + mfThis[2][1]*pvIn->z + mfThis[3][1];
   pvOut->z = mfThis[0][2]*pvIn->x + mfThis[1][2]*pvIn->y
               + mfThis[2][2]*pvIn->z + mfThis[3][2];
}
