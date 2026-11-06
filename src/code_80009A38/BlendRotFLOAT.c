#include "common_local_source_3842.h"

#line 1143 "reference.c"
float BlendRotFLOAT(float u, float A, float B)
{
	float newB, blended;
	
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

	blended = BlendFLOAT(u, A, B);
	NormalizeRotation(&blended);
	
	return blended;
}
