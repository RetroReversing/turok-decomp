#include "common.h"

typedef struct Entry{struct Entry*next;u8 p[0x2D];u8 id31,id32,id33,p34,state35;}Entry;typedef struct{u8 p[0x64];Entry*head;}List;
Entry*func_800AB76C(List*a,u8 x,u8 y){Entry*v=a->head; while(v){if(v->id32==x && v->id31==y && v->state35!=3 && v->state35!=4)return v;v=v->next;}return 0;}
