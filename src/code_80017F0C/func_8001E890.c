#include "common.h"

extern void func_8002D1F8(void*,void*,s32,void*,void*,s32,s32,void*); extern s32 func_8002DC24(s32,s32,u16); extern void func_8001914C(); extern s32 D_800FA3C8,D_800F0DF4;
typedef struct {u8 pad0[2];u16 id;u8 pad4[0xf8];s32 value; s32 zero1;u8 pad104[8];s32 zero2;u8 pad110[0x20];u32 flags;u8 pad134[0x34];s16 mode;} Obj;
void func_8001E890(Obj *a,s32 b,s32 c,s32 d){
a->flags &= ~0x10000;
a->flags &= ~0x20000;
a->flags |= 0x40000;
a->mode=d;
a->zero1=0;
a->zero2=0;
a->value=func_8002DC24(b,c,a->id);
func_8002D1F8(&D_800FA3C8,a,0,func_8001914C,(u8*)a+0x108,a->value,0x18,&D_800F0DF4);
}
