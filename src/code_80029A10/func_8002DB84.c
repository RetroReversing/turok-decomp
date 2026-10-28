#include "common.h"

s32 *func_80011FA0(s32, void *);

void func_8002DB84(void *arg0) {
    s32 *temp_v0;
    s32 *temp_v1;

    temp_v0 = func_80011FA0(8, arg0);
    *(s32 **)arg0 = temp_v0;
    *temp_v0 = 0;
    temp_v1 = *(s32 **)arg0;
    temp_v1[1] = 0;
    *((s32 *)arg0 + 2) = 8;
    *((s32 *)arg0 + 1) = 1;
}
