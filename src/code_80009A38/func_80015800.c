#include "common_local_source_3886.h"

#line 114 "reference.c"
void func_80015800(CMtxF mfThis)
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
