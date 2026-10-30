#include "common.h"

extern f64 D_800F75D0;
typedef struct { u8 pad[0x18]; s16 value; } Arg0;
u32 alSeqSecToTicks(Arg0 *arg0, f32 arg1, u32 arg2) {
    return (u32)(((f64)arg1 * D_800F75D0 * (f64)arg0->value) / (f64)arg2);
}
