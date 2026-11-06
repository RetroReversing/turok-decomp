#include "common.h"

extern void r_memcpy(void *pDest, void *pSrc, int Count);
void r_memcpy(void *pDest, void *pSrc, int Count);
void r_memcpy(void *pDest, void *pSrc, int Count){
 int i;
 for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = ((unsigned char*)pSrc)[i];
}
