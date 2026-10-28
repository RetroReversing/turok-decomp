#include "common.h"

s32 func_8005F100(s32 soundId) {
    switch (soundId) {
    case 0:
    case 1:
    case 0x15:
    case 0xAD:
    case 0xCE:
    case 0x10D:
    case 0xAB:
    case 0x25B:
        return 1;
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x182:
    case 0x183:
    case 0x184:
    case 0x185:
    case 0x186:
    case 0x187:
    case 0x188:
    case 0x189:
    case 0x18A:
    case 0x18B:
    case 0x18C:
    case 0x18D:
    case 0x18E:
    case 0x18F:
    case 0x190:
    case 0x191:
    case 0x192:
    case 0x193:
    case 0x194:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x206:
    case 0x207:
    case 0x208:
    case 0x209:
    case 0x20A:
    default:
        /* These IDs dispatch to empty entries or invalid cases. */
        return 0;
    }
}
