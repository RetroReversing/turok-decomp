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
extern void func_80043BAC(CSelectionList *pThis, signed short Item, signed short Weight) ;
void func_80043BAC(CSelectionList *pThis, signed short Item, signed short Weight);
void func_80043BAC(CSelectionList *pThis, signed short Item, signed short Weight){
 pThis->m_List[pThis->m_Entries].m_Number = Item ;
 pThis->m_List[pThis->m_Entries].m_Weight = Weight ;
 pThis->m_Entries++ ;
}
