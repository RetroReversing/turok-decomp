#include "common.h"

typedef struct 
{
  char pad[0x3c];
  s32 index;
  void *items;
} A;
typedef struct 
{
  char pad[0xD];
  u8 value;
} B;
typedef struct 
{
  char pad[0x18];
  s32 x;
} X;
typedef struct 
{
  char pad[0xB0];
} Y;
typedef struct 
{
  char pad[0x14];
} Z;
extern void func_800ACBAC(void *, void *, void *);
void func_800A3DF0(A *a, s8 v);
s16 func_800A3CF0(A *a, B *b)
{
  void *base = a->items;
  s16 i = 0;
  s32 count = *((s32 *) (((char *) a) + 0x44));
  if (count > 0)
  {
    do
    {
      char *e = ((char *) base) + (i * 0x30);
      if ((*((void **) (e + 0x1c))) == NULL)
      {
        *((void **) (e + 0x1c)) = b;
        *((s16 *) (e + 0x20)) = 5;
        *((s32 *) (e + 0x28)) = 0 & 0xFFFFFFFF;
        *((u8 *) (e + 0x2e)) = 0x40;
        *((u8 *) (e + 0x2f)) = 0;
        *((f32 *) (e + 0x24)) = 1.0f;
        *((s16 *) (e + 0x2c)) = ((s32) (b->value * 0x7fff)) / 127;
        return i;
      }
      i++;
    }
    while (i < count);
  }
  return -1;
}

void func_800A40C0(void *a0, void *a1);
void func_800A4160(void *a0, void *a1);
