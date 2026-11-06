#include "common.h"

extern char D_800F68A8[]; extern char D_800F68AC[]; extern char D_800F68B0[]; extern char D_800F68B4[]; typedef unsigned long sa_u32;
extern void draw_uint( unsigned long num );
extern void draw_puts(const char *s);
typedef struct {
 sa_u32 mask;
 sa_u32 value;
 char *string;
} regDesc_t;
void draw_uint( unsigned long num );
void draw_puts(const char *s);
void printRegisterScr(sa_u32 regValue, char *regName, regDesc_t *regDesc);
void printRegisterScr(sa_u32 regValue, char *regName, regDesc_t *regDesc){
 int first = 1;
 draw_puts(regName);
 draw_puts(D_800F68A8);
 draw_uint(regValue);
 draw_puts(D_800F68AC);
 while (regDesc->mask != 0) {
  if ((regValue & regDesc->mask) == regDesc->value) {
   if (first)
    first = 0;
   else
    draw_puts(D_800F68B0);
   draw_puts(regDesc->string);
  }
  regDesc++;
 }
 draw_puts(D_800F68B4);
}
