#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef signed char sa_s8;
typedef struct {
 sa_u16 button;
 sa_s8 stick_x;
 sa_s8 stick_y;
 sa_u8 errno;
} OSContPad;
extern OSContPad D_80119990[];
extern OSContPad D_801199C8 ;
extern void ReadPlayerController(void) ;
extern int D_800F9E40;
extern int CAttractDemo__StartOfRecordingDemo(void) ;
extern OSContPad D_80119990[4];
extern OSContPad D_801199C8 ;
void ReadPlayerController(void);
void ReadPlayerController(void){
 if (D_800F9E40 < 0)
 {
  D_801199C8.button = 0 ;
  D_801199C8.stick_x = 0 ;
  D_801199C8.stick_y = 0 ;
                                        ;
  return;
 }
 D_801199C8 = D_80119990[D_800F9E40] ;
 if (CAttractDemo__StartOfRecordingDemo())
 {
  D_801199C8.button = 0 ;
  D_801199C8.stick_x = 0 ;
  D_801199C8.stick_y = 0 ;
 }
}
