#include "common.h"

typedef struct SolNode {struct SolNode *next;} SolNode;
typedef struct {s32 pad[11];SolNode *head;} SolOwner;
extern SolOwner *D_800EF260;
SolNode *func_800A5170(void){SolOwner *o;SolNode *r;SolNode *n;o=D_800EF260;r=0;n=o->head;if(n){o->head=n->next;r=n;n->next=0;}return r;}
