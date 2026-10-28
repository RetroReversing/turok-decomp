#include "common.h"

typedef struct { u8 pad[0x144]; f32 value; u8 pad2[0x34]; void *p; } A;
typedef struct { u8 pad[0x20]; s32 code; } B;
extern A *D_80112BD8;
s32 func_800165E0(void *unused, u32 index) {
    A *obj = D_80112BD8;
    if (((B *)obj->p)->code != 0x29) return -1;
    switch (index) {
    case 0: if (104.0f < obj->value) return -1; break;
    case 1: if (122.0f < obj->value) return -1; break;
    case 2: if (135.0f < obj->value) return -1; break;
    case 3: if (118.0f < obj->value) return -1; break;
    case 4: if (121.0f < obj->value) return -1; break;
    case 5: if (135.0f < obj->value) return -1; break;
    case 6: case 7: case 8: case 9: case 10: case 11: case 12: break;
    }
    if (obj->value < 17.0f) return -1;
    return 0;
}
