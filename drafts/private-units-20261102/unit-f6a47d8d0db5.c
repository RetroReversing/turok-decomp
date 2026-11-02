
ALMicroTime     func_800AC16C(void *node);
static  void            func_800AB94C(ALSeqPlayer *seqp, ALEvent *event);
static  void            func_800AB6AC(ALSeqPlayer *seqp, ALEvent *event);
static	void		__handleNextSeqEvent(ALSeqPlayer *seqp);
static	void		__setUsptFromTempo(ALSeqPlayer *seqp, f32 tempo);
ALMicroTime func_800AC16C(void *node)
{
    ALSeqPlayer     *seqp = (ALSeqPlayer *) node;
    ALEvent         evt;
    ALVoice         *voice;
    ALMicroTime     delta;
    ALVoiceState    *vs;
    void            *oscState;
    f32		    oscValue;
    u8              chan;
    
    do {

	switch (seqp->nextEvent.type) {

	  case (AL_SEQ_REF_EVT):
	      __handleNextSeqEvent(seqp);
              break;

	  case (AL_SEQP_API_EVT):
              evt.type = AL_SEQP_API_EVT;
              alEvtqPostEvent(&seqp->evtq, (ALEvent *)&evt, seqp->frameTime);
              break;

	  case (AL_NOTE_END_EVT):
              voice = seqp->nextEvent.msg.note.voice;
              alSynStopVoice(seqp->drvr, voice);
              alSynFreeVoice(seqp->drvr, voice);
              vs = (ALVoiceState *)voice->clientPrivate;
              if(vs->flags)
                  __seqpStopOsc((ALSeqPlayer*)seqp,vs);
              __unmapVoice(seqp, voice);
              break;

	  case (AL_SEQP_ENV_EVT):
              voice = seqp->nextEvent.msg.vol.voice;
              vs = (ALVoiceState *)voice->clientPrivate;
                
              if (vs->envPhase == AL_PHASE_ATTACK)
                  vs->envPhase = AL_PHASE_DECAY;

              delta = seqp->nextEvent.msg.vol.delta;
              vs->envGain = seqp->nextEvent.msg.vol.vol;
              vs->envEndTime = seqp->curTime + delta;
              alSynSetVol(seqp->drvr, voice, __vsVol(vs, seqp), delta);
              break;

	  case (AL_TREM_OSC_EVT):
              vs = seqp->nextEvent.msg.osc.vs;
              oscState = seqp->nextEvent.msg.osc.oscState;
              delta = (*seqp->updateOsc)(oscState,&oscValue);
              vs->tremelo = (u8)oscValue;
              alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs,seqp),
                          __vsDelta(vs,seqp->curTime));
              evt.type = AL_TREM_OSC_EVT;
              evt.msg.osc.vs = vs;
              evt.msg.osc.oscState = oscState;
              alEvtqPostEvent(&seqp->evtq, &evt, delta);
              break;
                
	  case (AL_VIB_OSC_EVT):
              vs = seqp->nextEvent.msg.osc.vs;
              oscState = seqp->nextEvent.msg.osc.oscState;
              chan = seqp->nextEvent.msg.osc.chan;
              delta = (*seqp->updateOsc)(oscState,&oscValue);
              vs->vibrato = oscValue;
              alSynSetPitch(seqp->drvr, &vs->voice, vs->pitch * vs->vibrato
                            * seqp->chanState[chan].pitchBend);
              evt.type = AL_VIB_OSC_EVT;
              evt.msg.osc.vs = vs;
              evt.msg.osc.oscState = oscState;
              evt.msg.osc.chan = chan;
              alEvtqPostEvent(&seqp->evtq, &evt, delta);
              break;
                
	  case (AL_SEQP_MIDI_EVT):
              func_800AB94C(seqp, &seqp->nextEvent);
              break;

	  case (AL_SEQP_META_EVT):
              func_800AB6AC(seqp, &seqp->nextEvent);
              break;
              
	  case (AL_SEQP_PLAY_EVT):
	      if (seqp->state != AL_PLAYING)
	      {
	          seqp->state = AL_PLAYING;
	          __postNextSeqEvent(seqp);	/* seqp must be AL_PLAYING before we call this routine. */
	      }
	      break;

	  case (AL_SEQP_STOP_EVT):
              if ( seqp->state == AL_STOPPING )
	      {
                  for (vs = seqp->vAllocHead; vs != 0; vs = seqp->vAllocHead)
                  {
                      alSynStopVoice(seqp->drvr, &vs->voice);
                      alSynFreeVoice(seqp->drvr, &vs->voice);
                      if(vs->flags)
                          __seqpStopOsc((ALSeqPlayer*)seqp,vs);
                      __unmapVoice((ALSeqPlayer*)seqp, &vs->voice); 
                  }

                  seqp->curTime = 0;
                  seqp->state = AL_STOPPED;

                  /* alEvtqFlush(&seqp->evtq); - Don't flush event
                     queue anymore. */
		  /* sct 1/3/96 - Don't overwrite nextEvent with
		     AL_SEQP_API_EVT or set nextDelta to
		     AL_USEC_PER_FRAME since we're not stopping event
		     processing. */
		  /* sct 1/3/96 - Don't return here since we keep
                     processing events as usual. */
              }
              break;

	  case (AL_SEQP_STOPPING_EVT):
              if (seqp->state == AL_PLAYING)
	      {
		  /*
                   * sct 12/29/95 - Remove events associated with the
                   * stopping sequence.  Note that flushing
                   * AL_SEQP_MIDI_EVTs may flush events that were
                   * posted after the call to alSeqpStop, so the
                   * application must queue these events either when
                   * the player is fully stopped, or when it is
                   * playing.
                   */
                  alEvtqFlushType(&seqp->evtq, AL_SEQ_REF_EVT);
		  alEvtqFlushType(&seqp->evtq, AL_SEQP_MIDI_EVT);	

		  /*
                   * sct 1/3/96 - Check to see which voices need to be
                   * killed and release them.  Unkilled voices should
                   * have note end events occurring prior to
                   * KILL_TIME.
                   */
                  for (vs = seqp->vAllocHead; vs != 0; vs = vs->next)
		  {
		      if (__voiceNeedsNoteKill (seqp, &vs->voice, KILL_TIME))
			  __seqpReleaseVoice(seqp, &vs->voice, KILL_TIME);
		  }

                  seqp->state = AL_STOPPING;
                  evt.type = AL_SEQP_STOP_EVT;
                  alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
              }
              break;

	  case (AL_SEQP_VOL_EVT):
              seqp->vol = seqp->nextEvent.msg.spvol.vol;
              for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                  alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp),
                              __vsDelta(vs, seqp->curTime));
              }
              break;
            
	  case (AL_SEQP_LOOP_EVT):
              seqp->loopStart = seqp->nextEvent.msg.loop.start;
              seqp->loopEnd   = seqp->nextEvent.msg.loop.end;
              seqp->loopCount = seqp->nextEvent.msg.loop.count;
              break;

	  case (AL_SEQP_PRIORITY_EVT):
	      chan = seqp->nextEvent.msg.sppriority.chan;
	      seqp->chanState[chan].priority = seqp->nextEvent.msg.sppriority.priority;
	      break;
	  case (AL_SEQP_SEQ_EVT):
                                                                     
         
      
	      //assert(seqp->state != AL_PLAYING);	/* Must be done playing to change sequences. */

    
	      seqp->target = seqp->nextEvent.msg.spseq.seq;
	      __setUsptFromTempo (seqp, 500000.0);
	      if (seqp->bank)
		  __initFromBank(seqp, seqp->bank);
	      break;
	  case (AL_SEQP_BANK_EVT):
                             
         
      
	      //assert(seqp->state == AL_STOPPED);	/* Must be fully stopped to change banks. */

	      seqp->bank = seqp->nextEvent.msg.spbank.bank;
	      __initFromBank(seqp, seqp->bank);
	      break;

	  /* sct 11/6/95 - these events should now be handled by __handleNextSeqEvent */
	  case (AL_SEQ_END_EVT):
	  case (AL_TEMPO_EVT):
          case (AL_SEQ_MIDI_EVT):
                             
         
      
	      //assert(FALSE);	


              break;
        }

	seqp->nextDelta = alEvtqNextEvent (&seqp->evtq, &seqp->nextEvent);
	
    } while (seqp->nextDelta == 0);

    /*
     * assume that next callback won't be more than half an hour away
     */
    seqp->curTime += seqp->nextDelta;	/* Update the player's current time. */
    return seqp->nextDelta;
}

