#include "common.h"

extern void SetBitStreamFlag(unsigned char Bits[], int nBit, int Set);
void SetBitStreamFlag(unsigned char Bits[], int nBit, int Set);
void SetBitStreamFlag(unsigned char Bits[], int nBit, int Set){
 int nByte, nByteBit;
 unsigned char mask;
 nByte = nBit/8;
 nByteBit = nBit%8;
 mask = 1 << nByteBit;
 if (Set)
  Bits[nByte] |= mask;
 else
  Bits[nByte] &= ~mask;
}
