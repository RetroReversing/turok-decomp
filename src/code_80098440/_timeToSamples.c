#include "common.h"

extern f64 D_800F70D0;

typedef struct {
    char pad[0x44];
    s32 unk44;
} Struct5068;

s32 _timeToSamples(Struct5068 *arg0, s32 arg1) {
    f32 temp = (f64)((f32)arg1 * (f32)arg0->unk44) / D_800F70D0 + 0.5;
    return (s32)temp & -0x10;
}
