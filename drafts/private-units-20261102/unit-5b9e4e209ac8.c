
#line 241 "reference-macro.c"
    #define INT_MAX         2147483647      /* Should be in a limits.h file. */

ALMicroTime     func_800A366C(void *node);
static  void            func_800A3664(ALSndPlayer *sndp, ALSndpEvent *event);
static	void		func_800A35E0(ALEventQueue *evtq, ALSoundState *state);
static	s32		func_800A365C (s32 i, f32 f);
ALMicroTime     func_800A366C(void *node);
static  void            func_800A3664(ALSndPlayer *sndp, ALSndpEvent *event);
static	void		func_800A35E0(ALEventQueue *evtq, ALSoundState *state);
static	s32		func_800A365C (s32 i, f32 f);
ALMicroTime func_800A366C(void *node)
{
    ALSndPlayer *sndp = (ALSndPlayer *) node;
    ALSndpEvent evt;

    do {
        switch (sndp->nextEvent.type) {
            case (AL_SNDP_API_EVT):
                evt.common.type = AL_SNDP_API_EVT;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, sndp->frameTime);
                break;

            default:
                func_800A3664(sndp, (ALSndpEvent *)&sndp->nextEvent);
                break;
        }
        sndp->nextDelta = alEvtqNextEvent(&sndp->evtq, &sndp->nextEvent);
        
    } while (sndp->nextDelta == 0);
    sndp->curTime += sndp->nextDelta;
    return sndp->nextDelta;
}

