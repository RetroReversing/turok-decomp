#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

void *i3D_mallocTop(s32);
s32 func_80011FA0(s32);
s32 CCartCache__DiscardCacheEntry(s32);
s32 CCartCache__Alloc(s32 pThis, void *Size, s32 AllocTop) {
    void *result, *candidate;
    if (AllocTop) {
        result = i3D_mallocTop((s32)Size);
        candidate = result;
    } else {
        result = (void *)func_80011FA0((s32)Size);
        candidate = result;
    }
    if (result) return (s32)candidate;
    /* Retry allocation while the owner can release another resource. */
    do {
        if (!CCartCache__DiscardCacheEntry(pThis)) return 0;
        if (AllocTop) {
            result = i3D_mallocTop((s32)Size);
            candidate = result;
        } else {
            result = (void *)func_80011FA0((s32)Size);
            candidate = result;
        }
    } while (!candidate);
    return (s32)candidate;
}
