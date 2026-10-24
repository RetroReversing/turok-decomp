#include "common.h"

extern void func_80083D94(unsigned char Bits[], int nBit, int Set);
void func_80083D94(unsigned char Bits[], int nBit, int Set);
void func_80083D94(unsigned char Bits[], int nBit, int Set){
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
