#include "common.h"

extern void guMtxF2L(void *, void *);
extern void guOrthoF(void *, f32, f32, f32, f32, f32, f32, f32);
void guOrtho(void *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    u8 data[0x40];
    guOrthoF(data, a, b, c, d, e, f, g);
    guMtxF2L(data, p);
}
