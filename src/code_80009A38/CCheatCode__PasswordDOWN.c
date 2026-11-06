#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef struct { s32 count; s32 unknown4; s32 unknown8; } Record12;
typedef struct { s8 unknown0[12]; s32 index; s32 selection; } StateOffsets;
extern Record12 D_800B8210[];
extern f32 D_800EC0C0;
void CCheatCode__PasswordDOWN(StateOffsets *pThis) {
    s32 count;
    s32 index;
    D_800EC0C0 = 0.0f;
    index = ++pThis->index;
    if (index >= 7) {
        pThis->index = 0;
        index = 0;
    }
    count = D_800B8210[index].count;
    if (count != 0) {
        if (pThis->selection >= count) {
            pThis->selection = count - 1;
        }
    } else {
        pThis->selection = 0;
    }
}
