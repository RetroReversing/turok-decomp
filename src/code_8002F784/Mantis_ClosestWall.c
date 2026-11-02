#include "decompdecomp_sync_930d1ec4e69fea65baa4.h"
#line 1 "func.c"
#line 17864 "reference.c"
INT32 Mantis_ClosestWall(CGameObjectInstance *pThis, CMantis *pMantis)
{
	INT32		i ;
	INT32		Chosen ;
	FLOAT		ClosestDistSqr, XDist, ZDist, DistSqr ;

	Chosen = -1 ;

	// Interrupted?
	if ((pMantis->m_WallToAimFor != -1) && (!pMantis->m_WallBroken[pMantis->m_WallToAimFor]))
		Chosen = pMantis->m_WallToAimFor ;
	else
	// Never chosen before?
	if (pMantis->m_WallToAimFor == -1)
		Chosen = func_8004045C(pThis, &D_800BC604[0], 4) ;
	else
	// Choose the logical next wall!
	switch(pMantis->m_WallToAimFor)
	{
		case 0:
			if (pMantis->m_WallToAimForJumpPos == 0)
				Chosen = 1 ;
			else
			if (pMantis->m_WallToAimForJumpPos == 1)
				Chosen = 3 ;
			break ;

		case 1:
			if (pMantis->m_WallToAimForJumpPos == 2)
				Chosen = 2 ;
			else
			if (pMantis->m_WallToAimForJumpPos == 3)
				Chosen = 0 ;
			break ;

		case 2:
			if (pMantis->m_WallToAimForJumpPos == 4)
				Chosen = 3 ;
			else
			if (pMantis->m_WallToAimForJumpPos == 5)
				Chosen = 1 ;
			break ;

		case 3:
			if (pMantis->m_WallToAimForJumpPos == 6)
				Chosen = 0 ;
			else
			if (pMantis->m_WallToAimForJumpPos == 7)
				Chosen = 2 ;
			break ;
	}

	// Select closest if wall has already been knocked down!
	if ((Chosen == -1) || (pMantis->m_WallBroken[Chosen]))
	{
		// Set dist to max
		Chosen = -1 ;
		ClosestDistSqr = 0 ;	// Fix warning!

		// Check all walls
		for (i = 0 ; i < 4 ; i++)
		{
			// This wall broken?
			if (!pMantis->m_WallBroken[i])
			{
				// Get dist squared from mantis
				XDist = D_800BC604[i].x - BOSS_GetPos(pThis).x ;
				ZDist = D_800BC604[i].z - BOSS_GetPos(pThis).z ;
				DistSqr = (XDist * XDist) + (ZDist * ZDist) ;

				// Is this the closest wall so far?
				if ((Chosen == -1) || (DistSqr < ClosestDistSqr))
				{
					Chosen = i ;
					ClosestDistSqr = DistSqr ;
				}
			}
		}
	}

	// Choose jump position for wall
 	pMantis->m_WallToAimFor = Chosen ;
	if (Chosen != -1)
	{
		func_80044A34(pThis, pMantis) ;

                
                                               
                               
                                        
      

	}

	return pMantis->m_WallToAimFor ;
}

