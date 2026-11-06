#include "decompdecomp_sync_66144abd60c7229a54dc.h"
#line 1 "func.c"
#line 1922 "reference.c"
void CMtxF__PostMultScale(CMtxF mfThis, FLOAT Sx, FLOAT Sy, FLOAT Sz)
{
	mfThis[0][0] *= Sx ;
	mfThis[0][1] *= Sy ;
	mfThis[0][2] *= Sz ;

	mfThis[1][0] *= Sx ;
	mfThis[1][1] *= Sy ;
	mfThis[1][2] *= Sz ;

	mfThis[2][0] *= Sx ;
	mfThis[2][1] *= Sy ;
	mfThis[2][2] *= Sz ;

	mfThis[3][0] *= Sx ;
	mfThis[3][1] *= Sy ;
	mfThis[3][2] *= Sz ;

	// Total Adds 0, Total Multiplies 12 (Assumes column 4 = {0,0,0,1})
}

