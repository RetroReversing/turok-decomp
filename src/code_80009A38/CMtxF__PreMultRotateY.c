#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

extern float __sinf(float angle);
extern float __cosf(float angle);
typedef float CMtxF[4][4];
extern void CMtxF__PreMultRotateY(CMtxF mfThis, float RotY) ;
void CMtxF__PreMultRotateY(CMtxF mfThis, float RotY);
void CMtxF__PreMultRotateY(CMtxF mfThis, float RotY)
{
	float	SinRotY = __sinf(RotY), CosRotY = __cosf(RotY) ;
	float	a ;

	a = mfThis[0][0] ;
	mfThis[0][0] = (CosRotY * a) + (-SinRotY * mfThis[2][0]) ;
	mfThis[2][0] = (SinRotY * a) + (CosRotY * mfThis[2][0]) ;

	a = mfThis[0][1] ;
	mfThis[0][1] = (CosRotY * a) + (-SinRotY * mfThis[2][1]) ;
	mfThis[2][1] = (SinRotY * a) + (CosRotY * mfThis[2][1]) ;

	a = mfThis[0][2] ;
	mfThis[0][2] = (CosRotY * a) + (-SinRotY * mfThis[2][2]) ;
	mfThis[2][2] = (SinRotY * a) + (CosRotY * mfThis[2][2]) ;

	// Total Adds 6, Total Multiplies 12 (Assumes column 4 = {0,0,0,1})
}
