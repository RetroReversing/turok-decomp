#include "common.h"

typedef struct {
    char pad[0x2C];
    void *unk2C;
} SomeStruct;

extern SomeStruct *D_800EF260;

void func_800A5158(void **arg0) {
    SomeStruct *s = D_800EF260;
    *arg0 = s->unk2C;
    s->unk2C = arg0;
}
