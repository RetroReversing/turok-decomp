#include "common.h"

extern void draw_char(int code);
extern void draw_decimal(int num);
extern void draw_puts(const char *s);
void draw_char( int in_code );
void draw_decimal(int num);
void draw_puts(const char *s);
void draw_decimal(int num){
 char buffer[16],
    *pc;
 int current;
 if (num < 0)
 {
  draw_char('-');
  current = -num;
 }
 else
 {
  current = num;
 }
 pc = &buffer[16 - 1];
 *pc = 0;
 do
 {
  *(--pc) = current%10 + '0';
  current /= 10;
 } while (current);
 draw_puts(pc);
}
