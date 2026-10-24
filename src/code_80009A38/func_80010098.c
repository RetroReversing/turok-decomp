#include "common.h"

typedef unsigned short sa_u16;
extern sa_u16 D_800B8190[32];
extern char D_800B81D0[32];
extern int D_800B81F0;
extern void func_80010098(void) ;
void func_80010098(void);
void func_80010098(void){
 sa_u16 dcount = 0;
 sa_u16 scount = 0;
 sa_u16 byte ;
 int nibble = 0 ;
 int working = 1 ;
 while (working)
 {
  byte = D_800B8190[dcount] ;
  switch (nibble)
  {
   case 0:
    byte >>= 12 ;
    break ;
   case 1:
    byte >>= 8 ;
    break ;
   case 2:
    byte >>= 4 ;
    break ;
  }
  byte &= 0x0f ;
  D_800B81D0[scount] = byte ;
  nibble++ ;
  if (nibble >3)
  {
   nibble = 0 ;
   dcount++ ;
  }
  scount++ ;
  if (scount >= D_800B81F0)
   working = 0 ;
 }
}
