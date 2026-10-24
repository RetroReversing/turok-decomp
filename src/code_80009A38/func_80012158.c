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
extern void func_80012158 (void *pAddress, int Size) ;
extern t_MemoryPool D_80119C90 ;
extern void *D_800B8710 ,
     *D_800B8714 ;
extern int D_800B8718 ;
void func_80012158 (void *pAddress, int Size);
void func_80012158 (void *pAddress, int Size){
 D_800B8710 = pAddress;
 D_800B8718 = Size;
 D_800B8714 = (void*) (((signed long)pAddress) + Size);
 D_80119C90.addr = 0 ;
  D_80119C90.size = 0 ;
 D_80119C90.free_head = (t_Memory *) pAddress ;
  D_80119C90.free_tail = D_80119C90.free_head ;
 D_80119C90.free_head->prev = 0 ;
 D_80119C90.free_head->next = 0 ;
 D_80119C90.free_head->addr = (void *)((int)D_80119C90.free_head + sizeof (t_Memory)) ;
 D_80119C90.free_head->size = Size - sizeof (t_Memory) ;
  D_80119C90.used_head = 0 ;
}
