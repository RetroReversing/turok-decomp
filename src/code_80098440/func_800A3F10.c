#include "common.h"

typedef struct { char pad[0x3c]; s32 index; char *items; } A;
typedef struct { s16 type; s16 pad; void *entry; char extra[8]; } Cmd;
extern void func_800ACBAC(void *, Cmd *, s32);
void func_800A3F10(A *a) {
    Cmd command;
    char *items = a->items;
    command.type = 1;
    /* Select the 0x30-byte entry indexed by this object's current slot. */
    command.entry = items + a->index * 0x30;
    func_800ACBAC((char *)a + 0x14, &command, 0);
}
