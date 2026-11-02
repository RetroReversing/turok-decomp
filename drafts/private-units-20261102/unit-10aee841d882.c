
#line 32 "reference-macro.c"
#define ADPCMFBYTES      9
#line 33 "reference-macro.c"
#define LFSAMPLES        4

static Acmd *func_800AE5C0(Acmd *,ALLoadFilter *,s32,s32,s16,s16,u32);
Acmd *alAdpcmPull(void *filter, s16 *outp, s32 outCount, s32 sampleOffset, Acmd *p) 
{
    Acmd        *ptr = p;
    s16         inp;
    s32         tsam;
    s32         nframes;
    s32         nbytes;
    s32         overFlow;
    s32         startZero;
    s32         nOver;
    s32         nSam;
    s32         op;
    s32         nLeft;
    s32         bEnd;
    s32         decoded = 0;
    s32         looped = 0;
    
    ALLoadFilter *f = (ALLoadFilter *)filter;

                  
                                        
      

    if (outCount == 0)
        return ptr;

    inp = AL_DECODER_IN;
    aLoadADPCM(ptr++, f->bookSize,
               K0_TO_PHYS(f->table->waveInfo.adpcmWave.book->book));

    looped = (outCount + f->sample > f->loop.end) && (f->loop.count != 0);
    if (looped)
        nSam = f->loop.end - f->sample;
    else
        nSam = outCount;
    
    if (f->lastsam)
        nLeft = ADPCMFSIZE - f->lastsam;
    else
        nLeft = 0;
    tsam = nSam - nLeft;
    if (tsam<0) tsam = 0;
    
    nframes = (tsam+ADPCMFSIZE-1)>>LFSAMPLES;
    nbytes =  nframes*ADPCMFBYTES;

    if (looped){

        ptr = func_800AE5C0(ptr, f, tsam, nbytes, *outp, inp, f->first);

        /*
         * Fix up output pointer, which will be used as the input pointer
         * by the following module.
         */
        if (f->lastsam)
            *outp += (f->lastsam<<1);
        else
            *outp += (ADPCMFSIZE<<1);

        /*
         * Now fix up state info to reflect the loop start point
         */
        f->lastsam = f->loop.start &0xf;
        f->memin = (s32) f->table->base + ADPCMFBYTES *
            ((s32) (f->loop.start>>LFSAMPLES) + 1);
        f->sample = f->loop.start;

        bEnd = *outp;
        while (outCount > nSam){
            
            outCount -= nSam;
            
            /*
             * Put next one after the end of the last lot - on the
             * frame boundary (32 byte) after the end.
             */
            op = (bEnd + ((nframes+1)<<(LFSAMPLES+1))) & ~0x1f;

            /*
             * The actual end of data
             */
            bEnd += (nSam<<1);
            
            /*
             * -1 is loop forever - the loop count is not exact now
             * for small loops!
             */
            if ((f->loop.count != -1) && (f->loop.count != 0))
                f->loop.count--;
            
            /*
             * What's left to compute.
             */
            nSam = MIN(outCount, f->loop.end - f->loop.start);
            tsam = nSam - ADPCMFSIZE + f->lastsam;  
            if (tsam<0) tsam = 0;
            nframes = (tsam+ADPCMFSIZE-1)>>LFSAMPLES;
            nbytes =  nframes*ADPCMFBYTES;
            ptr = func_800AE5C0(ptr, f, tsam, nbytes, op, inp, f->first | A_LOOP);
            /*
             * Merge the two sections in DMEM.
             */
            aDMEMMove(ptr++, op+(f->lastsam<<1), bEnd, nSam<<1);

        }
        
        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += ADPCMFBYTES*nframes;    
                  
                                                                
      
        return ptr;
    }

    /*
     * The unlooped case, which is executed most of the time
     */

    nSam = nframes<<LFSAMPLES;
    
    /*
     * overFlow is the number of bytes past the end
     * of the bitstream I try to generate
     */
    overFlow = f->memin + nbytes - ((s32) f->table->base + f->table->len);
    if (overFlow < 0)
        overFlow = 0;
    nOver = (overFlow/ADPCMFBYTES)<<LFSAMPLES;
    if (nOver > nSam + nLeft)
        nOver = nSam + nLeft;
    
    nbytes -= overFlow;

    if ((nOver - (nOver & 0xf))< outCount){
        decoded = 1;
        ptr = func_800AE5C0(ptr, f, nSam - nOver, nbytes, *outp, inp, f->first);
    
        if (f->lastsam)
            *outp += (f->lastsam<<1);
        else
            *outp += (ADPCMFSIZE<<1);

        f->lastsam = (outCount + f->lastsam) & 0xf;
        f->sample += outCount;
        f->memin += ADPCMFBYTES*nframes;    
    } else {        
        f->lastsam = 0;
        f->memin += ADPCMFBYTES*nframes;    
    }

    /*
     * Put zeros in if necessary
     */
    if (nOver){
        f->lastsam = 0;
        if (decoded)
            startZero = (nLeft + nSam - nOver)<<1;
        else
            startZero = 0;
        aClearBuffer(ptr++, startZero + *outp, nOver<<1);
    }
                  
                                                            
      

    return ptr;
}

Acmd *func_800AE5C0(Acmd *ptr, ALLoadFilter *f, s32 tsam, s32 nbytes, s16 outp, s16 inp, u32 flags)

{

    s32
        dramAlign,
        dramLoc;
    
    if (nbytes > 0){
        dramLoc = (f->dma)(f->memin, nbytes, f->dmaState);
        /*
         * Make sure enough is loaded into DMEM to take care
         * of 8 byte alignment
         */
        dramAlign = dramLoc & 0x7;
        nbytes += dramAlign;
        aSetBuffer(ptr++, 0, inp, 0, nbytes + 8 - (nbytes & 0x7));
        aLoadBuffer(ptr++, dramLoc - dramAlign);
    } else
        dramAlign = 0;

    if (flags & A_LOOP){
        aSetLoop(ptr++, K0_TO_PHYS(f->lstate));
    }
    
    aSetBuffer(ptr++, 0, inp + dramAlign, outp, tsam<<1);
    aADPCMdec(ptr++, flags, K0_TO_PHYS(f->state));
    f->first = 0;

    return ptr;
}

