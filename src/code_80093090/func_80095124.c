#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
extern int D_80130D70;
extern void func_80095124(int code);
extern sa_u8 D_800EDA70[0x5f][16];
extern sa_u16 *D_80130D74;
extern unsigned int D_800EE060;
extern unsigned int D_800EE064;
extern sa_u16 D_80130D78;
extern sa_u16 D_800EE068;
void func_80095124( int in_code );
void func_80095124( int in_code ){
  /* Draw one fault-screen glyph, interpreting control characters as cursor movement. */
  int i,j;
  int code;
  switch( in_code )
    {
    case '\n':
      D_800EE060 = 7;
      if( ++D_800EE064 >= (240*2/16 - 3) )
 {
   D_800EE064 = 3;
 }
      break;
    case '\r':
      D_800EE060 = 7;
      break;
    case '\t':
                   D_800EE060 += 8;
      if( D_800EE060 >= D_80130D70 )
 {
   D_800EE060 = 7;
   if( ++D_800EE064 >= (240*2/16 - 3) )
     {
       D_800EE064 = 3;
     }
 }
      break;
    case '\f':
      D_800EE064 = 3;
      D_800EE060 = 7;
      break;
    default:
      if( 0 > ( code = in_code - 0x20 ))
 code = 0x1f;
      else if( 0x5f < code)
 code = 0x1f;
      for(i = 0 ; i < 16 ; i++)
 for(j = 0 ; j < 8 ; j++)
   D_80130D74[ (D_800EE064 * 16 + i) * 320*2 +
       (D_800EE060 * 8 + j) ]
         = ( ((D_800EDA70[code][i]>>(7-j)) & 0x01)? D_80130D78:D_800EE068);
      if( ++D_800EE060 >= D_80130D70 )
 {
   D_800EE060 = 7;
   if( ++D_800EE064 >= (240*2/16 - 3) )
     {
       D_800EE064=3;
     }
 }
      break;
    }
}
