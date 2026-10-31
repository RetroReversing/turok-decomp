#include "decompdecomp_sync_a61e2d90e4ef895ca18b.h"
#line 1 "func.c"
#line 2 "reference.c"
Acmd *_loadOutputBuffer(ALFx *r, ALDelay *d, s32 buff, s32 incount, Acmd *p)
{
    Acmd	*ptr = p;
    s32		ratio, count, rbuff = AL_TEMP_2;
    s16		*out_ptr;
    f32         fincount, fratio, delta;
    s32		ramalign = 0, length;
    static f32	val=0.0, lastval=-10.0;
    static f32	blob=0;

    if (d->rs) {
      length = d->output - d->input;
      delta = _doModFunc(d, incount);
      /*
       * find ratio of delta to delay length and quantize
       *  to same resolution as resampler
       */
      delta /= length;
      delta = (s32)(delta * UNITY_PITCH);
      delta = delta / UNITY_PITCH;
      fratio = 1.0 - delta;
      
      fincount = d->rs->delta + (fratio * (f32)incount);
      count = (s32) fincount;
      d->rs->delta = fincount - (f32)count;

      out_ptr = &r->input[-(d->output - d->rsdelta)];
      ramalign = ((s32)out_ptr & 0x7) >> 1;

             
                                               
                                                                       
       
      
      ptr = _loadBuffer(r, out_ptr - ramalign, rbuff, count + ramalign, ptr);

      ratio = (s32)(fratio * UNITY_PITCH);
      aSetBuffer(ptr++, 0, rbuff + (ramalign<<1), buff, incount<<1);
      aResample(ptr++, d->rs->first, ratio, osVirtualToPhysical(d->rs->state));
      d->rs->first = 0;
      d->rsdelta += count - incount;
    } else {
      out_ptr = &r->input[-d->output];
      ptr = _loadBuffer(r, out_ptr, buff, incount, ptr);
    }

    return ptr;

}

