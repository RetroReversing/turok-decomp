#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void CMtxF__PreMultRotateX(CMtxF mfThis, float RotX) ;
void CMtxF__PreMultRotateX(CMtxF mfThis, float RotX);
void CMtxF__PreMultRotateX(CMtxF mfThis, float RotX)
{
	float	SinRotX = __sinf(RotX), CosRotX = __cosf(RotX) ;
	float	a ;

	a = mfThis[1][0] ;
	mfThis[1][0] = (CosRotX * a) + (SinRotX * mfThis[2][0]) ;
	mfThis[2][0] = (-SinRotX * a) + (CosRotX * mfThis[2][0]) ;

	a = mfThis[1][1] ;
	mfThis[1][1] = (CosRotX * a) + (SinRotX * mfThis[2][1]) ;
	mfThis[2][1] = (-SinRotX * a) + (CosRotX * mfThis[2][1]) ;

	a = mfThis[1][2] ;
	mfThis[1][2] = (CosRotX * a) + (SinRotX * mfThis[2][2]) ;
	mfThis[2][2] = (-SinRotX * a) + (CosRotX * mfThis[2][2]) ;

	// Total Adds 6, Total Multiplies 12 (Assumes column 4 = {0,0,0,1})
}
