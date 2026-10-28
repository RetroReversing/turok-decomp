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
 /* Convert a float matrix to the N64 split integer and fraction fixed-point layout. */
 signed long fixedFirst,fixedSecond ;
 signed long *integerWords,*fractionWords ;
 integerWords=(signed long *)&m->m[0][0] ;
 fractionWords=(signed long *)&m->m[2][0] ;
 fixedFirst=(long)((mfThis[0][0]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[0][1]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[0][2]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[0][3]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[1][0]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[1][1]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[1][2]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[1][3]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[2][0]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[2][1]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[2][2]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[2][3]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[3][0]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[3][1]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
 fixedFirst=(long)((mfThis[3][2]) * (float)0x00010000) ;
 fixedSecond=(long)((mfThis[3][3]) * (float)0x00010000) ;
 *(integerWords++) = ( fixedFirst & 0xffff0000 ) | ((fixedSecond >> 16)&0xffff) ;
 *(fractionWords++) = ((fixedFirst << 16) & 0xffff0000) | (fixedSecond & 0xffff) ;
}
