#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct ALPlayer {struct ALPlayer *next;void *clientData;s32 (*handler)(void*);s32 callTime,samplesLeft;} ALPlayer;
typedef struct {s16 type;union{u32 words[3];f32 align;} msg;} ALEvent;
typedef struct {void *next,*prev;} ALLink;
typedef struct {ALLink node;s32 delta;ALEvent evt;} ALEventListItem;
typedef struct {ALLink freeList,allocList;s32 eventCount;} ALEventQueue;
typedef struct ALVoiceState {struct ALVoiceState *next;u8 rest[52];} ALVoiceState;
typedef struct {u32 data[4];} ALChanState;
typedef void ALHeap;typedef void ALSynth;
typedef struct {s32 maxVoices,maxEvents;u8 maxChannels,debugFlags;ALHeap *heap;void *initOsc,*updateOsc,*stopOsc;} ALSeqpConfig;
typedef struct {ALPlayer node;ALSynth *drvr;void *target;s32 curTime;void *bank;s32 uspt,nextDelta,state;u16 chanMask;s16 vol;u8 maxChannels,debugFlags;ALEvent nextEvent;ALEventQueue evtq;s32 frameTime;ALChanState *chanState;ALVoiceState *vAllocHead,*vAllocTail,*vFreeList;void *initOsc,*updateOsc,*stopOsc;void *loopStart,*loopEnd;s32 loopCount;} ALCSPlayer;
typedef ALCSPlayer ALSeqPlayer;
extern ALSynth *D_800EF260;
void *alHeapDBAlloc(char*,s32,ALHeap*,s32,s32);
void __initChanState(ALSeqPlayer*);void alEvtqNew(ALEventQueue*,ALEventListItem*,s32);void alSynAddPlayer(ALSynth*,ALPlayer*);s32 func_800AC16C(void*);
#define AL_STOPPED 0
#define AL_USEC_PER_FRAME 16000
#define AL_SEQP_API_EVT 9
#define alHeapAlloc(h,n,s) alHeapDBAlloc(0,0,h,n,s)
#line 56 "seqplayer.c"
void alSeqpNew(ALSeqPlayer *seqp, ALSeqpConfig *c)
{
    s32                 i;
    ALEventListItem     *items;
    ALVoiceState        *vs;
    ALVoiceState        *voices;
    ALHeap *hp = c->heap;    
    
    /*
     * initialize member variables
     */
    seqp->bank          = 0;
    seqp->target        = NULL;
    seqp->drvr          = D_800EF260;
    seqp->chanMask      = 0xff;
    seqp->uspt          = 488;
    seqp->nextDelta     = 0;
    seqp->state         = AL_STOPPED;
    seqp->vol           = 0x7FFF;                  /* full volume  */
    seqp->debugFlags    = c->debugFlags;
    seqp->frameTime     = AL_USEC_PER_FRAME; /* should get this from driver */
    seqp->curTime       = 0;
    seqp->initOsc       = c->initOsc;
    seqp->updateOsc     = c->updateOsc;
    seqp->stopOsc       = c->stopOsc;
    seqp->loopStart = 0;
    seqp->loopEnd   = 0;
    seqp->loopCount = 0;      /* -1 = loop forever, 0 = no loop   */
    
    seqp->nextEvent.type = AL_SEQP_API_EVT; /* start the voice handler "spinning" */
    
    /*
     * init the channel state
     */
    seqp->maxChannels = c->maxChannels;
    seqp->chanState = alHeapAlloc(hp, c->maxChannels, sizeof(ALChanState) );
    __initChanState(seqp);	/* sct 11/6/95 */
    
    /*
     * init the voice state array
     */
    voices = alHeapAlloc(hp, c->maxVoices, sizeof(ALVoiceState));
    seqp->vFreeList = 0;
    for (i = 0; i < c->maxVoices; i++) {
        vs = &voices[i];
        vs->next = seqp->vFreeList;
        seqp->vFreeList = vs;        
    }
    
    seqp->vAllocHead = 0;
    seqp->vAllocTail = 0;    
        
    /*
     * init the event queue
     */
    items = alHeapAlloc(hp, c->maxEvents, sizeof(ALEventListItem));
    alEvtqNew(&seqp->evtq, items, c->maxEvents);

    /*
     * add ourselves to the driver
     */
    seqp->node.next       = NULL;
    seqp->node.handler    = func_800AC16C;
    seqp->node.clientData = seqp;
    alSynAddPlayer(D_800EF260, &seqp->node);
}

