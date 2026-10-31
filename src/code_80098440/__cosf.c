#include "common.h"

extern f64 D_800F6D90[],D_800F6DB8,D_800F6DC0,D_800F6DC8;extern f32 D_800F7250,D_800F6DD0;
#define ABS(d) (((d)>0)?(d):-(d))
#define ROUND(d) (int)(((d)>=0.0)?((d)+0.5):((d)-0.5))
float
__cosf( float x )
{
float	absx;
double	dx, xsq, poly;
double	dn;
int	n;
double	result;
int	ix, xpt;


	ix = *(int *)&x;
	xpt = (ix >> 22);
	xpt &= 0x1ff;

	/* xpt is exponent(x) + 1 bit of mantissa */


	if ( xpt < 0x136 )
	{
		/* |x| < 2^28 */

		/* use the standard algorithm from Cody and Waite, doing
		   the computations in double precision
		*/

		absx = ABS(x);

		dx = absx;

		dn = dx*D_800F6DB8 + 0.5;
		n = ROUND(dn);
		dn = n;

		dn -= 0.5;

		dx = dx - dn*D_800F6DC0;
		dx = dx - dn*D_800F6DC8;	/* dx = x - (n - 0.5)*pi */

		xsq = dx*dx;

		poly = ((D_800F6D90[4]*xsq + D_800F6D90[3])*xsq + D_800F6D90[2])*xsq + D_800F6D90[1];

		result = dx + (dx*xsq)*poly;

		/* negate result if n is odd */

		if ( (n & 1) == 0 )
			return ( (float)result );

		return ( -(float)result );
	}

	if ( x != x )
	{
		/* x is a NaN; return a quiet NaN */


		
		return ( D_800F7250 );
	}

	/* just give up and return 0.0 */

	return ( D_800F6DD0 );
}
