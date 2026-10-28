#include "common.h"

void func_80011DDC(void *);
typedef struct { void *data; s32 field_4; s32 activeCount; s32 freeCount; void *freeList; } CBlockPool;
void func_8002E1C0(CBlockPool *pool) {
 void *block;
 void *next;
 if (pool->data != NULL) {
  func_80011DDC(pool->data);
  pool->data = NULL;
 }
 block = pool->freeList;
 pool->activeCount = 0;
 pool->freeCount = 0;
 while (block != NULL) {
  next = *(void **)block;
  func_80011DDC(block);
  block = next;
 }
 pool->freeList = NULL;
}
