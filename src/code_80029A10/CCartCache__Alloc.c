#include "common.h"

void *i3D_mallocTop(s32);
s32 func_80011FA0(s32);
s32 CCartCache__DiscardCacheEntry(s32);
s32 CCartCache__Alloc(s32 owner, void *request, s32 mode) {
    void *result, *candidate;
    if (mode) {
        result = i3D_mallocTop((s32)request);
        candidate = result;
    } else {
        result = (void *)func_80011FA0((s32)request);
        candidate = result;
    }
    if (result) return (s32)candidate;
    /* Retry allocation while the owner can release another resource. */
    do {
        if (!CCartCache__DiscardCacheEntry(owner)) return 0;
        if (mode) {
            result = i3D_mallocTop((s32)request);
            candidate = result;
        } else {
            result = (void *)func_80011FA0((s32)request);
            candidate = result;
        }
    } while (!candidate);
    return (s32)candidate;
}
