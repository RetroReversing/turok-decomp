#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"
extern const double D_800F1DA0;
extern float __sinf(float angle);
extern float DecelerateFLOAT(float Var, float Decel);
typedef struct CShake_t
{
  float m_Shake;
  float m_LastShake;
  float m_Amp;
  float m_Angle;
} CShake;
extern float D_800B6B00;
extern float CShake__Update(CShake *pThis);
float CShake__Update(CShake *pThis);
float CShake__Update(CShake *pThis)
{
  float Shake = 0;
  if (pThis->m_Shake > pThis->m_LastShake)
    pThis->m_LastShake = pThis->m_Shake;
  if (pThis->m_Amp == 0)
    pThis->m_Angle = 90;
  if (pThis->m_Amp < (pThis->m_LastShake * 2))
    pThis->m_Amp = pThis->m_LastShake * 2;
  *(&pThis->m_Shake) = DecelerateFLOAT(*(&pThis->m_Shake), D_800B6B00 * 3);
  *(&pThis->m_LastShake) = DecelerateFLOAT(*(&pThis->m_LastShake), D_800B6B00 * 3);
  if (pThis->m_Amp > 0)
  {
    Shake = __sinf(pThis->m_Angle * D_800F1DA0) * pThis->m_Amp;
    /* Make speed proportional to amplitude */ pThis->m_Angle += ((pThis->m_Amp * 2) * 3) * D_800B6B00;
    *(&pThis->m_Amp) = DecelerateFLOAT(*(&pThis->m_Amp), 2 * 3);
  }
  return Shake;
}
