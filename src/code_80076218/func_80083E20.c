#include "common.h"

typedef struct CEnemyAttributes_t
{
 float m_SightRadius,
     m_SightAngle,
     m_LoudRadius,
     m_QuietRadius,
     m_ProjectileRadius,
     m_FlyingHeight,
     m_CollisionRadius,
     m_CollisionWallRadius,
     m_CollisionHeight,
     m_DeadHeight,
     m_AttackRadius,
     m_LeashRadius,
     m_InteractiveAnimDelay;
 unsigned long m_dwSpecies,
     m_dwTypeFlags,
     m_dwTypeFlags2;
 unsigned short m_wTypeFlags3;
 short m_StartHealth,
     m_Id,
     m_DeathId,
     m_Regenerate;
 unsigned char m_Aggression,
     m_InteractiveAnim,
     m_nModel;
 signed char m_nTexture,
     m_AttackStyle;
 unsigned char unused1;
} CEnemyAttributes;
extern void func_80083E20(CEnemyAttributes *pThis);
void func_80083E20(CEnemyAttributes *pThis);
void func_80083E20(CEnemyAttributes *pThis){
 pThis->m_SightRadius = 70;
 pThis->m_SightAngle = ((90)*(3.14159265358979323846/180));
 pThis->m_QuietRadius = 20;
 pThis->m_LoudRadius = 150;
 pThis->m_ProjectileRadius = 60;
 pThis->m_LeashRadius = 150;
 pThis->m_CollisionRadius = 4;
 pThis->m_CollisionWallRadius = 4;
 pThis->m_CollisionHeight = 7;
 pThis->m_DeadHeight = 3;
 pThis->m_AttackRadius = 12;
 pThis->m_AttackStyle = 100;
 pThis->m_Aggression = 100;
 pThis->m_dwTypeFlags = (1<<3) | (1<<17) | (1<<20) | (1<<19);
 pThis->m_StartHealth = 100;
 pThis->m_Id = 100;
 pThis->m_DeathId = 0;
 pThis->m_Regenerate = 0;
 pThis->m_dwSpecies = (unsigned long) -1;
 pThis->m_InteractiveAnim = 0;
 pThis->m_InteractiveAnimDelay = 0;
 pThis->m_FlyingHeight = 30;
 pThis->m_dwTypeFlags2 = (1<<22);
 pThis->m_nModel = 0;
 pThis->m_nTexture = -1;
 pThis->m_wTypeFlags3 = 0;
 pThis->unused1 = 0;
}
