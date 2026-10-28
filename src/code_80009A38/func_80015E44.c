#include "common.h"

typedef struct { u8 p[0x18]; struct {u8 p[0x44]; s16 state;} *inner;} Obj;
extern s32 D_80128DFC,D_80128E00,D_80128E04,D_80128E08,D_80128E0C,D_80128E10,D_80128E14,D_800B9878; extern f32 D_800B9888;
s32 func_80015E44(Obj *arg0,s32 arg1) { s32 index; s32 value;
 switch(arg0->inner->state) {
 case 2: value=D_80128DFC; index=0; break;
 case 3: value=D_80128E00; index=1; break;
 case 4: value=D_80128E04; index=2; break;
 case 5: value=D_80128E08; index=3; break;
 case 6: value=D_80128E0C; index=4; break;
 case 7: value=D_80128E10; index=5; break;
 case 8: value=D_80128E14; index=0; break;
 default: return *(s8 *)((u8 *)arg0->inner+0x4D);
 }
 if(arg0->inner->state==8) { if(arg1>0 && value<arg1){D_800B9878=1;D_800B9888=0;} return index; }
 if(arg1 && value<arg1){D_800B9878=1;D_800B9888=0;} return index;
}
