#include "common_local_source_3841.h"

#line 1169 "reference.c"
float RotDifference(float A, float B)
{
	float newB;
	
	NormalizeRotation(&A);
	NormalizeRotation(&B);
	
	if (A > B)
	{
		newB = B + 2*ANGLE_PI;
		if ((newB - A) < (A - B))
			B = newB;
	}
	else
	{
		newB = B - 2*ANGLE_PI;
		if ((A - newB) < (B - A))
			B = newB;
	}

	return A - B;
}
