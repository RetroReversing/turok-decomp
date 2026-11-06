#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef int BOOL;typedef struct {float x,y,z;} CVector3;
typedef struct {u8 pad[0x20];float m_CollisionHeight;} CEnemyAttributes;
typedef struct {u8 m_Type,m_bActiveFlags;u16 m_nObjType;CVector3 m_vPos;float m_CollisionHeightOffset;void*m_pCurrentRegion;CEnemyAttributes*m_pEA;} CInstanceHdr;
typedef struct {CInstanceHdr ih;CVector3 m_vVelocity;} CAnimInstanceHdr;
extern u8 D_80136820;
int CAnimInstanceHdr__Collision3(CAnimInstanceHdr*,CVector3,void*);
#define CAnimInstanceHdr__Collision3 CAnimInstanceHdr__Collision3
#define ci_raycast D_80136820
#define ASSERT(x)









BOOL CAnimInstanceHdr__CastYeThyRay(CAnimInstanceHdr *pThis, CInstanceHdr *pTarget)
{
	CAnimInstanceHdr	ah;
	CVector3				vDesired;
	int					collisions;

	ASSERT(cache_is_valid);

	ah = *pThis;

	pThis->ih.m_vPos.y += 0.8*pThis->ih.m_pEA->m_CollisionHeight;

	vDesired = pTarget->m_vPos;
	vDesired.y += 0.8*pTarget->m_pEA->m_CollisionHeight;

	collisions = CAnimInstanceHdr__Collision3(pThis, vDesired, &ci_raycast);
	
	*pThis = ah;
	
	return !collisions;
}

