#include "common.h"

/* Draws the fading message box and its OK option. Source: loadsave.c CMessageBox__Draw. */
/* machine draft (m2c) for ido-5.3 -O2 -mips2 -G 0 -non_shared -Xcpluscomm -Wab,-r4300_mul, tried by autopilot */
#ifndef M2C_DEFINES
#define M2C_DEFINES
typedef s32 M2C_UNK;
typedef s8 M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))
#define M2C_BITWISE(type, expr) ((type)(expr))
#define M2C_ERROR(desc) (0)
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)
#endif

M2C_UNK COnScreen__InitBoxDraw(M2C_UNK);                     /* extern */
M2C_UNK COnScreen__DrawBox(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, u32); /* extern */
M2C_UNK COnScreen__DrawHilightBox(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, s32, s32, s32, s32, s32, s32, u32); /* extern */
M2C_UNK func_800806B4(M2C_UNK);                     /* extern */
M2C_UNK draw_onscreen_text(M2C_UNK, s32, M2C_UNK, M2C_UNK, s32, s32, s32); /* extern */
M2C_UNK CPause__InitPolygon(M2C_UNK);                     /* extern */
M2C_UNK func_800859F8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, f32, f32); /* extern */
extern f32 D_800B6B00;
extern s32 D_800B818C;
extern f64 D_800F0C48;
extern f64 D_800F0C50;
extern s32 D_801197B0;

void func_8000E52C(void *pMessageBox, M2C_UNK ppDLP) {
    s16 mode;

    mode = M2C_FIELD(pMessageBox, s16 *, 4);
    switch (mode) {                              /* irregular */
    case 1:
        M2C_FIELD(pMessageBox, f32 *, 0) = (f32) ((f64) M2C_FIELD(pMessageBox, f32 *, 0) + (D_800F0C48 * (f64) D_800B6B00));
        if ((f64) M2C_FIELD(pMessageBox, f32 *, 0) >= 1.0) {
            M2C_FIELD(pMessageBox, s16 *, 4) = 2;
            M2C_FIELD(pMessageBox, f32 *, 0) = 1.0f;
        }
        break;
    case 3:
        M2C_FIELD(pMessageBox, f32 *, 0) = (f32) ((f64) M2C_FIELD(pMessageBox, f32 *, 0) - (D_800F0C50 * (f64) D_800B6B00));
        if ((f64) M2C_FIELD(pMessageBox, f32 *, 0) <= 0.0) {
            M2C_FIELD(pMessageBox, s16 *, 4) = 0;
            M2C_FIELD(pMessageBox, f32 *, 0) = 0.0f;
            if (M2C_FIELD(pMessageBox, s32 *, 8) == 0) {
                D_801197B0 = 0;
            }
        }
        break;
    }
    COnScreen__InitBoxDraw(ppDLP);
    COnScreen__DrawBox(ppDLP, 0, 0, 0x140, 0xF0, 0, 0, 0, (u32) (M2C_FIELD(pMessageBox, f32 *, 0) * 120.0f));
    COnScreen__DrawHilightBox(ppDLP, 0x3C, 0x46, 0x104, 0x7A, 2, 1, 0x1E, 0x1E, 0x1E, (u32) (M2C_FIELD(pMessageBox, f32 *, 0) * 220.0f));
    COnScreen__DrawHilightBox(ppDLP, 0x3C, 0x7B, 0x104, 0xAA, 2, 1, 0x1E, 0x1E, 0x1E, (u32) (M2C_FIELD(pMessageBox, f32 *, 0) * 220.0f));
    CPause__InitPolygon(ppDLP);
    func_800859F8(ppDLP, 0x42B80000, 0x430A0000, 0x43080000, 18.0f, M2C_FIELD(pMessageBox, f32 *, 0));
    func_800806B4(ppDLP);
    draw_onscreen_text(ppDLP, M2C_FIELD(pMessageBox, s32 *, 0x10), 0xA0, 0x4E, (s32) (M2C_FIELD(pMessageBox, f32 *, 0) * 255.0f), 1, 1);
    draw_onscreen_text(ppDLP, M2C_FIELD(pMessageBox, s32 *, 0x14), 0xA0, 0x5E, (s32) (M2C_FIELD(pMessageBox, f32 *, 0) * 255.0f), 1, 1);
    draw_onscreen_text(ppDLP, D_800B818C, 0xA0, 0x8A, (s32) (M2C_FIELD(pMessageBox, f32 *, 0) * 255.0f), 1, 1);
}
