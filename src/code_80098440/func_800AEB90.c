#include "common.h"

typedef struct { void *object; u8 pad[0x14]; f32 field18; s32 field1C; f32 field20; s32 field24; u8 pad2[8]; s32 field30; } Record;
typedef struct { u8 pad[8]; void (*callback)(void *, s32, s32); } Object;
s32 func_800AEB90(Record *arg0, s32 type, s32 value) {
    void *object; volatile s32 unused; float f;
    switch (type) {
    case 1: arg0->object = (void *)value; break;
    case 2:
        object = arg0->object; arg0->field24 = 1; arg0->field30 = 0; arg0->field1C = 0; arg0->field20 = 0.0f;
        if (object) ((Object *)object)->callback(object, 4, 0);
        break;
    case 3:
        object = arg0->object; arg0->field30 = 1;
        if (object) ((Object *)object)->callback(object, 9, 0);
        break;
    case 4: *(s32 *)&f = value; arg0->field18 = f; break;
    case 5: arg0->field1C = 1; break;
    case 6: case 7: case 8: case 9:
    default:
        object = arg0->object;
        if (object) ((Object *)object)->callback(object, type, value);
        break;
    }
    return 0;
}
