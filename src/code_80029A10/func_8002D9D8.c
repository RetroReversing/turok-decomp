#include "common.h"

static __inline u32 Size(u32 **p){return (*p)[0]*(*p)[1]+8;} void func_8002D9D8(u32 **p,u32 **out,u32 *sz){*out=*p;*sz=Size(p);}
