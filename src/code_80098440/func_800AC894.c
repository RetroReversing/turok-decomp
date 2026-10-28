#include "common.h"

typedef unsigned char U8;
typedef unsigned short U16;
typedef signed int S32;
typedef struct Node
{
  struct Node *next;
} Node;
S32 func_800AB560(void *a, S32 target);
extern void func_800AB1A4(void *, S32);
unsigned char func_800AC894(void *a)
{
  U8 *new_var;
  U8 n = *(((U8 *) a) + 0x34);
  S32 i = 0;
  S32 off = 0;
  if ((*(((U8 *) a) + 0x34)) > 0)
  {
    do
    {
      *((S32 *) ((*((char **) (((char *) a) + 0x60))) + off)) = 0;
      func_800AB1A4(a, i);
      i++;
      off += 16;
      new_var = ((U8 *) a) + 0x34;
      n = *new_var;
    }
    while (((0, i)) < (*(((U8 *) a) + 0x34)));
  }
}

extern S32 func_8009D220(S32);
extern void func_800A4E60(void *);
extern void func_800A4E90(void *, void *);
extern void func_800B1500(void *, void *, S32);
S32 func_800ACCD0(void *a, U16 *out);
extern void *func_800A5170(void);
void func_800ACE20(void *a, void *b);
