#include "common.h"

typedef unsigned long sa_u32;
extern void *func_80000308;
void func_80000450(sa_u32 src, sa_u32 dst, sa_u32 length);
void func_80000450(sa_u32 src, sa_u32 dst, sa_u32 length){
 register sa_u32 *srcaddr;
 register sa_u32 *dstaddr;
 register volatile sa_u32 *status;
 srcaddr = (sa_u32 *)((sa_u32)func_80000308|(sa_u32)src);
 dstaddr = (sa_u32 *)dst;
 status = (sa_u32 *)((sa_u32)((0x04600000 + 0x10))|0xA0000000);
 length >>=2;
 while ( length--)
 {
  while ( *status & ((1 << 1)|(1 << 0)));
    *dstaddr++ = *srcaddr++;
 }
}
