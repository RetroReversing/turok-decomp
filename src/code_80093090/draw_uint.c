#include "common.h"

extern void draw_uint( unsigned long num );
extern void draw_hex(int code);
void draw_uint( unsigned long num );
void draw_hex( int num );
void draw_uint( unsigned long num ){
  int i;
  for(i = 0 ; i < 4; i++)
    draw_hex( num >> (8 * (3 - i)) );
}
