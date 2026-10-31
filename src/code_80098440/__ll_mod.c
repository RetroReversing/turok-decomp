#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
s64 __ll_mod(s64 a,s64 b) {
 s64 r;
 r=a%b;
 if((r<0 && b>0)||(r>0 && b<0)) r+=b;
 return r;
}

