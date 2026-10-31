#include "common.h"

typedef struct {u32 base;u32 validTracks;u32 gap;u32 lastTicks;u32 lastDeltaTicks;u32 pad;u8 *curLoc[16];u8 *curBUPtr[16];u8 curBULen[16];u8 lastStatus[16];u32 evtDeltaTicks[16];} LocalSeq;
typedef struct {u32 validTracks;u32 lastTicks;u32 lastDeltaTicks;u8 *curLoc[16];u8 *curBUPtr[16];u8 curBULen[16];u8 lastStatus[16];u32 evtDeltaTicks[16];} LocalMarker;
void alCSeqSetLoc(LocalSeq *seq,LocalMarker *m)
{
 s32 i;
 seq->validTracks=m->validTracks;
 seq->lastTicks=m->lastTicks;
 seq->lastDeltaTicks=m->lastDeltaTicks;
 for(i=0;i<16;i++)
 {
  seq->curLoc[i]=m->curLoc[i];
  seq->curBUPtr[i]=m->curBUPtr[i];
  seq->curBULen[i]=m->curBULen[i];
  seq->lastStatus[i]=m->lastStatus[i];
  seq->evtDeltaTicks[i]=m->evtDeltaTicks[i];
 }
}
