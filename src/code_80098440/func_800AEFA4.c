#include "common.h"

typedef struct {
    void *object;
    char pad04[0x16];
    s16 flag;
    char pad1C[0x1C];
    s32 field38;
    void *field3C;
    void *field40;
    char pad44[4];
    s32 field48;
} Obj_800AEFA4;

typedef struct {
    void *pad0;
    char pad4[4];
    void (*dispatch)(void *self, s32 command);
} CallbackObject_800AEFA4;

s32 func_800AEFA4(Obj_800AEFA4 *state, s32 mode, void *value) {
    CallbackObject_800AEFA4 *object;

    switch (mode) {
    case 3:
        if (state->field40 != NULL) {
            *(void **)state->field40 = value;
        } else {
            state->field3C = value;
        }
        state->field40 = value;
        break;
    case 4:
        object = state->object;
        state->field38 = 1;
        state->field48 = 0;
        state->flag = 1;
        if (object != NULL) {
            object->dispatch(object, 4);
        }
        break;
    case 9:
        object = state->object;
        state->field48 = 1;
        if (object != NULL) {
            object->dispatch(object, 9);
        }
        break;
    case 1:
        state->object = value;
        break;
    default:
        object = state->object;
        if (object != NULL) {
            object->dispatch(object, mode);
        }
        break;
    }
    return 0;
}
