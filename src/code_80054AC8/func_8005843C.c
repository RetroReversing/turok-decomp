#include "common.h"

/* Source-assisted mapping: CTMove__WeaponEmpty in PR/tengine/tmove.c. */
typedef struct {u8 pad[0x140];s32 x140,x144,x148,x14c,x150,x154,x158,x15c,x160,x164,x168,x16c,x170;} Obj;
extern void *D_800F341C[15]; extern void *D_800F3458[5];
s32 func_8005843C(Obj *p,s32 weapon,s32 variation) {
 switch(weapon) {
 case 0x64: if (p->x154==0) return 1; break;
 case 0x65: if (p->x158==0) return 1; break;
 case 0x66: if (p->x15c+p->x14c<=0) return 1; break;
 case 0x67: if (p->x140<=0) return 1; break;
 case 0x68: if (p->x140<=0) return 1; break;
 case 0x69: if (p->x148<=0) return 1; break;
 case 0x6A: if (p->x148<5) return 1; break;
 case 0x6B:
 switch(variation) {
 case 1:if (p->x148<2) return 1; break;
 case 2:if (p->x148<4) return 1; break;
 case 3:if (p->x148<6) return 1; break;
 case 4:if (p->x148<8) return 1; break;
 case 5:if (p->x148<10) return 1; break;
 }
 break;
 case 0x6C:if (p->x144+p->x150<=0) return 1; break;
 case 0x6D:if (p->x144+p->x150<=0) return 1; break;
 case 0x6E:if (p->x160<=0) return 1; break;
 case 0x6F:if (p->x170<=0) return 1; break;
 case 0x70:if (p->x164<=0) return 1; break;
 case 0x71:if (p->x168<=0) return 1; break;
 case 0x72:if (p->x16c<=0) return 1; break;
 }
 return 0;
}
