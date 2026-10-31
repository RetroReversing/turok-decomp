#include "common.h"

typedef struct {void *data;s32 automatic;s32 size;} Set;
int func_80011DDC(void*);
void func_8002D978(Set *p,void *data,s32 automatic)
{
 if(p->data && p->automatic)
  func_80011DDC(p->data);
 p->data=data;
 p->size=0;
 p->automatic=automatic;
}
