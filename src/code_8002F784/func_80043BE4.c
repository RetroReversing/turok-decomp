#include "common.h"

typedef struct CSelection_t
{
 signed short m_Number ;
 signed short m_Weight ;
} CSelection ;
typedef struct CSelectionList_t
{
 signed short m_Entries ;
 CSelection m_List[24] ;
} CSelectionList ;
extern signed short func_80043AE0(CSelection *pList) ;
extern signed short func_80043BE4(CSelectionList *pThis) ;
signed short func_80043AE0(CSelection *pThis);
signed short func_80043BE4(CSelectionList *pThis);
signed short func_80043BE4(CSelectionList *pThis){
 if (!pThis->m_Entries)
  return 0 ;
 pThis->m_List[pThis->m_Entries].m_Number = -1 ;
 return func_80043AE0(pThis->m_List) ;
}
