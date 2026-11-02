#include "decompdecomp_sync_b65a55f69af9c1ca073f.h"
#line 1 "func.c"
#line 142 "reference.c"
Acmd *alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen)
{
    ALPlayer    *client;
    ALFilter    *output;
    ALSynth     *drvr = D_800EF260;
    s16         tmp = 0;        /* Starting buffer in DMEM */
    Acmd        *cmdlEnd = cmdList;
    Acmd        *cmdPtr;
    s32         nOut;
    s16         *lOutBuf = outBuf;

                  
                                        
      
    
    if (drvr->head == 0) {
	*cmdLen = 0;
        return cmdList;         /* nothing to do */
    }    

    /*
     * run down list of clients and execute callback if needed this
     * subframe. Here we do all the work for the frame at the
     * start. Time offsets that occur before the next frame are
     * executed "early".
     */

                  
                                        
      

    /*
     * paramSamples = time of next parameter change.
     * curSamples = current sample time.
     * so paramSamples - curSamples is the time until the next parameter change.
     * if the next parameter change occurs within this frame time (outLen),
     * then call back the client that contains the parameter change.
     * Note, paramSamples must be rounded down to 16 sample boundary for use
     * during the client handler.
     */

    for (drvr->paramSamples = __nextSampleTime(drvr, &client);
	 drvr->paramSamples - drvr->curSamples < outLen;
	 drvr->paramSamples = __nextSampleTime(drvr, &client))
    {
	drvr->paramSamples &= ~0xf;
	client->samplesLeft += _timeToSamplesNoRound(drvr, (*client->handler)(client));
    }

    /* for safety's sake, always store paramSamples aligned to 16 sample boundary.
     * this way, if an voice handler routine gets called outside the ALVoiceHandler
     * routine (alSynAllocVoice) it will get timestamped with an aligned value and
     * will be processed immediately next audio frame.
     */
    drvr->paramSamples &= ~0xf;


                  
                                                                
      

    /*
     * Now build the command list in small chunks
     */
    while (outLen > 0){
        nOut = MIN(drvr->maxOutSamples, outLen);

        /*
         * construct the command list for each physical voice by calling
         * the head of the filter chain.
         */
        cmdPtr = cmdlEnd;
        aSegment(cmdPtr++, 0, 0);
        output = drvr->outputFilter;
        (*output->setParam)(output, AL_FILTER_SET_DRAM, lOutBuf);
        cmdlEnd = (*output->handler)(output, &tmp, nOut, drvr->curSamples,
                                     cmdPtr);
        
        outLen -= nOut;
        lOutBuf += nOut<<1;     /* For Stereo */
        drvr->curSamples += nOut;
                
    }
    *cmdLen = (s32) (cmdlEnd - cmdList);

    _collectPVoices(drvr); /* collect free physical voices */
    
                  
                                                        
      
    return cmdlEnd;
}

