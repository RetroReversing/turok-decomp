#include "common.h"

extern void func_800121B8(void *pDest, unsigned char Val, int Count);
void func_800121B8(void *pDest, unsigned char Val, int Count);
void func_800121B8(void *pDest, unsigned char Val, int Count){
 int i;
 for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = Val;
}
