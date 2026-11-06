#include "common.h"

extern void draw_uint( unsigned long num );
extern void D_80095060(int r,int g,int b);
extern void draw_puts(const char *s);
void D_80095060( int r, int g, int b);
void draw_uint( unsigned long num );
void draw_puts(const char *s);
void printRegisterRow2(char *s1, unsigned int v1,
         char *s2, unsigned int v2);
void printRegisterRow2(char *s1, unsigned int v1,
         char *s2, unsigned int v2){
 draw_puts(s1);
 draw_puts(": ");
 draw_uint(v1);
 draw_puts("   ");
 D_80095060(240, 240, 160);
 draw_puts(s2);
 draw_puts(": ");
 draw_uint(v2);
 D_80095060(160, 160, 160);
 draw_puts("\n");
}
