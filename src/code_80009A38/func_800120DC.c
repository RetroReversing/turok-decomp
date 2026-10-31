#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct s_Memory {struct s_Memory *prev,*next;void *addr;int size;} t_Memory;
typedef struct {void *addr;int size;t_Memory *free_head,*free_tail,*used_head;} t_MemoryPool;
extern t_MemoryPool D_80119C90;
void *func_80011EC0(t_MemoryPool*,int);
#define i3D_malloc(n) func_80011EC0(&D_80119C90,n)
#line 168 "memory.c"
t_MemoryPool *func_800120DC (int size)
{
	t_MemoryPool	*pool ;
	int				total_size ;

	total_size = size + sizeof (t_MemoryPool) + sizeof (t_Memory) ;
	pool = (t_MemoryPool*) i3D_malloc(total_size) ;

	if (pool)
	{
	 	pool->addr = (void *)pool ;
	 	pool->size = total_size ;
	 	pool->free_head = (t_Memory *)((int)pool + sizeof (t_MemoryPool)) ;
	 	pool->free_tail = pool->free_head ;
		pool->free_head->prev = NULL ;
		pool->free_head->next = NULL ;
		pool->free_head->addr = (void *)((int)pool->free_head + sizeof (t_Memory)) ;
		pool->free_head->size = size ;

	 	pool->used_head = NULL ;
	}

	return pool ;
}

