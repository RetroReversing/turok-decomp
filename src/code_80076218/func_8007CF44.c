#include "common.h"

void func_8007CF44(signed char Offset,
      unsigned char inR, unsigned char inG, unsigned char inB,
      unsigned char *pOutR, unsigned char *pOutG, unsigned char *pOutB);
void func_8007CF44(signed char Offset,
      unsigned char inR, unsigned char inG, unsigned char inB,
      unsigned char *pOutR, unsigned char *pOutG, unsigned char *pOutB){
 int l, m, r,
   or, og, ob,
   oldMax, maxColor;
 if (Offset)
 {
  if (Offset < 0)
   m = ((0) > (((int)Offset) + 85) ? (0) : (((int)Offset) + 85))*255/85;
  else
   m = ((0) > (85 - ((int)Offset)) ? (0) : (85 - ((int)Offset)))*255/85;
  if (Offset < -85)
   l = (170 + ((int)Offset))*255/85;
  else
   l = ((0) > (-((int)Offset)) ? (0) : (-((int)Offset)))*255/85;
  if (Offset > 85)
   r = (170 - ((int)Offset))*255/85;
  else
   r = ((0) > (((int)Offset)) ? (0) : (((int)Offset)))*255/85;
  or = l*inB + m*inR + r*inG;
  og = l*inR + m*inG + r*inB;
  ob = l*inG + m*inB + r*inR;
  oldMax = ((inR) > (((inG) > (inB) ? (inG) : (inB))) ? (inR) : (((inG) > (inB) ? (inG) : (inB))));
  maxColor = ((or) > (((og) > (ob) ? (og) : (ob))) ? (or) : (((og) > (ob) ? (og) : (ob))));
  if (maxColor)
  {
   *pOutR = (unsigned char) (or*oldMax/maxColor);
   *pOutG = (unsigned char) (og*oldMax/maxColor);
   *pOutB = (unsigned char) (ob*oldMax/maxColor);
  }
  else
  {
   *pOutR = inR;
   *pOutG = inG;
   *pOutB = inB;
  }
 }
 else
 {
  *pOutR = inR;
  *pOutG = inG;
  *pOutB = inB;
  return;
 }
}
