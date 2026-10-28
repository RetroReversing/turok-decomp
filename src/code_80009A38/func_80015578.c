#include "common.h"

typedef struct { f32 m[16]; } M;
void func_80015578(M*p,f32 a,f32 b,f32 c){p->m[15]=1;p->m[10]=1;p->m[5]=1;p->m[0]=1;p->m[11]=0;p->m[9]=0;p->m[8]=0;p->m[7]=0;p->m[6]=0;p->m[4]=0;p->m[3]=0;p->m[2]=0;p->m[1]=0;p->m[12]=a;p->m[13]=b;p->m[14]=c;}
