#include "common.h"

typedef float CMtxF[4][4];
extern void func_80015910(CMtxF mfThis, CMtxF mfLeft, CMtxF mfRight);
void func_80015910(CMtxF mfThis, CMtxF mfLeft, CMtxF mfRight);
/* Multiply two 4x4 float matrices and store the product in mfThis. */
void func_80015910(CMtxF mfThis, CMtxF mfLeft, CMtxF mfRight){
 mfThis[0][0] = (mfLeft[0][0] * mfRight[0][0]) + (mfLeft[0][1] * mfRight[1][0]) + (mfLeft[0][2] * mfRight[2][0]) + (mfLeft[0][3] * mfRight[3][0]) ;
 mfThis[0][1] = (mfLeft[0][0] * mfRight[0][1]) + (mfLeft[0][1] * mfRight[1][1]) + (mfLeft[0][2] * mfRight[2][1]) + (mfLeft[0][3] * mfRight[3][1]) ;
 mfThis[0][2] = (mfLeft[0][0] * mfRight[0][2]) + (mfLeft[0][1] * mfRight[1][2]) + (mfLeft[0][2] * mfRight[2][2]) + (mfLeft[0][3] * mfRight[3][2]) ;
 mfThis[0][3] = (mfLeft[0][0] * mfRight[0][3]) + (mfLeft[0][1] * mfRight[1][3]) + (mfLeft[0][2] * mfRight[2][3]) + (mfLeft[0][3] * mfRight[3][3]) ;
 mfThis[1][0] = (mfLeft[1][0] * mfRight[0][0]) + (mfLeft[1][1] * mfRight[1][0]) + (mfLeft[1][2] * mfRight[2][0]) + (mfLeft[1][3] * mfRight[3][0]) ;
 mfThis[1][1] = (mfLeft[1][0] * mfRight[0][1]) + (mfLeft[1][1] * mfRight[1][1]) + (mfLeft[1][2] * mfRight[2][1]) + (mfLeft[1][3] * mfRight[3][1]) ;
 mfThis[1][2] = (mfLeft[1][0] * mfRight[0][2]) + (mfLeft[1][1] * mfRight[1][2]) + (mfLeft[1][2] * mfRight[2][2]) + (mfLeft[1][3] * mfRight[3][2]) ;
 mfThis[1][3] = (mfLeft[1][0] * mfRight[0][3]) + (mfLeft[1][1] * mfRight[1][3]) + (mfLeft[1][2] * mfRight[2][3]) + (mfLeft[1][3] * mfRight[3][3]) ;
 mfThis[2][0] = (mfLeft[2][0] * mfRight[0][0]) + (mfLeft[2][1] * mfRight[1][0]) + (mfLeft[2][2] * mfRight[2][0]) + (mfLeft[2][3] * mfRight[3][0]) ;
 mfThis[2][1] = (mfLeft[2][0] * mfRight[0][1]) + (mfLeft[2][1] * mfRight[1][1]) + (mfLeft[2][2] * mfRight[2][1]) + (mfLeft[2][3] * mfRight[3][1]) ;
 mfThis[2][2] = (mfLeft[2][0] * mfRight[0][2]) + (mfLeft[2][1] * mfRight[1][2]) + (mfLeft[2][2] * mfRight[2][2]) + (mfLeft[2][3] * mfRight[3][2]) ;
 mfThis[2][3] = (mfLeft[2][0] * mfRight[0][3]) + (mfLeft[2][1] * mfRight[1][3]) + (mfLeft[2][2] * mfRight[2][3]) + (mfLeft[2][3] * mfRight[3][3]) ;
 mfThis[3][0] = (mfLeft[3][0] * mfRight[0][0]) + (mfLeft[3][1] * mfRight[1][0]) + (mfLeft[3][2] * mfRight[2][0]) + (mfLeft[3][3] * mfRight[3][0]) ;
 mfThis[3][1] = (mfLeft[3][0] * mfRight[0][1]) + (mfLeft[3][1] * mfRight[1][1]) + (mfLeft[3][2] * mfRight[2][1]) + (mfLeft[3][3] * mfRight[3][1]) ;
 mfThis[3][2] = (mfLeft[3][0] * mfRight[0][2]) + (mfLeft[3][1] * mfRight[1][2]) + (mfLeft[3][2] * mfRight[2][2]) + (mfLeft[3][3] * mfRight[3][2]) ;
 mfThis[3][3] = (mfLeft[3][0] * mfRight[0][3]) + (mfLeft[3][1] * mfRight[1][3]) + (mfLeft[3][2] * mfRight[2][3]) + (mfLeft[3][3] * mfRight[3][3]) ;
}
