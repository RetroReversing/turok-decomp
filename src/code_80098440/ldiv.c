#include "common.h"

typedef struct {s32 q,r;} Pair;
void *ldiv(Pair *p, s32 a, s32 b) {
    Pair t;
    t.q = a / b;
    t.r = a - b * t.q;
    if (t.q < 0) {
        t.q = t.q;
        t.r = t.r;
        if (t.r > 0) {
            t.q += 1;
            t.r -= b;
        }
    }
    *p = t;
    return p;
}
