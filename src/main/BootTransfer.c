#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
typedef unsigned long sa_u32;
extern void *func_80000308;
void BootTransfer(sa_u32 src, sa_u32 dst, sa_u32 length);
void BootTransfer(sa_u32 src, sa_u32 dst, sa_u32 length){
 register sa_u32 *srcaddr;
 register sa_u32 *dstaddr;
 register volatile sa_u32 *status;
 srcaddr = (sa_u32 *)((sa_u32)func_80000308|(sa_u32)src);
 dstaddr = (sa_u32 *)dst;
 status = (sa_u32 *)((sa_u32)((0x04600000 + 0x10))|0xA0000000);
 length >>=2;
 while ( length--)
 {
  /* Wait for busy IO status, in reality, it should never be busy. */ /* the question is: how slow is the ROM and what happens while it's trying */ /* to fetch the data? */ while ( *status & ((1 << 1)|(1 << 0)));
    *dstaddr++ = *srcaddr++;
 }
}
