#include "common.h"

typedef struct { u8 pad[0x3c]; s32 index; void *items; } A;
extern void alEvtqPostEvent(void *, void *, s32);
void alSndpSetPitch(A *a, f32 v) {
    struct { s16 type; u16 pad; void *entry; f32 value; u8 extra[4]; } command;
    u8 *base = a->items;
    command.type = 4;
    command.entry = base + a->index * 0x30;
    command.value = v;
    alEvtqPostEvent((u8 *)a + 0x14, &command, 0);
}
