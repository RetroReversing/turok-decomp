#include "common.h"

typedef struct {void *data;s32 automatic;s32 size;} Set;
int func_80011DDC(void*);
void func_8002DCCC(Set *p,void *data,s32 automatic)
{
 if(p->data && p->automatic)
  func_80011DDC(p->data);
 p->data=data;
 p->automatic=automatic;
}
