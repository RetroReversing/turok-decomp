#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

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
extern void *i3D_mallocPool (t_MemoryPool *pool, int size) ;
void *i3D_mallocPool (t_MemoryPool *pool, int size);
void *i3D_mallocPool (t_MemoryPool *pool, int size){
 t_Memory *pointer ;
 t_Memory *free ;
 t_Memory *prev ;
 t_Memory *next ;
 int total_size ;
 /* --- Illegal allocation size ? */ if (size < 0)
 {
               ;
  return ((void*)0) ;
 }
 /* --- Align size to MEMORY_ALIGN bytes */ size = (size + 8 - 1) & ~(8 - 1) ;
 /* --- Find free allocation slot */ pointer = pool->free_head ;
 total_size = size + sizeof (t_Memory) ;
 while (pointer)
 {
  if (pointer->size >= total_size)
  {
   /* --- Modify previous and next linked elements */ free = (t_Memory *)((int)pointer + total_size) ;
   prev = pointer->prev ;
   next = pointer->next ;
   if (prev)
    prev->next = free ;
   if (next)
    next->prev = free ;
   /* --- Modify free entry */ free->prev = prev ;
   free->next = next ;
   free->addr = (void *)((int)free + sizeof (t_Memory)) ;
   free->size = pointer->size - total_size ;
   if (pool->free_head == pointer)
    pool->free_head = free ;
   if (pool->free_tail == pointer)
    pool->free_tail = free ;
   /* --- Setup new used entry */ pointer->prev = ((void*)0) ;
   pointer->next = pool->used_head ;
   pointer->addr = (t_Memory *)((int)pointer + sizeof (t_Memory)) ;
   pointer->size = size ;
   if (pool->used_head)
    pool->used_head->prev = pointer ;
   pool->used_head = pointer ;
   return pointer->addr ;
  }
  pointer = pointer->next ;
 }
 return ((void*)0);
}
