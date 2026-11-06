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
extern void CList__Construct(CList *pThis) ;
extern void CList__AppendNode(CList *pThis, CNode *pNode) ;
extern void CDynamicList__Construct(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total) ;
void CList__Construct(CList *pThis);
void CList__AppendNode(CList *pThis, CNode *pNode);
void CDynamicList__Construct(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total);
void CDynamicList__Construct(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total){
 CList__Construct(&pThis->m_FreeList) ;
 CList__Construct(&pThis->m_ActiveList) ;
 while(Total--)
 {
  CList__AppendNode(&pThis->m_FreeList, (CNode *)NodeData) ;
  NodeData += NodeSize;
 }
}
