#include "common.h"

typedef struct {u32 base;u32 validTracks;u32 gap;u32 lastTicks;u32 lastDeltaTicks;u32 pad;u8 *curLoc[16];u8 *curBUPtr[16];u8 curBULen[16];u8 lastStatus[16];u32 evtDeltaTicks[16];} LocalSeq;
typedef struct {u32 validTracks;u32 lastTicks;u32 lastDeltaTicks;u8 *curLoc[16];u8 *curBUPtr[16];u8 curBULen[16];u8 lastStatus[16];u32 evtDeltaTicks[16];} LocalMarker;
void alCSeqGetLoc(LocalSeq *seq,LocalMarker *m)
{
 s32 i;
 m->validTracks=seq->validTracks;
 m->lastTicks=seq->lastTicks;
 m->lastDeltaTicks=seq->lastDeltaTicks;
 for(i=0;i<16;i++)
 {
  m->curLoc[i]=seq->curLoc[i];
  m->curBUPtr[i]=seq->curBUPtr[i];
  m->curBULen[i]=seq->curBULen[i];
  m->lastStatus[i]=seq->lastStatus[i];
  m->evtDeltaTicks[i]=seq->evtDeltaTicks[i];
 }
}
