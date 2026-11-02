#include "decompdecomp_sync_6dec8abb6d34ae0339d0.h"
#line 1 "func.c"
#line 19 "reference.c"
void _Litob(_Pft *px, char code)
{	/* convert unsigned long to text */
	char ac[24];	/* safe for 64-bit integers */
	char *digs = code == 'X' ? udigs : ldigs;
	int base = code == 'o' ? 8 : code != 'x' && code != 'X' ? 10 : 16;
	int i = sizeof(ac);
	unsigned long long ullval = px->v.ll;

	if ((code == 'd' || code == 'i') && px->v.ll < 0)
		ullval = -ullval;	/* safe against overflow */
	if (ullval || px->prec)
		ac[--i] = digs[func_8009D38C(ullval, base)];
	px->v.ll = __ull_div(ullval, base);
	while (0 < px->v.ll && 0 < i) {	/* convert digits */
		lldiv_t qr = lldiv(px->v.ll, (long long) base);

		px->v.ll = qr.quot;
		ac[--i] = digs[qr.rem];
	}
	px->n1 = sizeof(ac) - i;
	memcpy(px->s, &ac[i], px->n1);
	if (px->n1 < px->prec)
		px->nz0 = px->prec - px->n1;
	if (px->prec < 0 && (px->flags & (_FMI | _FZE)) == _FZE
		&& 0 < (i = px->width - px->n0 - px->nz0 - px->n1))
		px->nz0 += i;
}

