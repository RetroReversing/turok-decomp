#include "common.h"

s32 __alSeqNextDelta(void *, s32 *);
s32 func_800B0F08(void *);
void func_800B0EEC(void *, s32);
void alEvtqPostEvent(void *, s16 *, u32);
typedef struct 
{
  u8 pad0[0x18];
  void *p18;
  u8 pad1[0x08];
  s32 p24;
  u8 pad26[4];
  s32 p2c;
  u8 pad2[0x4C];
  void *p7c;
  void *p80;
  s32 p84;
} S_AB5D0;
void __postNextSeqEvent(S_AB5D0 *p)
{
  struct {s16 type; u8 rest[14];} zero;
  s32 count;
  void *obj;
  obj = p->p18;
  if ((p->p2c == 1) && (obj != 0))
  {
    if (__alSeqNextDelta(obj, &count))
    {
      if ((p->p84 != 0) && ((func_800B0F08(obj) + count) >= (*((s32 *) (((u8 *) p->p80) + 8)))))
      {
        func_800B0EEC(obj, (s32) p->p7c);
        if (p->p84 != (-1))
        {
          p->p84--;
        }
        if ((p->p2c && p->p2c) && p->p2c)
        {
        }
      }
      zero.type = 0;
      alEvtqPostEvent(((u8 *) p) + 0x48, &zero.type, p->p24 * count);
    }
  }
}
