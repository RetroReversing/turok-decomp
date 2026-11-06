#include "common.h"

typedef float CMtxF[4][4];
extern void CMtxF__PreMult3DSToU64(CMtxF mfThis) ;
void CMtxF__PreMult3DSToU64(CMtxF mfThis);
void CMtxF__PreMult3DSToU64(CMtxF mfThis){
 float t ;
 t = mfThis[1][0] ; mfThis[1][0] = mfThis[2][0] ; mfThis[2][0] = t ; ;
 t = mfThis[1][1] ; mfThis[1][1] = mfThis[2][1] ; mfThis[2][1] = t ; ;
 t = mfThis[1][2] ; mfThis[1][2] = mfThis[2][2] ; mfThis[2][2] = t ; ;
}
