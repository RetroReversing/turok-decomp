#include "decompdecomp_sync_534464c15286c4ba87ba.h"
#line 1 "func.c"
#line 469 "reference.c"
int		func_80011BD8 (t_MemoryPool *pool, void *address)
{
	t_Memory	*pointer ;
	t_Memory	*prev ;
	t_Memory	*next ;
	t_Memory	*free ;
	int			size ;

	if (address == NULL)
	{
		ASSERT(FALSE);
		return FALSE ;
	}


	pointer = (t_Memory*)( ((UINT32)address) - sizeof(t_Memory) ) ;

	if (pointer->addr == address)
	{
		size = pointer->size ;
//		pointer->addr = NULL ;

		//---	Remove deallocated memory from used linked list
		prev = pointer->prev ;
		next = pointer->next ;

		if (prev)
			prev->next = next ;
		if (next)
			next->prev = prev ;

		if (pool->used_head == pointer)
			pool->used_head = next ;


		//---	Find position to insert free entry
		free = pool->free_head ;
		prev = NULL ;

		while (free)
		{
			if (free->addr > address)
				break ;

			prev = free ;
			free = free->next ;
		}

		//---	Insert free entry in found position
		if (free == pool->free_head)
		{
				//TRACE0 ("Free at head\n") ;
			//---	Insert entry at head of list
			pointer->prev = NULL ;
			pointer->next = pool->free_head ;
 			free->prev = pointer ;
			pool->free_head = pointer ;
		}
		else
		{
			if (free == NULL)
			{
					//TRACE0 ("Free at tail\n") ;
				//---	Insert entry at end of list
				prev->next = pointer ;
				pointer->prev = prev ;
				pointer->next = NULL ;
				pool->free_tail = pointer ;
			}
			else
			{
					//TRACE0 ("Free in middle\n") ;
				//---	Insert entry somewhere in the middle of list
				prev->next = pointer ;
				pointer->prev = prev ;
				pointer->next = free ;
				free->prev = pointer ;
			}
		}


		//---	Check if new entry can be combined with previous and next entries
		prev = pointer->prev ;
		next = pointer->next ;

		if (prev)
		{
			if ((int)pointer == ((int)prev->addr + prev->size))
			{
				prev->size += pointer->size + sizeof (t_Memory) ;
				prev->next = next ;

				if (next)
					next->prev = prev ;

				if (pool->free_tail == pointer)
					pool->free_tail = prev ;

				pointer = prev ;

						//TRACE0 ("Link Prev\n");
			}
		}

		if (next)
		{
			if ((int)next == ((int)pointer->addr + pointer->size))
			{
				pointer->size += next->size + sizeof (t_Memory) ;

				if (pool->free_tail == next)
					pool->free_tail = pointer ;

				next = next->next ;

				pointer->next = next ;

				if (next)
					next->prev = pointer ;

						//TRACE0 ("Link Next\n");
			}
		}
		else
			pool->free_tail = pointer ;

//		pointer->addr = NULL ;

		return	size ;
	}
	else
	{
		ASSERT(FALSE);
	}

	return	FALSE ;
}

