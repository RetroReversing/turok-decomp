#include "common.h"

extern char D_800F68B8[]; extern void draw_uint( unsigned long num );
extern void draw_puts(const char *s);
void draw_uint( unsigned long num );
void draw_puts(const char *s);
void printRegisterRow(char *s1, unsigned int v1,
        char *s2, unsigned int v2,
        char *s3, unsigned int v3);
#line 1000
void printRegisterRow(char *s1, unsigned int v1,
        char *s2, unsigned int v2,
        char *s3, unsigned int v3){
 draw_puts(s1);
 draw_puts((&D_800F68B8[0]));
 draw_uint(v1);
 draw_puts((&D_800F68B8[4]));
 draw_puts(s2);
 draw_puts((&D_800F68B8[8]));
 draw_uint(v2);
 draw_puts((&D_800F68B8[12]));
 draw_puts(s3);
 draw_puts((&D_800F68B8[16]));
 draw_uint(v3);
 draw_puts((&D_800F68B8[20]));
}
