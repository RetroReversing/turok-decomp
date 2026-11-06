#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern void r_memcpy(void *pDest, void *pSrc, int Count);
void r_memcpy(void *pDest, void *pSrc, int Count);
void r_memcpy(void *pDest, void *pSrc, int Count){
 int i;
 /* TRACE3("memcpy(%x, %x, %x)\r\n", pDest, pSrc, Count); */ for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = ((unsigned char*)pSrc)[i];
}
