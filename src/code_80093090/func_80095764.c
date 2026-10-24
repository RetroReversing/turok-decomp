#include "common.h"

extern void func_80095418( unsigned long num );
extern void D_80095060(int r,int g,int b);
extern void func_800955BC(const char *s);
void D_80095060( int r, int g, int b);
void func_80095418( unsigned long num );
void func_800955BC(const char *s);
void func_80095764(char *s1, unsigned int v1,
         char *s2, unsigned int v2);
void func_80095764(char *s1, unsigned int v1,
         char *s2, unsigned int v2){
 func_800955BC(s1);
 func_800955BC(": ");
 func_80095418(v1);
 func_800955BC("   ");
 D_80095060(240, 240, 160);
 func_800955BC(s2);
 func_800955BC(": ");
 func_80095418(v2);
 D_80095060(160, 160, 160);
 func_800955BC("\n");
}
