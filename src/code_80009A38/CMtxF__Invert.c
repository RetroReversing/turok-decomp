#include "common.h"

typedef float CMtxF[4][4];
extern void CMtxF__Copy(CMtxF mfThis, CMtxF mfSource);
extern void CMtxF__Invert(CMtxF mfThis, CMtxF mfIn);
void CMtxF__Copy(CMtxF mfThis, CMtxF mfSource);
void CMtxF__Invert(CMtxF mfThis, CMtxF mfIn);
/* Invert an affine 4x4 matrix, copying input if its 3x3 determinant is zero. */
void CMtxF__Invert(CMtxF mfThis, CMtxF mfIn){
 float det, invDet;





   det = mfIn[0][0]*mfIn[1][1]*mfIn[2][2] - mfIn[0][0]*mfIn[2][1]*mfIn[1][2]
       - mfIn[1][0]*mfIn[0][1]*mfIn[2][2] + mfIn[1][0]*mfIn[2][1]*mfIn[0][2]
       + mfIn[2][0]*mfIn[0][1]*mfIn[1][2] - mfIn[2][0]*mfIn[1][1]*mfIn[0][2];
   if (det == 0)
   {

  CMtxF__Copy(mfThis, mfIn);
   }
   else
   {
  invDet = 1/det;
    mfThis[0][0] = (mfIn[1][1]*mfIn[2][2]-mfIn[2][1]*mfIn[1][2])*invDet;
    mfThis[0][1] = -(mfIn[0][1]*mfIn[2][2]-mfIn[2][1]*mfIn[0][2])*invDet;
    mfThis[0][2] = (mfIn[0][1]*mfIn[1][2]-mfIn[1][1]*mfIn[0][2])*invDet;
    mfThis[0][3] = 0;
    mfThis[1][0] = (-mfIn[1][0]*mfIn[2][2]+mfIn[2][0]*mfIn[1][2])*invDet;
    mfThis[1][1] = (mfIn[0][0]*mfIn[2][2]-mfIn[2][0]*mfIn[0][2])*invDet;
    mfThis[1][2] = -(mfIn[0][0]*mfIn[1][2]-mfIn[1][0]*mfIn[0][2])*invDet;
    mfThis[1][3] = 0;
    mfThis[2][0] = -(-mfIn[1][0]*mfIn[2][1]+mfIn[2][0]*mfIn[1][1])*invDet;
    mfThis[2][1] = (-mfIn[0][0]*mfIn[2][1]+mfIn[2][0]*mfIn[0][1])*invDet;
    mfThis[2][2] = -(-mfIn[0][0]*mfIn[1][1]+mfIn[1][0]*mfIn[0][1])*invDet;
    mfThis[2][3] = 0;
    mfThis[3][0] = (-mfIn[1][0]*mfIn[2][1]*mfIn[3][2]+mfIn[1][0]*mfIn[2][2]*mfIn[3][1]
      +mfIn[2][0]*mfIn[1][1]*mfIn[3][2]-mfIn[2][0]*mfIn[1][2]*mfIn[3][1]
      -mfIn[3][0]*mfIn[1][1]*mfIn[2][2]+mfIn[3][0]*mfIn[2][1]*mfIn[1][2])*invDet;
    mfThis[3][1] = (mfIn[0][0]*mfIn[2][1]*mfIn[3][2]-mfIn[0][0]*mfIn[2][2]*mfIn[3][1]
      -mfIn[2][0]*mfIn[0][1]*mfIn[3][2]+mfIn[2][0]*mfIn[0][2]*mfIn[3][1]
      +mfIn[3][0]*mfIn[0][1]*mfIn[2][2]-mfIn[3][0]*mfIn[2][1]*mfIn[0][2])*invDet;
    mfThis[3][2] = -(mfIn[0][0]*mfIn[1][1]*mfIn[3][2]-mfIn[0][0]*mfIn[1][2]*mfIn[3][1]
      -mfIn[1][0]*mfIn[0][1]*mfIn[3][2]+mfIn[1][0]*mfIn[0][2]*mfIn[3][1]
      +mfIn[3][0]*mfIn[0][1]*mfIn[1][2]-mfIn[3][0]*mfIn[1][1]*mfIn[0][2])*invDet;
    mfThis[3][3] = 1;
   }
}
