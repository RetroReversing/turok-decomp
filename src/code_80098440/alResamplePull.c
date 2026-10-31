#include "decompdecomp_sync_88507c151ce89be81e21.h"
#line 1 "func.c"
#line 2 "reference.c"
Acmd *alResamplePull(void *filter, s16 *outp, s32 outCnt, s32 sampleOffset, Acmd *p) 
{
    ALResampler *f = (ALResampler *)filter;
    Acmd        *ptr = p;
    s16         inp;
    s32         inCount;
    ALFilter    *source = f->filter.source;
    s32		incr;
    f32         finCount;
    
                  
                                        
      
    
    inp = AL_DECODER_OUT;

    if (!outCnt)
        return ptr;

    /*
     * check if resampler is required
     */
    if (f->upitch) {

	ptr = (*source->handler)(source, &inp, outCnt, sampleOffset, p);
	aDMEMMove(ptr++, inp, *outp, outCnt<<1);

    } else {

	/*
	 * clip to maximum allowable pitch
	 * FIXME: should we check for some minimum as well?
	 */
	if (f->ratio > MAX_RATIO) f->ratio = MAX_RATIO;

	/*
	 * quantize the pitch
	 */
	f->ratio = (s32)(f->ratio * UNITY_PITCH);
	f->ratio = f->ratio / UNITY_PITCH;

	/*
	 * determine how many samples to generate
	 */
	finCount = f->delta + (f->ratio * (f32) outCnt);
	inCount = (s32) finCount;
	f->delta = finCount - (f32)inCount;

	/*
	 * ask all filters upstream from us to build their command
	 * lists.
	 */
	ptr = (*source->handler)(source, &inp, inCount, sampleOffset, p);

	/*
	 * construct our portion of the command list
	 */
	incr = (s32)(f->ratio * UNITY_PITCH);
	aSetBuffer(ptr++, 0, inp, *outp, outCnt<<1);
	aResample(ptr++, f->first, incr, osVirtualToPhysical(f->state));
	f->first = 0;
    }
    
                  
                                                                            
      
    return ptr;
}

