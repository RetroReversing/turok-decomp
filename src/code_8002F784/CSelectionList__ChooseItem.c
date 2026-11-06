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
extern signed short CSelection__Choose(CSelection *pList) ;
extern signed short CSelectionList__ChooseItem(CSelectionList *pThis) ;
signed short CSelection__Choose(CSelection *pThis);
signed short CSelectionList__ChooseItem(CSelectionList *pThis);
signed short CSelectionList__ChooseItem(CSelectionList *pThis){
 if (!pThis->m_Entries)
  return 0 ;
 pThis->m_List[pThis->m_Entries].m_Number = -1 ;
 return CSelection__Choose(pThis->m_List) ;
}
