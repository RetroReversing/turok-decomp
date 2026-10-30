#include "common_local_source_3842.h"

#line 1143 "reference.c"
float func_800136C8(float u, float A, float B)
{
	float newB, blended;
	
	func_80013588(&A);
	func_80013588(&B);

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
	func_80013588(&blended);
	
	return blended;
}
