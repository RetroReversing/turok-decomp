#include "common.h"

extern s32 func_800A5750(void); extern void func_800A5770(s32); extern void func_800A5DEC(void *); extern s32 func_800A5F34(void *); extern void func_8009E150(s32); extern struct { u8 pad[16]; s16 field; } *D_800EF290;
typedef struct { s32 unk0; s32 *unk4; s32 count; s32 index; s32 capacity; s32 *items; } Queue;
s32 func_8009D0B0(Queue *q, s32 *out, s32 wait) {
 register s32 lock; register s32 value;
 lock = func_800A5750();
 if (q->count == 0) {
loop:
  if (wait == 0) { func_800A5770(lock); return -1; }
  D_800EF290->field = 8;
  func_800A5DEC((void *)q);
  if (q->count == 0) goto loop;
 }
 if (out != 0) *out = q->items[q->index];
 q->index = (q->index + 1) % q->capacity;
 q->count--;
 if (*q->unk4 != 0) { value = func_800A5F34((void *)&q->unk4); func_8009E150(value); }
 func_800A5770(lock);
 return 0;
}
