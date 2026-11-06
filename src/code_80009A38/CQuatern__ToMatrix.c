#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

struct CQuatern_t;
typedef float CMtxF[4][4];
typedef struct CQuatern_t
{
 float x, y, z, t;
} CQuatern;
extern void CQuatern__ToMatrix(CQuatern *pqThis, CMtxF mfRotate);
void CQuatern__ToMatrix(CQuatern *pqThis, CMtxF mfRotate);
//#define Q2M_NORMALIZE
void CQuatern__ToMatrix(CQuatern *pqThis, CMtxF mfRotate)
{
	float		x, x2,
				y, y2,
				z, z2,
				t, t2;
#ifdef Q2M_NORMALIZE
	float		denom, invDenom;
#endif

	float		xy2,
				tz2,
				xz2,
				ty2,
				yz2,
				tx2 ;

	x 	= pqThis->x;
	x2 = x*x;

	y 	= pqThis->y;
	y2	= y*y;

	z	= pqThis->z;
	z2 = z*z;

	t	= pqThis->t;
	t2 = t*t;

#ifdef Q2M_NORMALIZE
	denom = t2 + x2 + y2 + z2;
	if (denom == 0)
		invDenom = 1;
	else
		invDenom = 1/denom;

	mfRotate[0][0] = (t2 + x2 - y2 - z2)*invDenom;
	mfRotate[1][0] = (2*x*y - 2*t*z)		*invDenom;
   mfRotate[2][0] = (2*x*z + 2*t*y)		*invDenom;
   mfRotate[3][0] = 0;

   mfRotate[0][1] = (2*x*y + 2*t*z)		*invDenom;
   mfRotate[1][1] = (t2 - x2 + y2 - z2)*invDenom;
   mfRotate[2][1] = (2*y*z - 2*t*x)		*invDenom;
   mfRotate[3][1] = 0;

   mfRotate[0][2] = (2*x*z - 2*t*y)		*invDenom;
   mfRotate[1][2] = (2*y*z + 2*t*x)		*invDenom;
   mfRotate[2][2] = (t2 - x2 - y2 + z2)*invDenom;
   mfRotate[3][2] = 0;

   mfRotate[0][3] = 0;
   mfRotate[1][3] = 0;
   mfRotate[2][3] = 0;
	mfRotate[3][3] = 1;
#else

	// USING THIS ONE
	xy2 = 2*x*y ;
	tz2 = 2*t*z ;
	xz2 = 2*x*z ;
	ty2 = 2*t*y ;
	yz2 = 2*y*z ;
	tx2 = 2*t*x ;


	mfRotate[0][0] = t2 + x2 - y2 - z2;
   mfRotate[0][1] = xy2 + tz2 ; //2*x*y + 2*t*z;
   mfRotate[0][2] = xz2 - ty2 ; //2*x*z - 2*t*y;
   mfRotate[0][3] = 0;

	mfRotate[1][0] = xy2 - tz2 ; //2*x*y - 2*t*z;
   mfRotate[1][1] = t2 - x2 + y2 - z2;
   mfRotate[1][2] = yz2 + tx2 ; //2*y*z + 2*t*x;
   mfRotate[1][3] = 0;

   mfRotate[2][0] = xz2 + ty2 ; //2*x*z + 2*t*y;
   mfRotate[2][1] = yz2 - tx2 ; //2*y*z - 2*t*x;
   mfRotate[2][2] = t2 - x2 - y2 + z2;
   mfRotate[2][3] = 0;

   mfRotate[3][0] = 0;
   mfRotate[3][1] = 0;
   mfRotate[3][2] = 0;
	mfRotate[3][3] = 1;
#endif
}
