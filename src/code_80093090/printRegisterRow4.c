#include "common.h"

extern void draw_uint( unsigned long num );
extern void draw_puts(const char *s);
void draw_uint( unsigned long num );
void draw_puts(const char *s);
void printRegisterRow4(char *s1, unsigned int v1,
         char *s2, unsigned int v2,
         char *s3, unsigned int v3,
         char *s4, unsigned int v4);
void printRegisterRow4(char *s1, unsigned int v1,
         char *s2, unsigned int v2,
         char *s3, unsigned int v3,
         char *s4, unsigned int v4){
 draw_puts(s1);
 draw_puts(": ");
 draw_uint(v1);
 draw_puts("   ");
 draw_puts(s2);
 draw_puts(": ");
 draw_uint(v2);
 draw_puts("   ");
 draw_puts(s3);
 draw_puts(": ");
 draw_uint(v3);
 draw_puts("   ");
 draw_puts(s4);
 draw_puts(": ");
 draw_uint(v4);
 draw_puts("\n");
}
