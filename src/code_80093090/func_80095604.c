#include "common.h"

extern char D_800F68A8[]; extern char D_800F68AC[]; extern char D_800F68B0[]; extern char D_800F68B4[]; typedef unsigned long sa_u32;
extern void func_80095418( unsigned long num );
extern void func_800955BC(const char *s);
typedef struct {
 sa_u32 mask;
 sa_u32 value;
 char *string;
} regDesc_t;
void func_80095418( unsigned long num );
void func_800955BC(const char *s);
void func_80095604(sa_u32 regValue, char *regName, regDesc_t *regDesc);
void func_80095604(sa_u32 regValue, char *regName, regDesc_t *regDesc){
 int first = 1;
 func_800955BC(regName);
 func_800955BC(D_800F68A8);
 func_80095418(regValue);
 func_800955BC(D_800F68AC);
 while (regDesc->mask != 0) {
  if ((regValue & regDesc->mask) == regDesc->value) {
   if (first)
    first = 0;
   else
    func_800955BC(D_800F68B0);
   func_800955BC(regDesc->string);
  }
  regDesc++;
 }
 func_800955BC(D_800F68B4);
}
