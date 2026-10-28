#include "common.h"

s32 func_800A2100(s32,s32,s32,s32,s32); void func_800B1580(void*,void*,void*,s32); extern s32 func_800AF59C,func_800AEFA4;
typedef struct {u8 pad[0x14];s32 a14; s16 a18,a1a,a1c,a1e,a20,a22,a24,a26;u8 pad28[8];s32 a30,a34,a38,a3c,a40,a44,a48;} Obj2;
void func_800AD8CC(volatile Obj2 *p,s32 n){
 func_800B1580((void*)p,&func_800AF59C,&func_800AEFA4,4);
 p->a14=func_800A2100(0,0,n,1,0x50);
 p->a38=1;p->a48=0;
 p->a1a=1;*(volatile s16*)((volatile u8*)p+0x28)=1;*(volatile s16*)((volatile u8*)p+0x2e)=1;
 p->a1c=1;p->a1e=1;p->a20=0;p->a22=0;p->a26=1;p->a24=0;
 p->a30=0;p->a34=0;p->a18=0;p->a3c=0;p->a40=0;p->a44=0;
}
