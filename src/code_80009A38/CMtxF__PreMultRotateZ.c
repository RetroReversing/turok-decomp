#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void CMtxF__PreMultRotateZ(CMtxF mfThis, float RotZ) ;
void CMtxF__PreMultRotateZ(CMtxF mfThis, float RotZ);
void CMtxF__PreMultRotateZ(CMtxF mfThis, float RotZ)
{
	float	SinRotZ = __sinf(RotZ), CosRotZ = __cosf(RotZ) ;
	float	a ;

	a = mfThis[0][0] ;
	mfThis[0][0] = (CosRotZ * a) + (SinRotZ * mfThis[1][0]) ;
	mfThis[1][0] = (-SinRotZ * a) + (CosRotZ * mfThis[1][0]) ;

	a = mfThis[0][1] ;
	mfThis[0][1] = (CosRotZ * a) + (SinRotZ * mfThis[1][1]) ;
	mfThis[1][1] = (-SinRotZ * a) + (CosRotZ * mfThis[1][1]) ;

	a = mfThis[0][2] ;
	mfThis[0][2] = (CosRotZ * a) + (SinRotZ * mfThis[1][2]) ;
	mfThis[1][2] = (-SinRotZ * a) + (CosRotZ * mfThis[1][2]) ;

	// Total Adds 6, Total Multiplies 12 (Assumes column 4 = {0,0,0,1})
}
