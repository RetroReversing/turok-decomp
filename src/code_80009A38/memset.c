#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern void memset(void *pDest, unsigned char Val, int Count);
void memset(void *pDest, unsigned char Val, int Count);
void memset(void *pDest, unsigned char Val, int Count){
 int i;
 /* TRACE3("memset(%x, %x, %x)\r\n", pDest, Val, Count); */ for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = Val;
}
