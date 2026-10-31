#include "source_func_800894B0.h"

#line 1 "reference.c"
void func_800894B0(void)
{
    u32					bankLen;
    ALSynConfig		c;
    ALSeqpConfig		seqc;
    amConfig			amc;
	int					i;
	ALInstrument		*inst;
	//ALSndId			*idPtr;
	//ALSound			*newsndptr;
	//ALSndPlayer		*PlayerPtr;
	OSPri					ospri;

	ospri = func_800A1920(NULL);	// set priority higher to avoid
	osSetThreadPri(NULL, PRIORITY_AUDIOLOCK);

	func_8008B40C(DEFAULT_RADIUS);

   alHeapInit(&D_8012AF18, (u8*)D_80157000, AUDIO_HEAP_SIZE);

	// Load the SEQ sound ctl file from ROM
   bankLen = RO_00628350 - D_00626DD0;
   D_8012AF0C = alHeapAlloc(&D_8012AF18, 1, bankLen);
   func_80083B80(D_00626DD0, (char *)D_8012AF0C, bankLen);
   alBnkfNew(D_8012AF0C, (u8 *) D_00628350);

	/*
     * Create the Audio Manager
     */
    c.maxVVoices	= MAX_VOICES;
    c.maxPVoices	= MAX_VOICES*2;
    c.maxUpdates	= MAX_UPDATES;
    c.dmaproc		= 0;                  // audio mgr will fill this in
#ifdef SOUND_USE_REVERB
	 c.fxType		= AL_FX_CUSTOM;
#else
	 c.fxType		= AL_FX_NONE;
#endif

    c.heap			= &D_8012AF18;

	 if (c.fxType == AL_FX_CUSTOM)
		c.D_800ECEC4 = D_800ECEC4;

    amc.outputRate = OUTPUT_RATE;
    amc.framesPerField = NUM_FIELDS;
    amc.maxACMDSize = MAX_RSP_CMDS;

	// Intialize AudioWorld globals
	D_80129520.SndPlayerList.NextPlayer = NULL;
	for(i = 0; i<MAX_VOICES_ALL;i++)
	{
		D_80129520.VoiceChannels[i].VirtualHandle = -1;
		D_80129520.VoiceChannels[i].PhysicalHandle = -1;
		D_80129520.VoiceChannels[i].theSFX.SfxNum = -1;
		D_80129520.VoiceChannels[i].theSFX.Priority = 0;
		D_80129520.VoiceChannels[i].theSFX.pEnvSound = NULL;
		D_80129520.VoiceChannels[i].theSFX.QuedVoice = -1;
		D_80129520.VoiceChannels[i].SndPlayer = &D_80129520.SndPlayerList.Sndp;
		D_80129520.VoiceChannels[i].ChannelFlags = 0;
	}

	for(i = 0; i<MAX_VOICES;i++)
		D_80129520.SndPlayerList.idlist[i] = -1;

	func_8008B80C(&D_80129410);
	func_8008B80C(&D_80129498);

	for(i = 0; i < MAX_QUE; i++)
	{
		func_8008B838(D_80129498.Next,&D_80129520.SFXWaitQue[i]);
	}

	func_8008D300(&c, PRIORITY_AUDIO, &amc);

#if 1
    /*
     * Create the sequence and the sequence player
     */
    seqc.maxVoices      = 24;
    seqc.maxEvents      = MAX_EVENTS;
    seqc.maxChannels    = 16;
    seqc.heap           = &D_8012AF18;
    seqc.initOsc        = 0;
    seqc.updateOsc      = 0;
    seqc.stopOsc        = 0;

	 D_8012EF2C = alHeapAlloc(&D_8012AF18, 1, sizeof(ALCSPlayer));

	 ASSERT(D_8012EF2C);
    alCSPNew(D_8012EF2C, &seqc);
    D_8012EF28 = alHeapAlloc(&D_8012AF18, 1, sizeof(ALCSeq));
	 ASSERT(D_8012EF28);

#endif


 	//load SFX sound info
	bankLen = RO_00672500 - D_00667230;
	D_80129520.SndPlayerList.sfxBankPtr = alHeapAlloc(&D_8012AF18, 1, bankLen);
	ASSERT(D_80129520.SndPlayerList.sfxBankPtr);
	func_80083B80(D_00667230,  D_80129520.SndPlayerList.sfxBankPtr, bankLen);
	alBnkfNew((ALBankFile *) D_80129520.SndPlayerList.sfxBankPtr, D_00672500);
	D_80129520.SndPlayerList.sfxBank = ((ALBankFile *) D_80129520.SndPlayerList.sfxBankPtr)->bankArray[0];
	ASSERT(D_80129520.SndPlayerList.sfxBank);
	//sort sfx
	inst =  D_80129520.SndPlayerList.sfxBank->instArray[0];
	func_800897E8(inst);

#ifndef DISABLE_SFX
	 // Initialize the soundplayer
   D_80129520.SPConfig.maxSounds = MAX_VOICES;
   D_80129520.SPConfig.maxEvents = MAX_EVENTS;
   D_80129520.SPConfig.heap  = &D_8012AF18;
	alSndpNew(&D_80129520.SndPlayerList.Sndp, &D_80129520.SPConfig);

#endif

	D_80129520.sfx_counter = 0;
	D_80129520.ChannelLock = -1;
	D_80129520.sfx_timer = 0;

	func_8008D274();


#if 0		// test code
	 		// allocate sound in player
	inst =  D_80129520.SndPlayerList.sfxBank->instArray[0];
	idPtr = D_80129520.SndPlayerList.idlist;
	PlayerPtr = &D_80129520.SndPlayerList.Sndp;

	newsndptr = inst->soundArray[57];
	idPtr[0] = alSndpAllocate(PlayerPtr, newsndptr);
	func_80089EC4(0);
	func_80089E70(0);
#endif

	osSetThreadPri(NULL, ospri);
}
