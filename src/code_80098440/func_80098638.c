#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
extern void func_80013B2C(CVector3 *pvThis);
typedef struct CSun_t
{
 int m_nBuffer, m_nReceived;
 float m_ScreenX, m_ScreenY,
     m_Opacity;
 CVector3 m_vDir;
 int m_Visible;
} CSun;
extern void func_80098638(CSun *pThis, CVector3 *pvDir);
void func_80098638(CSun *pThis, CVector3 *pvDir);
void func_80098638(CSun *pThis, CVector3 *pvDir){
 pThis->m_vDir = *pvDir;
 func_80013B2C(&pThis->m_vDir);
}
