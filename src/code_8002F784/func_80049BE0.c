#include "common.h"

s32 func_80049BE0(void *arg0, s32 arg1) {
    s32 bits = *(s32 *)((u8 *)*(void **)((u8 *)*(void **)((u8 *)arg0 + 0x17C) + 0x1FC) + 4);
    switch (arg1) {
    case 1: case 7: case 13: case 19: case 25: case 31: case 37: case 44: return (bits & 1) != 0;
    case 2: case 8: case 14: case 20: case 26: case 32: case 38: return (bits & 2) != 0;
    case 3: case 9: case 15: case 21: case 27: case 33: case 39: return (bits & 4) != 0;
    case 4: case 10: case 16: case 22: case 28: case 34: case 40: return (bits & 8) != 0;
    case 5: case 11: case 17: case 23: case 29: case 35: case 41: return (bits & 16) != 0;
    case 6: case 12: case 18: case 24: case 30: case 36: case 42: return (bits & 32) != 0;
    default: return 0;
    }
}
