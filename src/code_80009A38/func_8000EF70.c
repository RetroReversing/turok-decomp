#include "common.h"

typedef struct { s32 count; s32 unknown4; s32 unknown8; } Record12;
typedef struct { s8 unknown0[12]; s32 index; s32 selection; } StateOffsets;
extern Record12 D_800B8210[];
extern f32 D_800EC0C0;
void func_8000EF70(StateOffsets *arg0) {
    s32 count;
    s32 index;
    D_800EC0C0 = 0.0f;
    index = ++arg0->index;
    if (index >= 7) {
        arg0->index = 0;
        index = 0;
    }
    count = D_800B8210[index].count;
    if (count != 0) {
        if (arg0->selection >= count) {
            arg0->selection = count - 1;
        }
    } else {
        arg0->selection = 0;
    }
}
