#include "common.h"

extern const double D_800F6B90;
typedef unsigned long long sa_u64;
typedef long sa_s32;
extern void func_800A1760(void *, sa_s32);
typedef struct CVector3_t
{
  float x;
  float y;
  float z;
} CVector3;
typedef struct CSunFrameData_t
{
  sa_u64 m_DepthData[2];
  int m_DepthPos;
  int m_Visible;
  int m_VisibleZ;
  int align;
} CSunFrameData;
extern void func_800984BC(CSunFrameData *pThis);
typedef struct CSun_t
{
  int m_nBuffer;
  int m_nReceived;
  float m_ScreenX;
  float m_ScreenY;
  float m_Opacity;
  CVector3 m_vDir;
  int m_Visible;
} CSun;
extern CSun D_80135BE0;
extern CSun D_80135BE0;
void func_800984BC(CSunFrameData *pThis);
void func_800984BC(CSunFrameData *pThis)
{
  unsigned short *zValues;
  int i;
  int v;
  ;
  func_800A1760(pThis->m_DepthData, 2 * (sizeof(sa_u64)));
  ;
  if (pThis->m_Visible)
  {
    zValues = (unsigned short *) pThis->m_DepthData;
    v = 0;
    for (i = 0; i < 8; i++)
    {
      if (zValues[i] > 0xfff0)
      {
        if (i == pThis->m_DepthPos)
          v += 3;
        else
          v++;
      }
    }

    D_80135BE0.m_Opacity = v * D_800F6B90;
  }
  D_80135BE0.m_Visible = pThis->m_Visible;
}
