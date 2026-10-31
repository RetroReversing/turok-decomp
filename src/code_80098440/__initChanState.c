#include "common.h"

typedef unsigned char U8;
typedef unsigned short U16;
typedef signed int S32;
typedef struct Node
{
  struct Node *next;
} Node;
S32 __unmapVoice(void *a, S32 target);
extern void __resetPerfChanState(void *, S32);
unsigned char __initChanState(void *a)
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
      __resetPerfChanState(a, i);
      i++;
      off += 16;
      new_var = ((U8 *) a) + 0x34;
      n = *new_var;
    }
    while (((0, i)) < (*(((U8 *) a) + 0x34)));
  }
}

extern S32 func_8009D220(S32);
extern void alUnlink(void *);
extern void alLink(void *, void *);
extern void alCopy(void *, void *, S32);
S32 alEvtqNextEvent(void *a, U16 *out);
extern void *__allocParam(void);
void alSynStopVoice(void *a, void *b);
