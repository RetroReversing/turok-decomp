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
typedef struct CDynamicList_t
{
 CList m_FreeList ;
 CList m_ActiveList ;
} CDynamicList ;
extern void func_80043940(CList *pThis, CNode *pNode) ;
extern void func_80043988(CList *pThis, CNode *pNode) ;
extern CNode *func_80043A60(CDynamicList *pThis) ;
void func_80043940(CList *pThis, CNode *pNode);
void func_80043988(CList *pThis, CNode *pNode);
CNode *func_80043A60(CDynamicList *pThis);
CNode *func_80043A60(CDynamicList *pThis){
 CNode *pNode ;
 pNode = pThis->m_FreeList.m_pHead ;
 if (pNode)
 {
  func_80043988(&pThis->m_FreeList, pNode) ;
  func_80043940(&pThis->m_ActiveList, pNode) ;
 }
 return pNode ;
}
