#include "common.h"

void func_8007CC90(unsigned char Reduce,
          unsigned char inR, unsigned char inG, unsigned char inB,
          unsigned char *pOutR, unsigned char *pOutG, unsigned char *pOutB);
void func_8007CC90(unsigned char Reduce,
          unsigned char inR, unsigned char inG, unsigned char inB,
          unsigned char *pOutR, unsigned char *pOutG, unsigned char *pOutB){
 int onemr;
 if (Reduce)
 {
  onemr = 255 - Reduce;
  *pOutR = inR*onemr/255;
  *pOutG = inG*onemr/255;
  *pOutB = inB*onemr/255;
 }
 else
 {
  *pOutR = inR;
  *pOutG = inG;
  *pOutB = inB;
  return;
 }
}
