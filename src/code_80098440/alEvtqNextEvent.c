#include "common.h"

typedef struct Link {struct Link *next,*prev;} Link;
typedef struct {s16 type;u8 data[14];} Event;
typedef struct {Link node;s32 delta;Event evt;} Item;
typedef struct {Link freeList,allocList;s32 count;} Queue;
extern s32 func_8009D220(s32);extern void alUnlink(Link*);extern void alLink(Link*,Link*);extern void alCopy(void*,void*,s32);
s32 alEvtqNextEvent(Queue *evtq,Event *evt)
{
 Item *item;
 s32 delta;
 s32 mask;
 mask=func_8009D220(1);
 item=(Item*)evtq->allocList.next;
 if(item)
 {
  alUnlink((Link*)item);
  alCopy(&item->evt,evt,sizeof(*evt));
  alLink((Link*)item,&evtq->freeList);
  delta=item->delta;
 }
 else
 {
  evt->type=-1;
  delta=0;
 }
 func_8009D220(mask);
 return delta;
}
