#include "common.h"

s32 strlen(u8 *arg0) {
    u8 *v1 = arg0;
    if (*arg0 != 0) {
        do {
        } while (*++v1 != 0);
    }
    return v1 - arg0;
}
