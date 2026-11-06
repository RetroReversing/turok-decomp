#include "common.h"

typedef struct {void *data;s32 automatic;s32 size;} Set;
int i3D_free(void*);
void func_8002DCCC(Set *p,void *data,s32 automatic)
{
 if(p->data && p->automatic)
  i3D_free(p->data);
 p->data=data;
 p->automatic=automatic;
}
