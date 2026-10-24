#include "common.h"

typedef struct CVector3_t
{
 float x, y, z;
} CVector3;
typedef struct CROMCornerEnc_t
{
 long x, y, z, c;
} CROMCornerEnc;
typedef struct CROMCorner_t
{
   CVector3 m_vCorner;
   float m_Ceiling;
} CROMCorner;
void func_80021B28(CROMCorner *pThis);
void func_80021B28(CROMCorner *pThis){
 CROMCornerEnc *pEnc = (CROMCornerEnc*) pThis;
 pThis->m_vCorner.x = ( (float) ((pEnc->x)*((float)(((1500.0*(1 << (32 - 20)))*(1024.0/100.0))))/2147483648.0f) );
 pThis->m_vCorner.y = ( (float) ((pEnc->y)*((float)(((1500.0*(1 << (32 - 20)))*(1024.0/100.0))))/2147483648.0f) );
 pThis->m_vCorner.z = ( (float) ((pEnc->z)*((float)(((1500.0*(1 << (32 - 20)))*(1024.0/100.0))))/2147483648.0f) );
 pThis->m_Ceiling = ( (float) ((pEnc->c)*((float)(((1500.0*(1 << (32 - 20)))*(1024.0/100.0))))/2147483648.0f) );
}
