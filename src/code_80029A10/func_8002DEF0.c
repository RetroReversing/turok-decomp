#include "common.h"

typedef struct Assoc {struct Assoc *next;u32 hash;void *key,*value;} Assoc;
typedef struct Plex {struct Plex *next;u32 max,cur;} Plex;
typedef struct {void *table;u32 tableSize;s32 count;Assoc *freeList;Plex *blocks;s32 blockSize;} Hash;
extern void *func_80011E98(s32);
static __inline Plex *Create(Plex **head,u32 max,u32 element)
{
 Plex *p;

 p=(Plex*)func_80011E98(sizeof(Plex)+max*element);
 p->max=max;
 p->cur=0;
 p->next=*head;
 *head=p;
 return p;
}
Assoc *func_8002DEF0(Hash *h)
{
 Plex *block;
 Assoc *a;
 int i;
 if(h->freeList==0)
 {
  block=Create(&h->blocks,h->blockSize,sizeof(Assoc));
  a=(Assoc*)(block+1);
  a+=h->blockSize-1;
  for(i=h->blockSize-1;i>=0;i--,a--)
  {
   a->next=h->freeList;
   h->freeList=a;
  }
 }
 a=h->freeList;
 h->freeList=h->freeList->next;
 h->count++;
 a->key=a->value=0;
 return a;
}
