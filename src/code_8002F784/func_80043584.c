#include "common.h"

extern unsigned long D_800B9878;
extern float D_800B987C[5];
extern void func_8004353C(float *pVar) ;
extern void func_80043584(void) ;
void func_8004353C(float *pVar);
void func_80043584(void);
void func_80043584(void){
 float Trans, Color ;
 func_8004353C(&D_800B987C[0]) ;
 func_8004353C(&D_800B987C[1]) ;
 func_8004353C(&D_800B987C[2]) ;
 func_8004353C(&D_800B987C[3]) ;
 func_8004353C(&D_800B987C[4]) ;
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
