#include "common.h"

extern char D_800F68B8[]; extern void func_80095418( unsigned long num );
extern void func_800955BC(const char *s);
void func_80095418( unsigned long num );
void func_800955BC(const char *s);
void func_800956CC(char *s1, unsigned int v1,
        char *s2, unsigned int v2,
        char *s3, unsigned int v3);
#line 1000
void func_800956CC(char *s1, unsigned int v1,
        char *s2, unsigned int v2,
        char *s3, unsigned int v3){
 func_800955BC(s1);
 func_800955BC((&D_800F68B8[0]));
 func_80095418(v1);
 func_800955BC((&D_800F68B8[4]));
 func_800955BC(s2);
 func_800955BC((&D_800F68B8[8]));
 func_80095418(v2);
 func_800955BC((&D_800F68B8[12]));
 func_800955BC(s3);
 func_800955BC((&D_800F68B8[16]));
 func_80095418(v3);
 func_800955BC((&D_800F68B8[20]));
}
