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
extern void CList__AppendNode(CList *pThis, CNode *pNode) ;
extern void CList__DeleteNode(CList *pThis, CNode *pNode) ;
extern CNode *CDynamicList__AllocateNode(CDynamicList *pThis) ;
void CList__AppendNode(CList *pThis, CNode *pNode);
void CList__DeleteNode(CList *pThis, CNode *pNode);
CNode *CDynamicList__AllocateNode(CDynamicList *pThis);
CNode *CDynamicList__AllocateNode(CDynamicList *pThis){
 CNode *pNode ;
 pNode = pThis->m_FreeList.m_pHead ;
 if (pNode)
 {
  CList__DeleteNode(&pThis->m_FreeList, pNode) ;
  CList__AppendNode(&pThis->m_ActiveList, pNode) ;
 }
 return pNode ;
}
