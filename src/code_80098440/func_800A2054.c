#include "common.h"

extern void func_8009DD90(void *, void *);
extern void func_800A1F00(void *, f32, f32, f32, f32, f32, f32, f32);
void func_800A2054(void *p, f32 a, f32 b, f32 c, f32 d, f32 e, f32 f, f32 g) {
    u8 data[0x40];
    func_800A1F00(data, a, b, c, d, e, f, g);
    func_8009DD90(data, p);
}
