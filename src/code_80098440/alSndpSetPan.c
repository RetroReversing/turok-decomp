#include "common.h"

typedef struct 
{
  char pad[0x3c];
  s32 index;
  char *items;
} A;
typedef struct 
{
  s16 type;
  s16 pad;
  void *entry;
  s8 value;
  char extra[7];
} Cmd;
extern void alEvtqPostEvent(void *, Cmd *, s32);
void alSndpSetPan(A *a, u8 value)
{
  Cmd command;
  s32 new_var;
  char *items;
  items = a->items;
  command.type = 2;
  command.value = value;
  value = 0x14;
  ;
  command.entry = items + (a->index * 0x30);
  value += 0;
  alEvtqPostEvent(((char *) a) + value, &command, 0);
}
