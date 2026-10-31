#include "common_local_source_4844.h"

#line 6263 "reference.c"
BOOL func_8005CE10(CTMove *pThis)
{
	float Ang;


	Ang = pThis->RotXPlayer + (ANGLE_PI/2);
	while (Ang>=ANGLE_PI*2)
		Ang -= ANGLE_PI*2;
	while (Ang<0)
		Ang += ANGLE_PI*2;


	return (BOOL) (Ang>=ANGLE_PI);
}
