#include "common.h"

typedef unsigned short U16; typedef signed int S32;
extern void *__allocParam(void);
void alSynStopVoice(void *a, void *b)
{
  void *p;
  void *q;
  U16 code;
  if (*((void **) (((char *) b) + 8)))
  {
    p = __allocParam();
    if (p)
    {
      code = 15;
      *((S32 *) (((char *) p) + 4)) = (*((S32 *) (((char *) (*((void **) (((char *) b) + 8)))) + 0xd8))) + (*((S32 *) (((char *) a) + 0x1c)));
 *((S32 *) ((char *) p)) = 0; *((U16 *) (((char *) p) + 8)) = code;
      q = *((void **) (((char *) (*((void **) (((char *) b) + 8)))) + 0xc));
      ((void (*)(void *, S32, void *, void *))(*((void **)((char *)q + 8))))(q, 3, p, b);
    }
  }
}
