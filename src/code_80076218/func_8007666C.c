#include "common_local_source_5334.h"

#line 2002 "reference.c"
void func_8007666C(CGameObjectInstance *pMe)
{
	INT32	Anim ;
	FLOAT	AssistFactor ;

	// Avoidance angle been setup, and attacking someone?
	if ((AI_GetDyn(pMe)->m_AvoidanceAngle == 0) || (!pMe->m_pAttackerCGameObjectInstance))
		return ;

	// Set assist amount
	switch(CGameObjectInstance__TypeFlag(pMe))
	{
		case AI_OBJECT_CHARACTER_HULK:
			AssistFactor = 0.25 ;
			break;

		case AI_OBJECT_CHARACTER_DIMETRODON:
			AssistFactor = 0.0;
			break;

		default:
			AssistFactor = 1 ;
	}

	// Get current anim
	Anim = CGameObjectInstance__GetCurrentAnim(pMe) ;
	Anim = CGameObjectInstance__LookupAIAnimType(pMe, Anim) ;
	switch(Anim)
	{
		case AI_ANIM_TURNL90:
		case AI_ANIM_TURNR90:
		case AI_ANIM_TURN180:
		case AI_ANIM_TURNL902:
		case AI_ANIM_TURNR902:
		case AI_ANIM_TURN1802:
			func_800765B4(pMe, AI_ASSIST_TURN_SPEED*AssistFactor) ;
			break ;

		case AI_ANIM_WTURNL90:
		case AI_ANIM_WTURNR90:
		case AI_ANIM_WTURN180:
		case AI_ANIM_WTURNL902:
		case AI_ANIM_WTURNR902:
		case AI_ANIM_WTURN1802:
			func_800765B4(pMe, AI_ASSIST_WTURN_SPEED*AssistFactor) ;
			break ;

		case AI_ANIM_RTURNL90:
		case AI_ANIM_RTURNR90:
		case AI_ANIM_RTURN180:
		case AI_ANIM_RTURNL902:
		case AI_ANIM_RTURNR902:
		case AI_ANIM_RTURN1802:
			func_800765B4(pMe, AI_ASSIST_RTURN_SPEED*AssistFactor) ;
			break ;

		case AI_ANIM_WALK:
		case AI_ANIM_WALK2:
			func_800765B4(pMe, AI_ASSIST_WALK_SPEED*AssistFactor) ;
			break ;

		case AI_ANIM_RUN:
		case AI_ANIM_RUN2:
			func_800765B4(pMe, AI_ASSIST_RUN_SPEED*AssistFactor) ;
			break ;
	}

	// Clear avoidance angle
	AI_GetDyn(pMe)->m_AvoidanceAngle = 0 ;
}
