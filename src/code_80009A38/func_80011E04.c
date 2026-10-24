#include "common.h"

typedef struct s_Memory {
 struct s_Memory *prev ;
 struct s_Memory *next ;
 void *addr ;
 int size ;
} t_Memory ;
typedef struct s_MemoryPool {
 void *addr ;
 int size ;
 struct s_Memory *free_head ;
 struct s_Memory *free_tail ;
 struct s_Memory *used_head ;
} t_MemoryPool ;
extern void *func_80011E04 (t_MemoryPool *pool, int size) ;
void *func_80011E04 (t_MemoryPool *pool, int size);
void *func_80011E04 (t_MemoryPool *pool, int size){
 t_Memory *pointer ;
 t_Memory *free ;
 int total_size ;
 if (size < 0)
  return ((void*)0) ;
 size = (size + 8 - 1) & ~(8 - 1) ;
 pointer = pool->free_tail ;
 total_size = size + sizeof (t_Memory) ;
 while (pointer)
 {
  if (pointer->size >= total_size)
  {
   pointer->size -= total_size ;
    free = (t_Memory *)((int)pointer->addr + pointer->size) ;
   free->prev = ((void*)0) ;
   free->next = pool->used_head ;
   free->addr = (t_Memory *)((int)free + sizeof (t_Memory)) ;
   free->size = size ;
   if (pool->used_head)
    pool->used_head->prev = free ;
   pool->used_head = free ;
   return free->addr ;
  }
  pointer = pointer->prev ;
 }
 return ((void*)0) ;
}
