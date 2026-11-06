#include "decompdecomp_sync_dbdb19140c1c3524ce26.h"
#line 1 "func.c"
#line 222 "reference.c"
void GetReducedSaturation(BYTE Reduce,
								  BYTE inR, BYTE inG, BYTE inB,
								  BYTE *pOutR, BYTE *pOutG, BYTE *pOutB)
{
	int	oldMax, onemr;

	if (Reduce)
	{
		onemr = 255 - Reduce;

		oldMax = max(inR, max(inG, inB));

		*pOutR = (inR*onemr + oldMax*Reduce)/255;
		*pOutG = (inG*onemr + oldMax*Reduce)/255;
		*pOutB = (inB*onemr + oldMax*Reduce)/255;
	}
	else
	{
		*pOutR = inR;
		*pOutG = inG;
		*pOutB = inB;

		return;
	}
}

