#include "common.h"

extern void func_800B1580(void *, void *, void *, s32);
extern s32 alHeapDBAlloc(s32, s32, s32, s32, s32);
extern s32 alLoadParam;
extern s32 alAdpcmPull;
typedef struct {s32 pad[4];s32 (*callback)(void *);} Obj2;
void alLoadNew(Obj2 *obj, s32 (*callback)(void *), s32 arg2)
{
  s32 allocationKey;
  func_800B1580(obj,&alAdpcmPull, &alLoadParam, 0);
  allocationKey = arg2;
  obj->pad[5] = (s32) alHeapDBAlloc(0, 0, allocationKey, 1, 0x20);
  obj->pad[6] = (s32) alHeapDBAlloc(0, 0, allocationKey, 1, 0x20);
  /* Initialize the callback-owned state and its status fields. */
  obj->pad[12] = callback(((u8 *) obj) + 0x34);
  obj->pad[15] = 0;
  obj->pad[16] = 1;
  obj->pad[17] = 0;
}
