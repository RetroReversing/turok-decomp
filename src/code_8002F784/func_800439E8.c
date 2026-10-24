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
extern void func_80043930(CList *pThis) ;
extern void func_80043940(CList *pThis, CNode *pNode) ;
extern void func_800439E8(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total) ;
void func_80043930(CList *pThis);
void func_80043940(CList *pThis, CNode *pNode);
void func_800439E8(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total);
void func_800439E8(CDynamicList *pThis, unsigned char *NodeData, signed long NodeSize, signed long Total){
 func_80043930(&pThis->m_FreeList) ;
 func_80043930(&pThis->m_ActiveList) ;
 while(Total--)
 {
  func_80043940(&pThis->m_FreeList, (CNode *)NodeData) ;
  NodeData += NodeSize;
 }
}
