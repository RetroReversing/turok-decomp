#include "context_8d698fdff8b3.h"
#line 1 "func.c"
typedef struct Item Item;
struct Item
{
  Item *next;
  u8 pad[4];
  void *obj;
  u8 pad2[0xcc];
  s32 flag;
};
typedef struct 
{
  u8 pad0[4];
  Item *head;
  u8 pad8[4];
  Item *list;
  void *field10;
  Item *field14;
} Container;
typedef struct 
{
  u8 pad[0x16];
  s16 index;
} ItemData;
void alUnlink(void *, Item **, s32, void *);
void alLink(void *, void *);
s32 _allocatePVoice(Container *arg0, Item **out, s32 arg2)
{
  Item *item;
  ItemData *data;
  s32 found = 0;
  arg2 = arg2;
  if (arg0->field14 != 0)
  {
    item = arg0->field14;
    *out = item;
    alUnlink(item, out, arg2, item);
    alLink(item, ((u8 *) arg0) + 0xC);
  }
  else
  {
    item = arg0->head;
    if (item != 0)
    {
      *out = item;
      alUnlink(item, out, arg2, item);
      alLink(item, ((u8 *) arg0) + 0xC);
    }
    else
    {
      item = arg0->list;
      if (item != 0)
      {
        do
        {
          data = item->obj;
          if (((!out) && (!out)) && (!out))
          {
          }
          if ((arg2 >= data->index) && (item->flag == 0))
          {
            *out = item;
            found = 1;
            arg2 = data->index;
          }
          item = item->next;
        }
        while (item != 0);
      }
    }
  }
  return found;
}

