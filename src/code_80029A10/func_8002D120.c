#include "common.h"

void *func_80011E98(s32);
s32 func_80011FA0(s32);
s32 func_8002CD18(s32);
s32 func_8002D120(s32 owner, void *request, s32 mode) {
    void *result, *candidate;
    if (mode) {
        result = func_80011E98((s32)request);
        candidate = result;
    } else {
        result = (void *)func_80011FA0((s32)request);
        candidate = result;
    }
    if (result) return (s32)candidate;
    /* Retry allocation while the owner can release another resource. */
    do {
        if (!func_8002CD18(owner)) return 0;
        if (mode) {
            result = func_80011E98((s32)request);
            candidate = result;
        } else {
            result = (void *)func_80011FA0((s32)request);
            candidate = result;
        }
    } while (!candidate);
    return (s32)candidate;
}
