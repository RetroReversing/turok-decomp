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
extern int i3D_memoryCheck (t_MemoryPool *pool) ;
extern t_MemoryPool D_80119C90 ;
extern signed long D_80119CA4 ;
int i3D_memoryCheck (t_MemoryPool *pool);
int		i3D_memoryCheck (t_MemoryPool *pool)
{
	t_Memory	*pointer ;
	//int			total_size ;
	int			size ;
	int			largest ;

	size = 0 ;

	//---	Find free allocation slot
	if (pool == 0)
		pool = &D_80119C90 ;

	pointer = pool->free_head ;
	//total_size = size + sizeof (t_Memory) ;

	largest = 0 ;

	while (pointer)
	{
		if (pointer->size > largest)
			largest = pointer->size ;

		size += pointer->size ;
		pointer = pointer->next ;
	}

	D_80119CA4 = largest ;

	return size ;
}
