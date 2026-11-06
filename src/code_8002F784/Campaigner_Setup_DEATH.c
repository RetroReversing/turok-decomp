#include "common.h"

extern u8 D_800BDBCC;
extern u8 D_80112C18[];
extern void CSpecialFx__Construct(void *, s32, void *);
extern void CSpecialFx__StartScript(void *, void *);
extern void CCamera__FadeToCinema(void *, s32);
typedef struct {u8 pad[0x8cc4]; s32 flags; u8 pad2[0x178]; s32 value;} Global;
extern Global D_80109F10;
void Campaigner_Setup_DEATH(s32 a, void *b) {
    *(s32 *)((u8 *)b + 0x20) = 0x37;
    CSpecialFx__Construct((u8 *)b + 0x188, a, b);
    CSpecialFx__StartScript((u8 *)b + 0x188, &D_800BDBCC);
    D_80109F10.flags |= 0x20000;
    D_80109F10.value = a;
    CCamera__FadeToCinema(D_80112C18, 0x800);
    *(f32 *)((u8 *)b + 0x258) = 0.0f;
}
