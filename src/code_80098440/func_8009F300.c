#include "common.h"

s32 func_8009F3B4(s32, s32); s32 func_800A8520(); s32 func_800A8564(); s32 func_800A8D94(void *); s32 func_800A9480(void *);

/* Runs the ordered setup stages and marks arg1 ready after all return success. */
s32 func_8009F300(s32 arg0, void *arg1, s32 arg2) {
    s32 result = 0;

    func_800A8520();
    result = func_8009F3B4(arg0, arg2);
    func_800A8564();
    if (result != 0) {
        return result;
    }

    *(s32 *)((u8 *)arg1 + 4) = arg0;
    *(s32 *)((u8 *)arg1 + 8) = arg2;
    *(s32 *)arg1 = 0;

    result = func_800A8D94(arg1);
    if (result != 0) {
        return result;
    }

    result = func_800A9480(arg1);
    *(s32 *)arg1 |= 1;
    return result;
}
