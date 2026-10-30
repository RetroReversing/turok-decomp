#include "common_local_source_3888.h"

#line 9552 "reference.c"
int func_80015D20(CInstanceHdr *pThis, int nNode)
{
	int nKey, nTexture, id;
	BOOL	hilite = FALSE ;

	switch (pThis->m_pEA->m_Id)
	{
		case 40:
		case 41:
		case 42:
			nKey = CTurokMovement.Level4Keys;
			nTexture = 2;
			break ;
		case 50:
		case 51:
		case 52:
			nKey = CTurokMovement.Level5Keys;
			nTexture = 3;
			break ;
		case 60:
		case 61:
		case 62:
			nKey = CTurokMovement.Level6Keys;
			nTexture = 4;
			break ;
		case 70:
		case 71:
		case 72:
			nKey = CTurokMovement.Level7Keys;
			nTexture = 5;
			break ;
		case 80:
		case 81:
		case 82:
		case 83:
		case 84:
			nKey = CTurokMovement.Level8Keys;
			nTexture = 6;
			break ;

		// chronosceptor piece
		case 100:
		case 101:
		case 102:
		case 103:
		case 104:
		case 105:
		case 106:
		case 107:
			nKey = CTurokMovement.ChronoSceptorPieces;
			nTexture = 0;
			break ;


		//default:
		//	return pThis->ah.ih.m_pEA->m_nTexture;
	}

	id = pThis->m_pEA->m_Id % 10 ;

	// regular key pieces
	if (!(nKey & (1<<id)))
		hilite = TRUE ;

	if (hilite)
	{
		fx_mode = FXMODE_TOCOLOR;
		fx_color[0] = 0;		// env r
		fx_color[1] = 0;		// env g
 		fx_color[2] = 0;		// env b
 		fx_color[3] = 180;	// env a		0: 0% color, 255: 100% color
 	}
	return nTexture;
}
