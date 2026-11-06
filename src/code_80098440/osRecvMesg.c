#include "common.h"

extern s32 __osDisableInt(void); extern void __osRestoreInt(s32); extern void __osEnqueueAndYield(void *); extern s32 __osPopThread(void *); extern void osStartThread(s32); extern struct { u8 pad[16]; s16 field; } *D_800EF290;
typedef struct { s32 unk0; s32 *unk4; s32 count; s32 index; s32 capacity; s32 *items; } Queue;
s32 osRecvMesg(Queue *q, s32 *out, s32 wait) {
 register s32 lock; register s32 value;
 lock = __osDisableInt();
 if (q->count == 0) {
loop:
  if (wait == 0) { __osRestoreInt(lock); return -1; }
  D_800EF290->field = 8;
  __osEnqueueAndYield((void *)q);
  if (q->count == 0) goto loop;
 }
 if (out != 0) *out = q->items[q->index];
 q->index = (q->index + 1) % q->capacity;
 q->count--;
 if (*q->unk4 != 0) { value = __osPopThread((void *)&q->unk4); osStartThread(value); }
 __osRestoreInt(lock);
 return 0;
}
