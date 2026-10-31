#include "common.h"

typedef struct SolNode {struct SolNode *next;s32 pad[3];s32 value;} SolNode;
typedef struct {SolNode*head;s32 pad[7];s32 value;} SolOwner;
s32 func_8009D220(s32);
void alSynAddPlayer(SolOwner*a,SolNode*b){s32 state;state=func_8009D220(1);b->value=a->value;b->next=a->head;a->head=b;func_8009D220(state);}
