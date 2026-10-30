#include "common.h"

s32 alSaveParam(s32 *values, s32 kind, s32 value) {
    /* Only kinds 1 and 6 select a destination field. */
    switch (kind) {
    case 1:
        values[0] = value;
        break;
    case 6:
        values[5] = value;
        break;
    }
    return 0;
}
