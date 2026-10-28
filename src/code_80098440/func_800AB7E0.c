#include "common.h"

typedef struct Entry{struct Entry*next;u8 p[0x2d];volatile u8 id31,id32,id33;u8 p34,state35;}Entry;typedef struct{u8 p[0x64];Entry*head,*tail,*free;}List; Entry*func_800AB7E0(List*a,u8 x,u8 y,u8 z){Entry*v=a->free;if(v){a->free=v->next;v->next=0;if(a->head==0)a->head=v;else a->tail->next=v;a->tail=v;v->id31=z;v->id32=x;v->id33=y;*(volatile Entry**)((u8*)v+0x14)=v;}return v;}
