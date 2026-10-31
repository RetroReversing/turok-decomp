#include "common.h"

extern void func_80012E6C(void *, f32);
extern void func_80013224(void *, void *, void *);
extern void func_80014DC4(void *, void *);
extern f32 func_800206E4(void *);
extern void func_800209A4(void *, void *);
extern void func_80020B28(void *, void *);
extern u8 D_80119FB0[], D_80119FF0[], D_8011A030[], D_8011A0D8[];

void *func_80026DC0(u8 *arg0, s32 mode) {
    u8 a[0x10], b[0x44];
    void *p;
    mode = *(s16 *)(arg0 + 0x16C);
    switch (mode + 6) {
        case 1:
            p = D_8011A030;
            break;
        case 3:
            func_80020B28(a, *(void **)(arg0 + 0x14));
            func_80014DC4(a, b);
            func_80013224(D_8011A0D8, D_8011A030, b);
            p = D_8011A0D8;
            break;
        case 4:
            func_800209A4(a, *(void **)(arg0 + 0x14));
            func_80014DC4(a, b);
            func_80013224(D_8011A0D8, D_8011A030, b);
            p = D_8011A0D8;
            break;
        case 6:case 7:case 8:
            func_80012E6C(D_8011A0D8, func_800206E4(*(void **)(arg0 + 0x14)));
            p = D_8011A0D8;
            break;
        case 0:
            p = D_80119FF0;
            break;
        default:
            p = D_80119FB0;
            break;
    }
    return p;
}
