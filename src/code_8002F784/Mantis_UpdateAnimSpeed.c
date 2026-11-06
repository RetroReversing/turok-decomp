#include "common.h"

extern s32 CCamera__InCinemaMode(void *); extern u8 D_80112C18[];
void Mantis_UpdateAnimSpeed(void *a, void *b) {
 if(CCamera__InCinemaMode(D_80112C18)){*(f32 *)((u8 *)b+0xCC)=1.0f;return;}
 switch(*(s32 *)((u8 *)b+0x20)){
 case 20: case 40: case 54: case 7: *(f32 *)((u8 *)b+0xCC)=1.0f; break;
 case 8: if(*(s16 *)((u8 *)b+0x108)==1){*(f32 *)((u8 *)b+0xCC)=2.0f; break;}
 default: *(f32 *)((u8 *)b+0xCC)=*(f32 *)((u8 *)*(void **)((u8 *)b+0x188)+4); break;
 }
}
