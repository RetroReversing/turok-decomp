#include "decompdecomp_sync_224ffcbd65e9fc2b7eed.h"
#line 1 "func.c"
#line 265 "reference.c"
void func_800153B4(CMtxF mfThis, float Theta, float X, float Y, float Z)
{
	float	sine ;
	float	cosine ;
	float	ab, bc, ca, t ;

	sine = sin(Theta) ;
	cosine = cos(Theta) ;

	t = (1-cosine) ;
	ab = X*Y*t ;
	bc = Y*Z*t ;
	ca = Z*X*t ;

	mfThis[0][3] = mfThis[1][3] = mfThis[2][3] =
	mfThis[3][0] = mfThis[3][1] = mfThis[3][2] = 0 ;
	mfThis[3][3] = 1 ;

	t = X*X ;
	X *= sine ;
	mfThis[0][0] = t+cosine*(1-t) ;
	mfThis[2][1] = bc-X ;
	mfThis[1][2] = bc+X ; 

	t = Y*Y ;
	Y *= sine ;
	mfThis[1][1] = t+cosine*(1-t) ;
	mfThis[2][0] = ca+Y ;
	mfThis[0][2] = ca-Y ;

	t = Z*Z ;
	Z *= sine ;
	mfThis[2][2] = t+cosine*(1-t) ;
	mfThis[1][0] = ab-Z ;
	mfThis[0][1] = ab+Z ;
}

