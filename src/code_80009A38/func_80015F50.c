#include "common.h"

typedef struct {u8 pad[0x18]; void *ptr;} S;
typedef struct {u8 pad[0x44]; s16 kind; u8 pad2[7]; s8 fallback;} T;
extern s32 D_80128DFC,D_80128E00,D_80128E04,D_80128E08,D_80128E0C,D_80128E10;
extern s32 D_800B9878;
extern f32 D_800B987C[4];
s32 func_80015F50(S *a,s32 lim) {
    T *t = a->ptr;
    s32 x,r;
    switch(t->kind) {
    case 2: x=D_80128DFC;r=0;break;
    case 3: x=D_80128E00;r=1;break;
    case 4: x=D_80128E04;r=2;break;
    case 5: x=D_80128E08;r=3;break;
    case 6: x=D_80128E0C;r=4;break;
    case 7: x=D_80128E10;r=5;break;
    default: return t->fallback;
    }
    if(lim && x<lim) {
        D_800B9878=3;
        D_800B987C[0]=0.0f;
        D_800B987C[1]=0.0f;
        D_800B987C[2]=0.0f;
        D_800B987C[3]=192.0f;
    }
    return r;
}
