#include "common.h"

typedef struct { u8 pad[0x1F9C0]; f32 progress; } LargeSave063;
extern f32 func_800516C4(s32);
extern f32 func_80051994(s32);
extern void func_80031974(void *, s32, f32, void *, void *, s32);
extern f64 D_800EF9B8;
extern f64 D_800EF9C0;
extern s32 D_800F9E44;
extern f32 D_800FA3C8;
extern f32 D_800B6B00;
s32 func_800063A8(void *arg0) {
    f32 value;
    if (((u8 *)((LargeSave063 *)arg0) + 0x18000)[0x76F1] == 2) return 0;
    if (func_800516C4(D_800F9E44) != 0.0f &&
        D_800EF9B8 == (f64)*(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79C0) &&
        D_800EF9B8 == (f64)*(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79BC) &&
        D_800EF9B8 == (f64)*(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79B8) &&
        D_800EF9B8 == (f64)*(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79B4)) {
        ((LargeSave063 *)arg0)->progress = 249.0f;
        func_80031974(&D_800FA3C8, 0x182, 0.0f, NULL, (u8 *)((LargeSave063 *)arg0) + 0x18E28, 0);
        return 1;
    }
    value = func_80051994(D_800F9E44);
    if (value <= 30.0f) {
        ((LargeSave063 *)arg0)->progress = 249.0f;
        return 0;
    }
    ((LargeSave063 *)arg0)->progress = *(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79C0) + value * D_800B6B00;
    if ((f64)D_800EF9C0 <= (f64)*(f32 *)(((u8 *)((LargeSave063 *)arg0) + 0x18000) + 0x79C0)) {
        ((LargeSave063 *)arg0)->progress = 0.0f;
        func_80031974(&D_800FA3C8, 0x182, 0.0f, NULL, (u8 *)((LargeSave063 *)arg0) + 0x18E28, 0);
        return 1;
    }
    return 0;
}
