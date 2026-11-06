#include "decompdecomp_sync_0394ae4400d685eb7d2c.h"

#line 114 "reference.c"
/////////////////////////////////////////////////////////////////////////////
//	CMtxF__Clamp - limit matrix value so that they can be converted to int's
/////////////////////////////////////////////////////////////////////////////
void CMtxF__Clamp(CMtxF mfThis)
{
	int 		r, c ;

	for (r=0; r<4; r++)
	{
   	for (c=0; c<4; c++)
		{
			// Range check matrix value
			if (mfThis[r][c] > 32767.0)
				mfThis[r][c] = 32767.0 ;
			else
			if (mfThis[r][c] < -32767.0)
				mfThis[r][c] = -32767.0 ;
		}
	}
}
