#include "common.h"

typedef struct { s16 a,b; u8 c; } Desc;
typedef struct Link Link; struct Link { char p0[8]; Link *next; void *owner; char p10[4]; s16 x,y,z,w; };
typedef struct Obj Obj; struct Obj { char p0[8]; void (*fn)(Obj *,s32,void *); };
typedef struct { char p0[8]; Link *next; Obj *owner; char p10[0xC8]; s32 value; } Found;
typedef struct { char p0[0x1c]; s32 value; } State;
typedef struct { s32 a,b; s16 kind; s16 pad; s32 c,d; } Event;
extern Event *__allocParam();
extern s32 _allocatePVoice(State *, Found **, s16);
s32 alSynAllocVoice(State *state, Link *link, Desc *desc) {
    Found *found=0; Obj *owner; Event *ev; s32 ok;
    link->y=desc->a; link->w=desc->c; link->owner=0; link->z=desc->b; link->next=0; link->x=0;
    ok=_allocatePVoice(state,&found,desc->a);
    if(found) {
       owner=found->owner;
       if(ok) {
         found->value=0x200; found->next->next=0;
         ev=__allocParam();
         ev->b=state->value;ev->c=0;ev->kind=11;ev->d=found->value-0x40;
         owner->fn(owner,3,ev);
         ev=__allocParam();
         if(ev){ev->b=state->value+found->value;ev->a=0;ev->kind=15;owner->fn(owner,3,ev);}
       } else found->value=0;
       found->next=link;link->next=found;
    }
    return found!=0;
}
