#include "common.h"

typedef struct {u32 pad0;u8 *trackStart;u8 *curPtr;s32 lastTicks;u8 pad10[10];s16 lastStatus;} ALSeq;
typedef struct {u8 *curPtr;s32 lastTicks;s32 curTicks;s16 lastStatus;} ALSeqMarker;
typedef struct {s16 type;union {s32 align;u8 payload[12];} msg;} ALEvent;
extern void alSeqNextEvent(ALSeq*,ALEvent*);
#define AL_SEQ_END_EVT 4
void alSeqNewMarker(ALSeq *seq, ALSeqMarker *m, u32 ticks)
{
    ALEvent     evt;
    u8          *savePtr, *lastPtr;
    s32         saveTicks, lastTicks;
    s16         saveStatus, lastStatus;
    
    /* does not check that ticks is within bounds */
    
    if (ticks == 0) { /* common case */
        m->curPtr     = seq->trackStart;
        m->lastStatus = 0;
        m->lastTicks  = 0;
        m->curTicks=0;
        return;
    } else {
        savePtr     = seq->curPtr;
        saveStatus  = seq->lastStatus;
        saveTicks   = seq->lastTicks;

        seq->curPtr     = seq->trackStart;
        seq->lastStatus = 0;
        seq->lastTicks  = 0;

        do {
            lastPtr    = seq->curPtr;
            lastStatus = seq->lastStatus;
            lastTicks  = seq->lastTicks;
        
            alSeqNextEvent(seq, &evt);
            
            if (evt.type == AL_SEQ_END_EVT)
	    {
		lastPtr    = seq->curPtr;
		lastStatus = seq->lastStatus;
		lastTicks  = seq->lastTicks;
                break;
	    }
            
        } while (seq->lastTicks < ticks);

        m->curPtr     = lastPtr;
        m->lastStatus = lastStatus;
        m->lastTicks  = lastTicks;
        m->curTicks = seq->lastTicks;
    
        seq->curPtr     = savePtr;
        seq->lastStatus = saveStatus;
        seq->lastTicks  = saveTicks;

    }    
}
