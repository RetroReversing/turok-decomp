#include "common.h"

extern unsigned long D_800B9878;
extern float D_800B987C[5];
extern void RangeCheckFxVar(float *pVar) ;
extern void PrepareDrawFxVars(void) ;
void RangeCheckFxVar(float *pVar);
void PrepareDrawFxVars(void);
void PrepareDrawFxVars(void){
 float Trans, Color ;
 RangeCheckFxVar(&D_800B987C[0]) ;
 RangeCheckFxVar(&D_800B987C[1]) ;
 RangeCheckFxVar(&D_800B987C[2]) ;
 RangeCheckFxVar(&D_800B987C[3]) ;
 RangeCheckFxVar(&D_800B987C[4]) ;
 Color = D_800B987C[3] ;
 Trans = D_800B987C[4] ;
 if ((Trans == 255) && (Color == 0))
  D_800B9878 = 0 ;
 else
 if ((Trans != 255) && (Color == 0))
 {
  D_800B9878 = 1 ;
  D_800B987C[3] = D_800B987C[4] ;
 }
 else
 if ((Trans == 255) && (Color != 0))
  D_800B9878 = 3 ;
 else
 if ((Trans != 255) && (Color != 0))
  D_800B9878 = 6 ;
}
