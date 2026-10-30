#include "common.h"

extern const double D_800F1DA0;
extern float __sinf(float angle);
extern float func_80040A0C(float Var, float Decel);
typedef struct CShake_t
{
  float m_Shake;
  float m_LastShake;
  float m_Amp;
  float m_Angle;
} CShake;
extern float D_800B6B00;
extern float func_80037728(CShake *pThis);
float func_80037728(CShake *pThis);
float func_80037728(CShake *pThis)
{
  float Shake = 0;
  if (pThis->m_Shake > pThis->m_LastShake)
    pThis->m_LastShake = pThis->m_Shake;
  if (pThis->m_Amp == 0)
    pThis->m_Angle = 90;
  if (pThis->m_Amp < (pThis->m_LastShake * 2))
    pThis->m_Amp = pThis->m_LastShake * 2;
  *(&pThis->m_Shake) = func_80040A0C(*(&pThis->m_Shake), D_800B6B00 * 3);
  *(&pThis->m_LastShake) = func_80040A0C(*(&pThis->m_LastShake), D_800B6B00 * 3);
  if (pThis->m_Amp > 0)
  {
    Shake = __sinf(pThis->m_Angle * D_800F1DA0) * pThis->m_Amp;
    pThis->m_Angle += ((pThis->m_Amp * 2) * 3) * D_800B6B00;
    *(&pThis->m_Amp) = func_80040A0C(*(&pThis->m_Amp), 2 * 3);
  }
  return Shake;
}
