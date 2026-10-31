#include "decompdecomp_sync_a1797edb49f6062e46da.h"
#line 1 "func.c"
#line 2 "reference.c"
void alSndpNew(ALSndPlayer *sndp, ALSndpConfig *c) 
{    
    u8            *ptr;
    ALEvent       evt;
    ALSoundState  *sState;
    u32           i;

    /*
     * Init member variables
     */
    sndp->maxSounds = c->maxSounds;
    sndp->target = -1;
    sndp->frameTime = AL_USEC_PER_FRAME;        /* time between API events */
    sState = (ALSoundState*)alHeapAlloc(c->heap, 1,
                                        c->maxSounds * sizeof(ALSoundState));
    sndp->sndState = sState;

    for(i = 0; i < c->maxSounds; i++)
	sState[i].sound = 0;

    /*
     * init the event queue
     */
    ptr = alHeapAlloc(c->heap, 1, c->maxEvents * sizeof(ALEventListItem));
    alEvtqNew(&sndp->evtq, (ALEventListItem *)ptr, c->maxEvents);
    
    /*
     * add ourselves to the driver
     */
    sndp->drvr = D_800EF260;
    sndp->node.next = NULL;
    sndp->node.handler = func_800A366C;
    sndp->node.clientData = sndp;
    alSynAddPlayer(sndp->drvr, &sndp->node);

    /*
     * Start responding to API events
     */
    evt.type = AL_SNDP_API_EVT;
    alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
    sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);

}

