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
extern void *i3D_mallocPoolTop (t_MemoryPool *pool, int size) ;
void *i3D_mallocPoolTop (t_MemoryPool *pool, int size);
void *i3D_mallocPoolTop (t_MemoryPool *pool, int size){
 t_Memory *pointer ;
 t_Memory *free ;
 int total_size ;
 /* --- Illegal allocation size ? */ if (size < 0)
  return ((void*)0) ;
 /* --- Align size to 4 bytes */ size = (size + 8 - 1) & ~(8 - 1) ;
 /* --- Find free allocation slot */ pointer = pool->free_tail ;
 total_size = size + sizeof (t_Memory) ;
 while (pointer)
 {
  if (pointer->size >= total_size)
  {
   /* --- Modify free entry */ pointer->size -= total_size ;
    /* --- Setup new used entry */ free = (t_Memory *)((int)pointer->addr + pointer->size) ;
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
