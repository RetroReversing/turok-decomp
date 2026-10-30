#include "common.h"

extern s32 _timeToSamples(void *, s32, void *, void *);
extern void *__allocParam(void);
void alSynStartVoiceParams(void *a0, void *a1, s32 a2, f32 a3, s16 a4, u8 a5, u8 a6, s32 a7)
{
  void *buf;
  
  if ((*((void **) (((u8 *) a1) + 8))) != 0)
  {
    buf = __allocParam();
    if (buf != 0)
    {
      if (a6 < 0) a6 = -a6;
 *((s32 *) (((u8 *) buf) + 4)) = (*((s32 *) (((u8 *) (*((void **) (((u8 *) a1) + 8)))) + 0xd8))) + (*((s32 *) (((u8 *) a0) + 0x1c))); *((s16 *) (((u8 *) buf) + 8)) = 13; *((s32 *) ((u8 *) buf)) = 0;
      *((s16 *) (((u8 *) buf) + 0xa)) = *((s16 *) (((0, (u8 *) a1)) + 0x1a));
      *(((u8 *) buf) + 0x12) = a5;
      *((s16 *) (((u8 *) buf) + 0x10)) = a4;
      *(((u8 *) buf) + 0x13) = a6;
      *((f32 *) (((u8 *) buf) + 0xc)) = a3;
      *((s32 *) (((u8 *) buf) + 0x14)) = _timeToSamples(a0, a7, buf, a1);
      *((s32 *) (((u8 *) buf) + 0x18)) = a2;
      {
        void *o = *((void **) (((u8 *) (*((void **) (((u8 *) a1) + 8)))) + 0xc));
        ((void (*)(void *, s32, void *, void *)) (*((void **) (((u8 *) o) + 8))))(o, 3, buf, a1);
 } }
  }
}
