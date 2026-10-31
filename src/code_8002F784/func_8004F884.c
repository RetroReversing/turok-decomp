#include "common.h"

s32 func_8004F884(void*a,s32 n){s32 x=*(s32*)((char*)*(void**)((char*)*(void**)((char*)a+0x17c)+0x250)+4);switch(n){case 21:return (x&16)!=0;case 20:return (x&32)!=0;case 13:return (x&64)!=0;case 14:return (x&128)!=0;case 5:return (x&256)!=0;default:return 0;}}
