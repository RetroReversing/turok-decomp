#include "common.h"

extern void func_80095418( unsigned long num );
extern void func_800955BC(const char *s);
void func_80095418( unsigned long num );
void func_800955BC(const char *s);
void func_800957F4(char *s1, unsigned int v1,
         char *s2, unsigned int v2,
         char *s3, unsigned int v3,
         char *s4, unsigned int v4);
void func_800957F4(char *s1, unsigned int v1,
         char *s2, unsigned int v2,
         char *s3, unsigned int v3,
         char *s4, unsigned int v4){
 func_800955BC(s1);
 func_800955BC(": ");
 func_80095418(v1);
 func_800955BC("   ");
 func_800955BC(s2);
 func_800955BC(": ");
 func_80095418(v2);
 func_800955BC("   ");
 func_800955BC(s3);
 func_800955BC(": ");
 func_80095418(v3);
 func_800955BC("   ");
 func_800955BC(s4);
 func_800955BC(": ");
 func_80095418(v4);
 func_800955BC("\n");
}
