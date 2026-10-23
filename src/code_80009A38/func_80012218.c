#include "common.h"

extern void func_80012218(void *pDest, void *pSrc, int Count);
void func_80012218(void *pDest, void *pSrc, int Count);
void func_80012218(void *pDest, void *pSrc, int Count){
 int i;
 for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = ((unsigned char*)pSrc)[i];
}
