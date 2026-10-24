#include "common.h"

typedef struct CNode_t
{
 struct CNode_t *m_pPrev ;
 struct CNode_t *m_pNext ;
} CNode ;
typedef struct CList_t
{
 CNode *m_pHead ;
 CNode *m_pTail ;
 signed long m_Length ;
} CList ;
extern void func_80043940(CList *pThis, CNode *pNode) ;
void func_80043940(CList *pThis, CNode *pNode);
void func_80043940(CList *pThis, CNode *pNode){
 if (!pThis->m_Length)
 {
  pThis->m_pHead = pNode ;
  pThis->m_pTail = pNode ;
  pNode->m_pPrev = ((void*)0) ;
  pNode->m_pNext = ((void*)0) ;
 }
 else
 {
  pNode->m_pPrev = pThis->m_pTail ;
  pNode->m_pNext = ((void*)0) ;
  pThis->m_pTail->m_pNext = pNode ;
  pThis->m_pTail = pNode ;
 }
 pThis->m_Length++ ;
}
