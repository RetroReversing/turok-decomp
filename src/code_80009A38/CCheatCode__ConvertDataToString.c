#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef unsigned short sa_u16;
extern sa_u16 D_800B8190[32];
extern char D_800B81D0[32];
extern int D_800B81F0;
extern void CCheatCode__ConvertDataToString(void) ;
void CCheatCode__ConvertDataToString(void);
/* Convert the data to a printable string */ void CCheatCode__ConvertDataToString(void){
 sa_u16 dcount = 0;
 sa_u16 scount = 0;
 sa_u16 byte ;
 int nibble = 0 ;
 int working = 1 ;
 while (working)
 {
  byte = D_800B8190[dcount] ;
  /* convert to nibble */ switch (nibble)
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
  /* move along in nibbles, move along data if nibble 0 */ nibble++ ;
  if (nibble >3)
  {
   nibble = 0 ;
   dcount++ ;
  }
  /* advance string position and check for end */ scount++ ;
  if (scount >= D_800B81F0)
   working = 0 ;
 }
}
