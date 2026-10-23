#include "common.h"

typedef long Mtx_t[4][4];
typedef union {
    Mtx_t m;
    long long int force_structure_alignment;
} Mtx;
typedef float CMtxF[4][4];
extern void func_80012290(CMtxF mfThis, Mtx *m) ;
void func_80012290(CMtxF mfThis, Mtx *m);
void func_80012290(CMtxF mfThis, Mtx *m){
 signed long e1,e2 ;
 signed long *ai,*af ;
 ai=(signed long *)&m->m[0][0] ;
 af=(signed long *)&m->m[2][0] ;
 e1=(long)((mfThis[0][0]) * (float)0x00010000) ;
 e2=(long)((mfThis[0][1]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[0][2]) * (float)0x00010000) ;
 e2=(long)((mfThis[0][3]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[1][0]) * (float)0x00010000) ;
 e2=(long)((mfThis[1][1]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[1][2]) * (float)0x00010000) ;
 e2=(long)((mfThis[1][3]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[2][0]) * (float)0x00010000) ;
 e2=(long)((mfThis[2][1]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[2][2]) * (float)0x00010000) ;
 e2=(long)((mfThis[2][3]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[3][0]) * (float)0x00010000) ;
 e2=(long)((mfThis[3][1]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
 e1=(long)((mfThis[3][2]) * (float)0x00010000) ;
 e2=(long)((mfThis[3][3]) * (float)0x00010000) ;
 *(ai++) = ( e1 & 0xffff0000 ) | ((e2 >> 16)&0xffff) ;
 *(af++) = ((e1 << 16) & 0xffff0000) | (e2 & 0xffff) ;
}