void func_800AB94C(ALSeqPlayer *seqp, ALEvent *event)
{
    ALVoice             *voice;
    ALVoiceState        *vs;
    s32                 status;
    u8                  chan;
    u8                  key;
    u8                  vel;
    u8                  byte1;
    u8                  byte2;
    ALMIDIEvent         *midi = &event->msg.midi;
    s16                 vol;
    ALEvent             evt;
    ALMicroTime         deltaTime;
    ALVoiceState        *vstate;
    ALPan   		    pan;
    ALFxRef		        fxref;
                             
         
      
    /* sct 12/15/95 - Fixed assert to also allow seqp midi event types. */
    //assert(event->type == AL_SEQ_MIDI_EVT || event->type == AL_SEQP_MIDI_EVT);

    
    status = midi->status & AL_MIDI_StatusMask;
    chan = midi->status & AL_MIDI_ChannelMask;
    byte1 = key  = midi->byte1;
    byte2 = vel  = midi->byte2;

    switch (status) {

        case (AL_MIDI_NoteOn):
            
            if (vel != 0) {		/* a real note on */
                ALVoiceConfig   config;
                ALSound         *sound;                    
                s16             cents;
                f32             pitch,oscValue;
                u8              fxmix;
                void            *oscState;
                ALInstrument    *inst;

		/* If we're not playing, don't process note ons. */
		if (seqp->state != AL_PLAYING)
		    break;

                sound = __lookupSoundQuick(seqp, key, vel, chan);
                ALFlagFailIf(!sound, seqp->debugFlags & NO_SOUND_ERR_MASK,
			   ERR_ALSEQP_NO_SOUND);
                
                config.priority = seqp->chanState[chan].priority;
                config.fxBus    = 0;
                config.unityPitch = 0;

                vstate = __mapVoice(seqp, key, vel, chan);
                ALFlagFailIf(!vstate, seqp->debugFlags & NO_VOICE_ERR_MASK,
			 ERR_ALSEQP_NO_VOICE );

                voice = &vstate->voice;
                
                alSynAllocVoice(seqp->drvr, voice, &config);

                /*
                 * set up the voice state structure
                 */
                vstate->sound = sound;
                vstate->envPhase = AL_PHASE_ATTACK;
                if (seqp->chanState[chan].sustain > AL_SUSTAIN)
                    vstate->phase = AL_PHASE_SUSTAIN;
                else
                    vstate->phase = AL_PHASE_NOTEON;
                
                cents = (key - sound->keyMap->keyBase) * 100
                    + sound->keyMap->detune;
                
                vstate->pitch = alCents2Ratio(cents);
                vstate->envGain = sound->envelope->attackVolume;
                vstate->envEndTime = seqp->curTime +
                    sound->envelope->attackTime;

                /*
                 * setup tremelo and vibrato if active
                 */
                vstate->flags = 0;
                inst = seqp->chanState[chan].instrument;

                oscValue = (f32)AL_VOL_FULL; /* set this as a default */

                if(inst->tremType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,
                                                     inst->tremType,
                                                     inst->tremRate,
                                                     inst->tremDepth,
                                                     inst->tremDelay);

                        if(deltaTime) /* if deltaTime = zero, don't run osc */
                        {
                            evt.type = AL_TREM_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x01; /* set tremelo flag bit */
                        }
                    }
                }
                /* will default if not changed by initOsc */
                vstate->tremelo = (u8)oscValue;
                
                oscValue = 1.0f; /* set this as a default */
                if(inst->vibType)
                {
                    if(seqp->initOsc)
                    {
                        deltaTime = (*seqp->initOsc)(&oscState,&oscValue,
                                                     inst->vibType,
                                                     inst->vibRate,
                                                     inst->vibDepth,
                                                     inst->vibDelay);

                        if(deltaTime)  /* if deltaTime = zero,don't run osc. */
                        {
                            evt.type = AL_VIB_OSC_EVT;
                            evt.msg.osc.vs = vstate;
                            evt.msg.osc.oscState = oscState;
                            evt.msg.osc.chan = chan;
                            alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);
                            vstate->flags |= 0x02; /* set the vibrato flag bit */
                        }
                    }
                }
                /* will default if not changed by initOsc */
                vstate->vibrato = oscValue;

                /*
                 * calculate the note on parameters
                 */
                pitch = vstate->pitch * seqp->chanState[chan].pitchBend *
                    vstate->vibrato;
                fxmix = seqp->chanState[chan].fxmix;
                pan   = __vsPan(vstate, seqp);
                vol   = __vsVol(vstate, seqp);
                deltaTime  = sound->envelope->attackTime;

                alSynStartVoiceParams(seqp->drvr, voice, sound->wavetable,
                                      pitch, vol, pan, fxmix, deltaTime);
                /*
                 * set up callbacks for envelope
                 */
                evt.type          = AL_SEQP_ENV_EVT;
                evt.msg.vol.voice = voice;
                evt.msg.vol.vol   = sound->envelope->decayVolume;
                evt.msg.vol.delta = sound->envelope->decayTime;
                deltaTime = sound->envelope->attackTime;
                
                alEvtqPostEvent(&seqp->evtq, &evt, deltaTime);

                break;
            }

            /*
             * NOTE: intentional fall-through for note on with zero
             * velocity
             */
            
        case (AL_MIDI_NoteOff):
            vstate = __lookupVoice(seqp, key, chan);
            ALFlagFailIf(!vstate, (seqp->debugFlags & NOTE_OFF_ERR_MASK),
		       ERR_ALSEQP_OFF_VOICE );

            if (vstate->phase == AL_PHASE_SUSTAIN)
                vstate->phase = AL_PHASE_SUSTREL;
            else {
                vstate->phase = AL_PHASE_RELEASE;
                __seqpReleaseVoice(seqp, &vstate->voice,
				   vstate->sound->envelope->releaseTime);
            }

            break;
            
        case (AL_MIDI_PolyKeyPressure):
	    /*
	     * Aftertouch per key (hardwired to volume). Note that
	     * aftertouch affects only notes that are already
	     * sounding.
             */
	    vstate = __lookupVoice(seqp, key, chan);
	    ALFailIf(!vstate,  ERR_ALSEQP_POLY_VOICE );

	    vstate->velocity = byte2;
	    alSynSetVol(seqp->drvr, &vstate->voice, __vsVol(vstate, seqp),
			__vsDelta(vstate, seqp->curTime));
	    break;

        case (AL_MIDI_ChannelPressure):
	    /*
             * Aftertouch per channel (hardwired to volume). Note that
             * aftertouch affects only notes that are already
             * sounding.
             */
	    for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		if (vs->channel == chan) {
		    vs->velocity = byte1;
		    alSynSetVol(seqp->drvr, &vs->voice, __vsVol(vs, seqp),
				__vsDelta(vs, seqp->curTime));
		}
	    }
            break;
            
        case (AL_MIDI_ControlChange):

	    switch (byte1) {
		  
	    case (AL_MIDI_PAN_CTRL):
		seqp->chanState[chan].pan = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if (vs->channel == chan) {
			pan = __vsPan(vs, seqp);
			alSynSetPan(seqp->drvr, &vs->voice, pan);
		    }
		}
		break;

	    case (AL_MIDI_VOLUME_CTRL):
		seqp->chanState[chan].vol = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if ((vs->channel == chan) &&
			(vs->envPhase != AL_PHASE_RELEASE))
		    {
			vol = __vsVol(vs, seqp);
			alSynSetVol(seqp->drvr, &vs->voice, vol,
				    __vsDelta(vs, seqp->curTime));
		    }
		}
		break;
            case (AL_MIDI_PRIORITY_CTRL):
		/* leave current voices where they are */
		seqp->chanState[chan].priority = byte2;
		break;
	    case (AL_MIDI_SUSTAIN_CTRL):
		seqp->chanState[chan].sustain = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if ((vs->channel == chan) &&
			(vs->phase != AL_PHASE_RELEASE)) {
			if ( byte2 > AL_SUSTAIN ) {
			    /*
			     * sustain pedal down
			     */
			    if (vs->phase == AL_PHASE_NOTEON)
				vs->phase = AL_PHASE_SUSTAIN;
			} else {
			    /*
			     * sustain pedal up
			     */
			    if (vs->phase == AL_PHASE_SUSTAIN)
				vs->phase = AL_PHASE_NOTEON;
			    else if(vs->phase == AL_PHASE_SUSTREL) {
				vs->phase = AL_PHASE_RELEASE;
				__seqpReleaseVoice(seqp, &vs->voice,
						   vs->sound->envelope->releaseTime);
			    }
			}
		    }
		}
		break;
	    
	    case (AL_MIDI_FX1_CTRL):
		seqp->chanState[chan].fxmix = byte2;
		for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
		    if (vs->channel == chan) {
			alSynSetFXMix(seqp->drvr, &vs->voice, byte2);
		    }
		}
		break;

	    case (AL_MIDI_FX_CTRL_0):
	    case (AL_MIDI_FX_CTRL_1):
	    case (AL_MIDI_FX_CTRL_2):
	    case (AL_MIDI_FX_CTRL_3):
	    case (AL_MIDI_FX_CTRL_4):
	    case (AL_MIDI_FX_CTRL_5):
	    case (AL_MIDI_FX_CTRL_6):
	    case (AL_MIDI_FX_CTRL_7):
                                            
                                          
            
                                                                    
        
      
	    case (AL_MIDI_FX3_CTRL):
	    default:
		break;
	    }
            break;

        case (AL_MIDI_ProgramChange):
	    /* sct 1/16/96 - We must have a valid bank in order to process the program change. */
                             
         
      
	    //assert(seqp->bank != NULL);


            if (key < seqp->bank->instCount) {
                ALInstrument *inst = seqp->bank->instArray[key];
                __setInstChanState(seqp, inst, chan);        /* sct 11/6/95 */
            }
             
         
                                                                  
                      
            break;
            
        case (AL_MIDI_PitchBendChange):
	    {
		s32 bendVal;
		f32 bendRatio;
		s32 cents;
                
		/*
                 * get 14-bit unsigned midi value
                 */
                bendVal = ( (byte2 << 7) + byte1) - 8192;

                /*
                 * calculate pitch bend in cents
                 */
                cents = (seqp->chanState[chan].bendRange * bendVal)/8192;

                /*
                 * calculate the corresponding ratio
                 */
                bendRatio = alCents2Ratio(cents);
                seqp->chanState[chan].pitchBend = bendRatio;
                
                for (vs = seqp->vAllocHead; vs != 0; vs = vs->next) {
                    if (vs->channel == chan) {
                        alSynSetPitch(seqp->drvr, &vs->voice,
                                      vs->pitch * bendRatio * vs->vibrato);
                    }
                }
            }
            break;
            
        default:
             
                                                 
      
	    break;
    }        
}

