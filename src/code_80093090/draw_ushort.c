#include "common.h"

extern void draw_ushort( unsigned short num );
extern void draw_hex(int code);
void draw_ushort( unsigned short num );
void draw_hex( int num );
void draw_ushort( unsigned short num ){
  int i;
  for(i = 0 ; i < 2; i++)
    draw_hex( num >> (8 * (1 - i)) );
}
