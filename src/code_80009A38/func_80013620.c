#include "common_local_source_3841.h"

#line 1169 "reference.c"
float func_80013620(float A, float B)
{
	float newB;
	
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

	return A - B;
}
