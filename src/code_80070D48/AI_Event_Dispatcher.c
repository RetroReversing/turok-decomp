#include "decompdecomp_sync_90cf2c2843980e1c3231.h"
#line 1 "func.c"
#line 1606 "reference.c"
void AI_Event_Dispatcher(CInstanceHdr *pThis, CInstanceHdr *pOrigin,
								 int Event, DWORD dwSpecies,
								 CVector3 vPos, float Value)
{
	int						cAI, nAIs;
	CGameObjectInstance	*pAI, *instances;
	CUnindexedSet			usInstances;
	CEngineApp				*pApp;
	BOOL						gamepaused;

	TRACE("Event: %s\r\n", AI_Event_Strings[Event]);


	// is game paused - save points or user pressing pause ?
	gamepaused = (GetApp()->m_bPause && GetApp()->m_Mode == MODE_GAME);

	// save certain events for boss levels
	if (		GetApp()->m_pBossActive
			&&	(		(Event == AI_SEVENT_DOOR_ALLOWENTRY)
					||	(Event == AI_SEVENT_DOOR_BLOCKENTRY) ) )
	{
		CBossesStatus__SaveEvent(&GetApp()->m_BossesStatus, pOrigin, Event, vPos, Value) ;
	}

	if (		(IsSingleEvent(Event))
			&&	(!gamepaused) )
	{
		AI_Single_Event(pThis, pOrigin, Event, vPos, Value);
	}
	else
	{
		pApp = GetApp();

		if (SendEventToWholeWorld(Event))
		{
			ASSERT(pApp->m_Scene.m_pceInstances);

			CUnindexedSet__ConstructFromRawData(&usInstances,
															CCacheEntry__GetData(pApp->m_Scene.m_pceInstances),
															FALSE);

			instances = (CGameObjectInstance*) CUnindexedSet__GetBasePtr(&usInstances);
			nAIs = CUnindexedSet__GetBlockCount(&usInstances);

			for (cAI=0; cAI<nAIs; cAI++)
			{
				pAI = &instances[cAI];

				// don't send event to self
				if ( ((&pAI->ah.ih) != pThis) && (AI_GetEA(pAI)->m_dwSpecies & dwSpecies) )
					AI_Multi_Event(pAI, pOrigin, Event, vPos, Value);
			}

			CUnindexedSet__Destruct(&usInstances);
		}
		else if (!gamepaused)
		{
			nAIs = CEngineApp__GetAnimInstanceCount(pApp);
			for (cAI=0; cAI<nAIs; cAI++)
			{
				pAI = CEngineApp__GetAnimInstance(pApp, cAI);

				// don't send event to self
				if ( ((&pAI->ah.ih) != pThis) && (AI_GetEA(pAI)->m_dwSpecies & dwSpecies) )
					AI_Multi_Event(pAI, pOrigin, Event, vPos, Value);
			}
		}
	}
}

