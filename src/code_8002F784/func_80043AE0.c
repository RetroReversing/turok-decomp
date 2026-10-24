#include "common.h"

typedef struct CSelection_t
{
 signed short m_Number ;
 signed short m_Weight ;
} CSelection ;
extern signed short func_80043AE0(CSelection *pList) ;
signed short func_80043AE0(CSelection *pThis);
signed short func_80043AE0(CSelection *pThis){
 CSelection *pSelect ;
 signed long TotalWeight, Random ;
 pSelect = pThis ;
 TotalWeight = 0 ;
 while(pSelect->m_Number != -1)
 {
  TotalWeight += pSelect->m_Weight ;
  pSelect++ ;
 }
 Random = (D_800137A0() % (TotalWeight)) ;
 pSelect = pThis ;
 TotalWeight = 0 ;
 while(pSelect->m_Number != -1)
 {
  TotalWeight += pSelect->m_Weight ;
  if (TotalWeight >= Random)
   break ;
  pSelect++ ;
 }
 return pSelect->m_Number ;
}
