#include "common.h"

typedef unsigned short sa_u16;
extern sa_u16 D_800B8190[32];
extern char D_800B81D0[32];
extern int D_800B81F0;
extern void func_80010158(void) ;
void func_80010158(void);
void func_80010158(void){
 sa_u16 dcount = 0;
 sa_u16 scount = 0;
 sa_u16 byte ;
 sa_u16 data ;
 int nibble = 0 ;
 int working = 1 ;
 while (working)
 {
  data = D_800B81D0[scount] & 0x0f ;
  switch (nibble)
  {
   case 0:
    byte = (data<<12) ;
    break ;
   case 1:
    byte |= (data<<8) ;
    break ;
   case 2:
    byte |= (data<<4) ;
    break ;
   case 3:
    byte |= (data) ;
    break ;
  }
  D_800B8190[dcount] = byte ;
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
