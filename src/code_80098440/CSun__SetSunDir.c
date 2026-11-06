#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void CVector3__Normalize(CVector3 *pvThis);
typedef struct CSun_t
{
 int m_nBuffer, m_nReceived;
 float m_ScreenX, m_ScreenY,
     m_Opacity;
 CVector3 m_vDir;
 int m_Visible;
} CSun;
extern void CSun__SetSunDir(CSun *pThis, CVector3 *pvDir);
void CSun__SetSunDir(CSun *pThis, CVector3 *pvDir);
void CSun__SetSunDir(CSun *pThis, CVector3 *pvDir){
 pThis->m_vDir = *pvDir;
 CVector3__Normalize(&pThis->m_vDir);
}
