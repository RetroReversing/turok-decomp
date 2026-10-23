#include "common.h"

typedef float CMtxF[4][4];
extern void func_800127A0(CMtxF mfThis, CMtxF mfSource) ;
void func_800127A0(CMtxF mfThis, CMtxF mfSource);
void func_800127A0(CMtxF mfThis, CMtxF mfSource){
 mfThis[0][0] = mfSource[0][0] ;
 mfThis[0][1] = mfSource[0][2] ;
 mfThis[0][2] = mfSource[0][1] ;
 mfThis[1][0] = mfSource[1][0] ;
 mfThis[1][1] = mfSource[1][2] ;
 mfThis[1][2] = mfSource[1][1] ;
 mfThis[2][0] = mfSource[2][0] ;
 mfThis[2][1] = mfSource[2][2] ;
 mfThis[2][2] = mfSource[2][1] ;
 mfThis[3][0] = mfSource[3][0] ;
 mfThis[3][1] = mfSource[3][2] ;
 mfThis[3][2] = mfSource[3][1] ;
 mfThis[0][3] = mfThis[1][3] = mfThis[2][3] = 0 ; mfThis[3][3] = 1 ;
}
