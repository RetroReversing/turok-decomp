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
extern void *func_80011EC0 (t_MemoryPool *pool, int size) ;
extern void *func_80011FC8 (t_MemoryPool *pool, void *address, int size) ;
extern int D_80011BD8 (t_MemoryPool *pool, void *address) ;
void *func_80011EC0 (t_MemoryPool *pool, int size);
void *func_80011FC8 (t_MemoryPool *pool, void *address, int size);
int D_80011BD8 (t_MemoryPool *pool, void *address);
void *func_80011FC8 (t_MemoryPool *pool, void *address, int size){
 void *newaddr ;
 unsigned long *source ;
 unsigned long *dest ;
 int i ;
 int oldsize ;
 int count ;
 if (size < 0)
  return ((void*)0) ;
 oldsize = D_80011BD8 (pool, address) ;
 if (oldsize)
 {
  newaddr = func_80011EC0 (pool, size) ;
  if (newaddr != address)
  {
   source = (unsigned long*) address ;
   dest = (unsigned long*) newaddr ;
   if (size < oldsize)
    count = size ;
   else
    count = oldsize ;
   for (i = 0 ; i < count ; i += 4)
    *dest++ = *source++ ;
  }
  return newaddr ;
 }
 else
  return ((void*)0) ;
}