void func_800A3664(ALSndPlayer *sndp, ALSndpEvent *event) 
{
    ALVoiceConfig       vc;
    ALSound             *snd;
    ALVoice             *voice;
    ALPan               pan;
    f32                 pitch;
    ALSndpEvent         evt;
    ALMicroTime         delta;

    s16                 vol;
    s16                 tmp;
    s32                 vtmp;
    ALSoundState        *state;

    state = event->common.state;
    snd   = state->sound;
            

    switch (event->msg.type) {
        case (AL_SNDP_PLAY_EVT):
            if (state->state != AL_STOPPED || !snd)
                return;
            
            vc.fxBus      = 0;            /* effect buss 0 */
            vc.priority   = state->priority;
	    vc.unityPitch = 0;

            voice = &state->voice;
            alSynAllocVoice(sndp->drvr, voice, &vc);

            vol   = (s16) ((s32) snd->envelope->attackVolume*state->vol/AL_VOL_FULL);
            tmp   = state->pan - AL_PAN_CENTER + snd->samplePan;
            tmp   = MAX(tmp, AL_PAN_LEFT);
            pan   = (ALPan) MIN(tmp, AL_PAN_RIGHT);
            pitch = state->pitch;
            delta   = snd->envelope->attackTime;
            
            alSynStartVoice(sndp->drvr, voice, snd->wavetable);
            state->state = AL_PLAYING;
            
            alSynSetPan(sndp->drvr, voice, pan);
            alSynSetVol(sndp->drvr, voice, vol, delta);
            alSynSetPitch(sndp->drvr, voice, pitch);
            alSynSetFXMix(sndp->drvr, voice, state->fxMix);
            
            evt.common.type     = AL_SNDP_DECAY_EVT;
            evt.common.state    = state;
	    delta = (ALMicroTime) func_800A365C (snd->envelope->attackTime, state->pitch);
            alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
            break;
                
        case (AL_SNDP_STOP_EVT):
            if (state->state != AL_PLAYING || !snd)
                return;

	    delta = (ALMicroTime) func_800A365C (snd->envelope->releaseTime, state->pitch);
            alSynSetVol(sndp->drvr, &state->voice, 0, delta);

            if (delta) {
                evt.common.type  = AL_SNDP_END_EVT;
                evt.common.state = state;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
                state->state = AL_STOPPING;
            } else {
                /* note: this code is repeated in AL_SNDP_END_EVT */
                alSynStopVoice(sndp->drvr, &state->voice);
                alSynFreeVoice(sndp->drvr, &state->voice);
                func_800A35E0(&sndp->evtq, state);
                state->state = AL_STOPPED;
            }            
            break;

        case (AL_SNDP_PAN_EVT):
            state->pan = event->pan.pan;
            if (state->state == AL_PLAYING && snd){
                tmp   = state->pan - AL_PAN_CENTER + snd->samplePan;
                tmp   = MAX(tmp, AL_PAN_LEFT);
                pan   = (ALPan) MIN(tmp, AL_PAN_RIGHT);
                alSynSetPan(sndp->drvr, &state->voice, pan);
            }
            break;

        case (AL_SNDP_PITCH_EVT):
	    /* Limit the pitch to a practical value even though we only need */
	    /* to limit it to a non-zero number to avoid divide by zero. */
            if ((state->pitch = event->pitch.pitch) < MIN_RATIO)
		state->pitch = MIN_RATIO;
	    
            if (state->state == AL_PLAYING){
                alSynSetPitch(sndp->drvr, &state->voice, state->pitch);
            }
            break;
            
        case (AL_SNDP_FX_EVT):
            state->fxMix = event->fx.mix;
            if (state->state == AL_PLAYING)
                alSynSetFXMix(sndp->drvr, &state->voice, state->fxMix);
            break;

        case (AL_SNDP_VOL_EVT):
            state->vol = event->vol.vol;
            if (state->state == AL_PLAYING && snd){
                vtmp  = snd->envelope->decayVolume * state->vol/AL_VOL_FULL;            
                alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, 1000);
            }
            break;

        case (AL_SNDP_DECAY_EVT):
            /*
             * The voice has theoretically reached its attack velocity,
             * set up callback for release envelope - except for a looped sound
             */
            if (snd->envelope->decayTime != -1){
                vtmp   = snd->envelope->decayVolume * state->vol/AL_VOL_FULL;            
		delta = (ALMicroTime) func_800A365C (snd->envelope->decayTime, state->pitch);
                alSynSetVol(sndp->drvr, &state->voice, (s16) vtmp, delta);
                evt.common.type        = AL_SNDP_STOP_EVT;
                evt.common.state       = state;
                alEvtqPostEvent(&sndp->evtq, (ALEvent *)&evt, delta);
            }
            break;

        case (AL_SNDP_END_EVT):
            /* note: this code is repeated in AL_SNDP_STOP_EVT */
            alSynStopVoice(sndp->drvr, &state->voice);
            alSynFreeVoice(sndp->drvr, &state->voice);
            func_800A35E0(&sndp->evtq, state);
            state->state = AL_STOPPED;
            break;

        default:
            break;
    }
}

static void func_800A35E0(ALEventQueue *evtq, ALSoundState *state)
{
    ALLink              *thisNode;
    ALLink              *nextNode;
    ALEventListItem     *thisItem;
    ALEventListItem     *nextItem;
    ALSndpEvent         *thisEvent;
    OSIntMask           mask;

    mask = func_8009D220(OS_IM_NONE);

    thisNode = evtq->allocList.next;
    while( thisNode != 0 ) {
	nextNode = thisNode->next;
        thisItem = (ALEventListItem *)thisNode;
        nextItem = (ALEventListItem *)nextNode;
        thisEvent = (ALSndpEvent *) &thisItem->evt;
        if (thisEvent->common.state == state){
            if( nextItem )
                nextItem->delta += thisItem->delta;
            alUnlink(thisNode);
            alLink(thisNode, &evtq->freeList);
        }
	thisNode = nextNode;
    }
    
    func_8009D220(mask);
}

static s32 func_800A365C (s32 i, f32 f)
{
    #define INT_MAX         2147483647      /* Should be in a limits.h file. */
    f64	rd;
    int	ri;

    //assert(f!=0);	/* Caller must make sure we do not divide by zero! */

    rd = i/f;		/* Store result as a double to avoid overflow. */
    
    if (rd > INT_MAX)	/* Limit the value if necessary. */
	ri = INT_MAX;
    else
	ri = rd;

    return ri;
}

