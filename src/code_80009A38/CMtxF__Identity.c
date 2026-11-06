#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef float CMtxF[4][4];
extern void CMtxF__Identity(CMtxF mfThis);
void CMtxF__Identity(CMtxF mfThis);
void CMtxF__Identity(CMtxF mfThis)
{
	mfThis[0][0] = mfThis[1][1] = mfThis[2][2] = mfThis[3][3] = 1 ;

	mfThis[0][1] =	mfThis[0][2] = mfThis[0][3] =
	mfThis[1][0] = mfThis[1][2] = mfThis[1][3] =
	mfThis[2][0] = mfThis[2][1] = mfThis[2][3] =
	mfThis[3][0] = mfThis[3][1] = mfThis[3][2] = 0 ;
}
