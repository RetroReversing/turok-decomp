#include "common.h"

typedef struct Node
{
  struct Node *next;
  char pad4[4];
  s32 value;
  s16 kind;
  char pade[2];
  void *owner;
} Node;
typedef struct Event
{
  s16 kind;
  s16 pad;
  void *owner;
} Event;
typedef struct Local
{
  char pad[16];
  Event event;
} Local;
extern void alUnlink(Node *);
extern void alLink(Node *, void *);
extern void alEvtqPostEvent(void *, Event *, s32);
extern void alSynSetVol(void *, void *, s32, s32);
extern void func_800B14F0(void *, void *, s32);
void __seqpReleaseVoice(char *arg0, char *arg1, s32 arg2)
{
  Node *next;
  char *state = *((char **) (arg1 + 0x10));
  Local local;
  Node *node;
  if (state[0x34] == 0)
  {
    node = *((Node **) (arg0 + 0x50));
    if (node != 0)
    {
      do
      {
        next = node->next;
        if ((node->kind == 6) && (arg1 == node->owner))
        {
          if (next != 0)
          {
            next->value += node->value;
          }
          alUnlink(node);
          alLink(node, arg0 + 0x48);
        }
        node = next;
      }
      while (next != 0);
    }
  }
  state[0x33] = 0;
  state[0x34] = 3;
  state[0x30] = 0;
  *((s32 *) (state + 0x24)) = (*((s32 *) (arg0 + 0x1c))) + arg2;
  func_800B14F0(*((void **) (arg0 + 0x14)), arg1, 0);
  alSynSetVol(*((void **) (arg0 + 0x14)), arg1, 0, arg2);
  local.event.kind = 5;
  local.event.owner = arg1;
  alEvtqPostEvent(arg0 + 0x48, &local.event, arg2);
}
