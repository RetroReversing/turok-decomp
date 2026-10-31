#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 osVirtualToPhysical(s32);
extern f32 _doModFunc(void *, s32);
extern void *_loadBuffer();
void *_loadOutputBuffer(void *a, void *b, s32 c, s32 d, s32 e)
{
  s32 x;
  s32 y;
  s32 z;
  s32 u;
  s32 v;
  s32 w0;
  f32 q;
  f32 r;
  void *t;
  void *p;
  if (*((u32 *) (((u8 *) b) + 36)))
  {
    x = (*((s32 *) (((u8 *) b) + 4))) - (*((s32 *) b));
    q = (f32) (1.0 - ((f64) (((f32) ((s32) ((_doModFunc(b, d) / ((f32) x)) * 32768.0f))) / 32768.0f)));
    t = *((void **) (((u8 *) b) + 36));
    r = (*((f32 *) (((u8 *) t) + 32))) + (q * ((f32) d));
    y = (s32) r;
    *((f32 *) (((u8 *) t) + 32)) = r - ((f32) y);
    z = (*((s32 *) (((u8 *) b) + 24))) + (((*((s32 *) (((u8 *) b) + 4))) - (*((s32 *) (((u8 *) b) + 24)))) * (-2));
    u = (z & 7) >> 1;
    v = u * 2;
    p = _loadBuffer(a, z - v, c, 640, y + u, e, d);
    *((u32 *) p) = ((v + 640) & 65535) | 0x8000000;
    *((u32 *) (((u8 *) p) + 4)) = (c << 16) | ((d * 2) & 65535);
    *((u32 *) (((u8 *) p) + 8)) = (((((*((u32 *) (((u8 *) t) + 36))) & 255) << 11) << 5) | 0x5000000) | (((s32) (q * 32768.0f)) & 65535);
    *((u32 *) (((u8 *) p) + 12)) = osVirtualToPhysical(*((s32 *) (((u8 *) t) + 20)));
    *((u32 *) (((u8 *) t) + 36)) = 0;
    *((s32 *) (((u8 *) b) + 24)) = ((*((s32 *) (((u8 *) b) + 24))) + y) - d;
    return ((u8 *) p) + 16;
  }
  w0 = e;
  z = *((s32 *) (((u8 *) b) + 4));
  return _loadBuffer(a, (*((s32 *) (((u8 *) a) + 24))) - ((z *= 2)), c, d, e);
}

