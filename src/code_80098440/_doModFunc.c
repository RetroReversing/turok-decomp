#include "common.h"

typedef struct { char pad[16]; f32 step, phase; char gap[4]; f32 scale; } S;
f32 _doModFunc(S *a, s32 n) {
    f64 d;
    f32 q, result;
    a->phase = a->phase + a->step * (f32)n;
    d = a->phase;
    if (d > 2.0) a->phase = (f32)(d - 4.0);
    else a->phase = (f32)d;
    q = a->phase;
    if (q < 0.0f) q = -q;
    d = (f64)q - 1.0;
    q = (f32)d;
    result = a->scale * q;
    return result;
}
