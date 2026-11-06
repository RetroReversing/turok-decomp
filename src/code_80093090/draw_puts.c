#include "common.h"

extern void draw_char(int code);
extern void draw_puts(const char *s);
void draw_char( int in_code );
void draw_puts(const char *s);
void draw_puts(const char *s){
  while( *s )
    draw_char( *s++ );
}
