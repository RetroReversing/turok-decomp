#include "decompdecomp_sync_66125f7b73441b73ef78.h"
#line 1 "func.c"
#line 223 "reference.c"
char __alCSeqNextDelta(ALCSeq *seq, s32 *pDeltaTicks)
{
    u32     i;
    u32	    firstTime = 0xFFFFFFFF;
    u32     lastTicks = seq->lastDeltaTicks;

    if (!seq->validTracks)
	return FALSE;

    for(i = 0; i < 16 ; i++)
    {
	if((seq->validTracks >> i) & 1)
        {
	    if(seq->deltaFlag)
		seq->evtDeltaTicks[i] -= lastTicks;

	    if(seq->evtDeltaTicks[i] < firstTime)
		firstTime = seq->evtDeltaTicks[i];
        }
    }
 
    seq->deltaFlag = 0;
    *pDeltaTicks = firstTime;

    return TRUE;
}

