#include "common.h"

extern void BOSS_RotateToFaceTurok(s32, void *, s32);
extern void TRex_SetupMode(s32, s32);
void TRex_Code_FireLoop(s32 arg0, void *arg1) {
    s32 val = *(s32 *)((u8 *)arg1 + 0x20);
    if (val == 0x13) {
        BOSS_RotateToFaceTurok(arg0, arg1, 0x3E0EFA35);
        val = *(s32 *)((u8 *)arg1 + 0x20);
    }
    if (val == 0x16) {
        BOSS_RotateToFaceTurok(arg0, arg1, 0x3D567750);
    }
    if (*(s32 *)((u8 *)arg1 + 0x3C) >= *(s32 *)((u8 *)arg1 + 0x48)) {
        TRex_SetupMode(arg0, *(s32 *)((u8 *)arg1 + 0x20) + 2);
    }
}
