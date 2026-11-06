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
extern void *i3D_reallocPool (t_MemoryPool *pool, void *address, int size) ;
extern int D_80011BD8 (t_MemoryPool *pool, void *address) ;
void *i3D_mallocPool (t_MemoryPool *pool, int size);
void *i3D_reallocPool (t_MemoryPool *pool, void *address, int size);
int D_80011BD8 (t_MemoryPool *pool, void *address);
void *i3D_reallocPool (t_MemoryPool *pool, void *address, int size){
 void *newaddr ;
 unsigned long *source ;
 unsigned long *dest ;
 int i ;
 int oldsize ;
 int count ;
 /* --- Illegal allocation size ? */ if (size < 0)
  return ((void*)0) ;
 oldsize = D_80011BD8 (pool, address) ;
 if (oldsize)
 {
  newaddr = i3D_mallocPool (pool, size) ;
  /* printf ("old addr = %p\n", address) ; */ /* printf ("new addr = %p\n", newaddr) ; */ /* printf ("newsize = %d (%d)\n", size, oldsize) ; */ if (newaddr != address)
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
