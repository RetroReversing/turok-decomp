#include "common.h"

extern void memset(void *pDest, unsigned char Val, int Count);
void memset(void *pDest, unsigned char Val, int Count);
void memset(void *pDest, unsigned char Val, int Count){
 int i;
 for (i=0; i<Count; i++)
  ((unsigned char*)pDest)[i] = Val;
}
