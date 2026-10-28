#include "common.h"

typedef struct Node { struct Node *next; s32 pad; u32 key; } Node;
typedef struct { Node **buckets; u32 bucketCount; s32 num; Node *freeList; } Pool;
s32 func_8002DE54(Pool *p, u32 key) {
 Node *n; Node **link;
 if (p->buckets == 0) return 0;
 link=&p->buckets[(key>>4)%p->bucketCount]; n=*link;
 while (n != 0) {
   if(key==n->key){ *link=n->next; n->next=p->freeList; p->freeList=n; p->num--; return 1; }
   link=&n->next; n=n->next;
 }
 return 0;
}
