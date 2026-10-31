#include "common.h"

s32 func_80049BE0(void *arg0, s32 arg1) {
    s32 bits = *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x17C) + 0x1FC) + 4);
    switch (arg1) {
    case 26:case 27:case 28:case 29:case 30:return (bits & 1) != 0;
    case 9:case 10:case 11:case 12:case 13:case 19:case 20:case 21:case 22:case 23:return (bits & 2) != 0;
    case 8:case 18:return (bits & 4) != 0;
    case 6:case 7:case 16:case 17:return (bits & 8) != 0;
    case 1:return (bits & 16) != 0;
    case 31:case 44:return (bits & 32) != 0;
    default: return 0;
    }
}
