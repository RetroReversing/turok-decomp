#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct {s16 fc,fgain;union {s16 fccoef[16];s64 force_aligned;}fcvec;void *fstate;s32 first;} LocalLowPass;
#define SCALE 16384
#line 92 "drvrNew.c"
void init_lpfilter(LocalLowPass *lp)
{
    s32		i, temp;
    s16		fc;
    f64		ffc, fcoef;

    temp = lp->fc * SCALE;
    fc = temp >> 15;
    lp->fgain = SCALE - fc;

    lp->first = 1;
    for (i=0; i<8; i++)
	lp->fcvec.fccoef[i] = 0;
    
    lp->fcvec.fccoef[i++] = fc;
    fcoef = ffc = (f64)fc/SCALE;

    for (; i<16; i++){
	fcoef *= ffc;
	lp->fcvec.fccoef[i] = (s16)(fcoef * SCALE);
    }
}

