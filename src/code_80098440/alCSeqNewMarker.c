#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {void *base;u32 validTracks;f32 qnpt;u32 lastTicks,lastDeltaTicks,deltaFlag;u8 *curLoc[16],*curBUPtr[16];u8 curBULen[16],lastStatus[16];u32 evtDeltaTicks[16];} ALCSeq;
typedef struct {u32 validTracks;s32 lastTicks;u32 lastDeltaTicks;u8 *curLoc[16],*curBUPtr[16];u8 curBULen[16],lastStatus[16];u32 evtDeltaTicks[16];} ALCSeqMarker;
typedef struct {s16 type;union {u32 words[3];f32 align;}msg;} ALEvent;
void alCSeqNew(ALCSeq*,u8*);void alCSeqNextEvent(ALCSeq*,ALEvent*);
#define AL_SEQ_END_EVT 4
#line 264 "cseq.c"
void alCSeqNewMarker(ALCSeq *seq, ALCSeqMarker *m, u32 ticks)
{
    ALEvent     evt;
    ALCSeq      tempSeq;
    s32         i;
    

    alCSeqNew(&tempSeq, (u8*)seq->base);
    
    do {
        m->validTracks    = tempSeq.validTracks;
        m->lastTicks      = tempSeq.lastTicks;
        m->lastDeltaTicks = tempSeq.lastDeltaTicks;
        
        for(i=0;i<16;i++)
        {
            m->curLoc[i]        = tempSeq.curLoc[i];
            m->curBUPtr[i]      = tempSeq.curBUPtr[i];
            m->curBULen[i]      = tempSeq.curBULen[i];
            m->lastStatus[i]    = tempSeq.lastStatus[i];
            m->evtDeltaTicks[i] = tempSeq.evtDeltaTicks[i];
        }
        
        alCSeqNextEvent(&tempSeq, &evt);
        
        if (evt.type == AL_SEQ_END_EVT)
            break;
        
    } while (tempSeq.lastTicks < ticks);

}

