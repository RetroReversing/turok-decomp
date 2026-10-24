#include "common.h"

typedef float CMtxF[4][4];
extern void func_80012820(CMtxF mfThis) ;
void func_80012820(CMtxF mfThis);
void func_80012820(CMtxF mfThis){
 float t ;
 t = mfThis[0][1] ; mfThis[0][1] = mfThis[0][2] ; mfThis[0][2] = t ; ;
 t = mfThis[1][1] ; mfThis[1][1] = mfThis[1][2] ; mfThis[1][2] = t ; ;
 t = mfThis[2][1] ; mfThis[2][1] = mfThis[2][2] ; mfThis[2][2] = t ; ;
 t = mfThis[3][1] ; mfThis[3][1] = mfThis[3][2] ; mfThis[3][2] = t ; ;
}
