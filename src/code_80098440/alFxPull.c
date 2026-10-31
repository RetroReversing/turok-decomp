#include "decompdecomp_sync_462fb6042280f42bff92.h"
#line 1 "func.c"
#line 2 "reference.c"
Acmd *alFxPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset,
                     Acmd *p) 
{
    Acmd        *ptr = p;
    ALFx	*r = (ALFx *)filter;
    ALFilter    *source = r->filter.source;
    s16		i, buff1, buff2, input, output;
    s16		*in_ptr, *out_ptr, gain, *prev_out_ptr = 0;
    ALDelay	*d, *pd;

                  
                                        
      
    
    assert(source);
    /*
     * pull channels going into this effect first
     */
    ptr = (*source->handler)(source, outp, outCount, sampleOffset, p);

    input  = AL_AUX_L_OUT;
    output = AL_AUX_R_OUT;
    buff1  = AL_TEMP_0;
    buff2  = AL_TEMP_1;
    
    aSetBuffer(ptr++, 0, 0, 0, outCount<<1);  /* set the buffer size */
    aMix(ptr++, 0, 0xda83, AL_AUX_L_OUT, input); /* .707L = L - .293L */
    aMix(ptr++, 0, 0x5a82, AL_AUX_R_OUT, input); /* mix the AuxL and AuxR into the AuxL */
    /* and write the mixed value to the delay line at r->input */
    ptr = _saveBuffer(r, r->input, input, outCount, ptr);

    aClearBuffer(ptr++, output, outCount<<1); /* clear the AL_AUX_R_OUT */

    for (i = 0; i < r->section_count; i++) {
	d  = &r->delay[i];  /* get the ALDelay structure */
	in_ptr  = &r->input[-d->input];
	out_ptr = &r->input[-d->output];
	
	if (in_ptr == prev_out_ptr) {
	    SWAP(buff1, buff2);
	} else {  /* load data at in_ptr into buff1 */
	    ptr = _loadBuffer(r, in_ptr, buff1, outCount, ptr);
	}
	ptr = _loadOutputBuffer(r, d, buff2, outCount, ptr);

	if (d->ffcoef) {
	    aMix(ptr++, 0, (u16)d->ffcoef, buff1, buff2);
	    if (!d->rs && !d->lp) {
		ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);
	    }
	}
	
	if (d->fbcoef) {
	    aMix(ptr++, 0, (u16)d->fbcoef, buff2, buff1);
	    ptr = _saveBuffer(r, in_ptr, buff1, outCount, ptr);
	}

	if (d->lp)
	    ptr = _filterBuffer(d->lp, buff2, outCount, ptr);

	if (!d->rs)
	    ptr = _saveBuffer(r, out_ptr, buff2, outCount, ptr);
	
	if (d->gain)
	    aMix(ptr++, 0, (u16)d->gain, buff2, output);
	
	prev_out_ptr = &r->input[d->output];
    }

    /*
     * bump the master delay line input pointer
     * modulo the length
     */
    r->input += outCount;
    if (r->input > &r->base[r->length])
	r->input -= r->length;

    /*
     * output already in AL_AUX_R_OUT
     *      just copy to AL_AUX_L_OUT
     */
    aDMEMMove(ptr++, output, AL_AUX_L_OUT, outCount<<1);

                  
                                                                
      
    return ptr;
}

