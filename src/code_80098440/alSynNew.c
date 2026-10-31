#include "decompdecomp_sync_a1797edb49f6062e46da.h"
#line 1 "func.c"
#line 2 "reference.c"
void alSynNew(ALSynth *drvr, ALSynConfig *c)
{
    s32         i;
    ALVoice     *vv;
    PVoice      *pv;
    ALVoice     *vvoices;
    PVoice      *pvoices;
    ALHeap      *hp = c->heap;
    ALSave      *save;
    ALFilter    *sources;
    ALParam     *params;
    ALParam     *paramPtr;
    
    drvr->head            = NULL;
    drvr->numPVoices      = c->maxPVoices;
    drvr->curSamples      = 0;
    drvr->paramSamples    = 0;
    drvr->outputRate      = c->outputRate;
    drvr->maxOutSamples   = AL_MAX_RSP_SAMPLES;
    drvr->dma             = (ALDMANew) c->dmaproc;

    save = alHeapAlloc(hp, 1, sizeof(ALSave));
    alSaveNew(save);
    drvr->outputFilter = (ALFilter *)save;

    /*
     * allocate and initialize the auxilliary effects bus. at present
     * we only support 1 effects bus.
     */
    drvr->auxBus = alHeapAlloc(hp, 1, 0x4c /* allocation extent observed at the retail call site */);
    drvr->maxAuxBusses = 1;
    sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
    alAuxBusNew(drvr->auxBus, sources, c->maxPVoices);

    /*
     * allocate and initialize the main bus.
     */
    drvr->mainBus = alHeapAlloc(hp, 1, sizeof(ALMainBus));
    sources = alHeapAlloc(hp, c->maxPVoices, sizeof(ALFilter *));
    alMainBusNew(drvr->mainBus, sources, c->maxPVoices);

    if (c->fxType != AL_FX_NONE){
        /*
         * Allocate an effect and set parameters
         */
        alSynAllocFX(drvr, 0, c, hp);
    } else
        /*
         * Connect the aux bus to the main bus
         */
    	func_800ADEF0(drvr->mainBus, AL_FILTER_ADD_SOURCE, &drvr->auxBus[0]);
    
    /*
     * Build the physical voice lists
     */
    drvr->pFreeList.next = 0;
    drvr->pFreeList.prev = 0;
    drvr->pLameList.next = 0;
    drvr->pLameList.prev = 0;
    drvr->pAllocList.next = 0;
    drvr->pAllocList.prev = 0;

    pvoices = alHeapAlloc(hp, c->maxPVoices, sizeof(PVoice));
    for (i = 0; i < c->maxPVoices; i++) {
        pv = &pvoices[i];
        alLink((ALLink *)pv, &drvr->pFreeList);
        pv->vvoice = 0;

        alLoadNew(&pv->decoder, drvr->dma, hp);
        alLoadParam(&pv->decoder, AL_FILTER_SET_SOURCE, 0);
    
        alResampleNew(&pv->resampler, hp);
        alResampleParam(&pv->resampler, AL_FILTER_SET_SOURCE, &pv->decoder);

        alEnvmixerNew(&pv->envmixer, hp);
        alEnvmixerParam(&pv->envmixer, AL_FILTER_SET_SOURCE, &pv->resampler);

        func_800AFAF0(drvr->auxBus, AL_FILTER_ADD_SOURCE, &pv->envmixer);
        
        pv->channelKnob   = (ALFilter *)&pv->envmixer;
    }
    
    alSaveParam(save, AL_FILTER_SET_SOURCE, drvr->mainBus);

    /*
     * build the parameter update list
     */
    params = alHeapAlloc(hp, c->maxUpdates, sizeof(ALParam));
    drvr->paramList = 0;
    for (i = 0; i < c->maxUpdates; i++) {
        paramPtr= &params[i];
        paramPtr->next = drvr->paramList;
        drvr->paramList = paramPtr;
    }
    
    drvr->heap = hp;
}

