#include "common.h"

void func_800B1500(u8 *src, u8 *dst, s32 n) {
    u8 *from = src;
    u8 *to = dst;
    s32 i = 0;
    while (i < n) {
        *to = *from;
        to++;
        from++;
        i++;
    }
}
