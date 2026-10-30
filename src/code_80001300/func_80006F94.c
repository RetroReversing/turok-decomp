#include "common_local_source_3719.h"

#line 1 "reference.c"
void func_80006F94(CEngineApp *pThis)
{
	CVector3	vDir ;
	int	i ;
	float speed;
	float ambri;

#ifndef KANJI
	if (GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO)
	{
		speed = 2.5;
		ambri = 2.0;
	}
	else
#endif
	{
		speed = 1.0;
		ambri = 1.0;
	}

	// Setup ambient and directional light
	for (i=0; i<3; i++)
	{
		D_800BEC40.a.l.colc[i] = D_800BEC40.a.l.col[i] = (ambri * 16 * sin(ANGLE_DTOR(speed * D_800B6AF8 * 4 * (2+i)))) + 16 + 48 ;	// ambient color
		D_800BEC40.l[0].l.colc[i] = D_800BEC40.l[0].l.col[i] = (64 * sin(ANGLE_DTOR(speed * D_800B6AF8 * 4 * (2+i)))) + 255-64-1 ;	// directional color
	}

	// Set direction
	vDir.x = sin(ANGLE_DTOR(D_800B6AF8 * 3*2)) ;
	vDir.y = sin(ANGLE_DTOR(D_800B6AF8 * 4*2)) ;
	vDir.z = cos(ANGLE_DTOR(D_800B6AF8 * 5*2)) ;
	func_80013B2C(&vDir) ;
	vDir.x *= 120 ;
	vDir.y *= 120 ;
	vDir.z *= 120 ;
	D_800BEC40.l[0].l.dir[0] = vDir.x ;
	D_800BEC40.l[0].l.dir[1] = vDir.y ;
	D_800BEC40.l[0].l.dir[2] = vDir.z ;

	// Set fog color
#ifndef KANJI
	if (!(GetApp()->m_dwCheatFlags & CHEATFLAG_DISCO))
#endif
	{
		pThis->m_LastFogColor[0] = pThis->m_FogColor[0] = (BYTE)((64 * sin(ANGLE_DTOR(speed * D_800B6AF8 * 2 * 4))) + 128) & 0xf8 ;
		pThis->m_LastFogColor[1] = pThis->m_FogColor[1] = (BYTE)((64 * sin(ANGLE_DTOR(speed * D_800B6AF8 * 3 * 4))) + 128) & 0xf8 ;
		pThis->m_LastFogColor[2] = pThis->m_FogColor[2] = (BYTE)((64 * sin(ANGLE_DTOR(speed * D_800B6AF8 * 4 * 4))) + 128) & 0xf8 ;
	}
}