void func_800AB6AC(ALSeqPlayer *seqp, ALEvent *event)
{
    ALTempoEvent *tevt = &event->msg.tempo;
    ALEvent      evt;
    s32          tempo;

    if (event->msg.tempo.status == AL_MIDI_Meta)
    {
        if (event->msg.tempo.type == AL_MIDI_META_TEMPO)
	{
	    tempo =
		(tevt->byte1 << 16) |
		(tevt->byte2 <<  8) |
		(tevt->byte3 <<  0);
	    __setUsptFromTempo (seqp, (f32)tempo);	/* sct 1/8/96 */
        }
    }
}

static void
__handleNextSeqEvent(ALSeqPlayer *seqp)
{
    ALEvent	evt;

    /* sct 1/5/96 - Do nothing if we don't have a target sequence. */
    if (seqp->target == NULL)
	return;

    alSeqNextEvent(seqp->target, &evt);

    switch (evt.type)
    {
    case AL_SEQ_MIDI_EVT:
	func_800AB94C(seqp, &evt);
	__postNextSeqEvent(seqp);
	break;

    case AL_TEMPO_EVT:
	func_800AB6AC(seqp, &evt);
	__postNextSeqEvent(seqp);
	break;

    case AL_SEQ_END_EVT:
	seqp->state = AL_STOPPING;      
	evt.type    = AL_SEQP_STOP_EVT;
	alEvtqPostEvent(&seqp->evtq, &evt, AL_EVTQ_END);
	break;

    default:
                             
         
      
	//assert(FALSE);	/* Sequence event type not supported. */
                              
	break;
      
    }
}

static void __setUsptFromTempo (ALSeqPlayer *seqp, f32 tempo)
{
    if (seqp->target)
	seqp->uspt = (s32)((f32)tempo * seqp->target->qnpt);
    else
	seqp->uspt = 488;		/* This is the initial value set by alSeqpNew. */
}

ALMicroTime __vsDelta(ALVoiceState *vs, ALMicroTime t)
{
    /*
     * If we are interrupting a previously set envelope segment, we
     * need to recalculate the segment end time given the current
     * time. Note: this routine assumes that the voice is currently
     * playing.
     */
    
    s32 delta = vs->envEndTime - t;
    
    if (delta >= 0) {
        return delta;
    } else {
        return AL_GAIN_CHANGE_TIME;
    }
}

