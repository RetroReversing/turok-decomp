#include "common.h"

typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
typedef float sa_f32;
typedef double sa_f64;
typedef union {
    struct {
        sa_f32 f_odd;
        sa_f32 f_even;
    } f;
    sa_f64 d;
} __OSfp;
typedef struct {
    sa_u64 at, v0, v1, a0, a1, a2, a3;
    sa_u64 t0, t1, t2, t3, t4, t5, t6, t7;
    sa_u64 s0, s1, s2, s3, s4, s5, s6, s7;
    sa_u64 t8, t9;
    sa_u64 gp, sp, sa_s8, ra;
    sa_u64 lo, hi;
    sa_u32 sr, pc, cause, badvaddr, rcp;
    sa_u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
extern char D_80001300[];
extern char D_800B6990[];
extern void func_80095418( unsigned long num );
extern void D_80095060(int r,int g,int b);
extern void func_800955BC(const char *s);
extern unsigned int D_800EE060;
extern unsigned int D_800EE064;
void D_80095060( int r, int g, int b);
void func_80095418( unsigned long num );
void func_800955BC(const char *s);
void func_800958B4(void *pStack, int StackSize, __OSThreadContext *pTc);
void func_800958B4(void *pStack, int StackSize, __OSThreadContext *pTc){
 /* Display return-address candidates beside raw stack words on the fault screen. */
 int i;
 sa_u32 *pStackEntry;
 sa_u32 *pTopStack = (sa_u32*) ((sa_u32) pStack + StackSize);
 for (i=8; i<11; i++)
 {
  D_800EE060 = 55 - 1;
  D_800EE064 = i;
  func_800955BC("                   ");
 }
 D_800EE060 = 55;
 D_800EE064 = 3;
 D_80095060(240, 240, 160);
 func_800955BC(" call");
 D_80095060(160, 160, 160);
 func_800955BC("      raw");
 D_800EE060 = 55;
 D_800EE064 = 3 + 1;
 D_80095060(240, 240, 160);
 func_800955BC(" stack");
 D_80095060(160, 160, 160);
 func_800955BC("     stack");
 D_80095060(240, 240, 160);
 D_800EE060 = 55;
 D_800EE064 = 3 + 3;
 func_80095418(pTc->pc);
 i = 1;
 pStackEntry = (sa_u32*) pTc->sp;
 while ((pStackEntry < pTopStack) && (i < 21))
 {
  if ((*pStackEntry >= (sa_u32) D_80001300) && (*pStackEntry < (sa_u32) D_800B6990))
  {
   D_800EE060 = 55;
   D_800EE064 = 3 + 3 + i;
   func_80095418(*pStackEntry);
   i++;
  }
  pStackEntry++;
 }
 D_80095060(160, 160, 160);
 i = 0;
 pStackEntry = (sa_u32*) pTc->sp;
 while ((pStackEntry < pTopStack) && (i < 21))
 {
  D_800EE060 = 55 + 10;
  D_800EE064 = 3 + 3 + i;
  func_80095418(*pStackEntry);
  i++;
  pStackEntry++;
 }
}
