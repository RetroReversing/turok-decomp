#include "common.h"

typedef struct CIndexedSet_t
{
    void *m_pData;
    int m_AutoDeleteData;
} CIndexedSet;

void *func_80011FA0(int, void *);
void func_80011DDC(void *);

u32 func_8002DBF8(CIndexedSet *pThis, u32 arg1, int nBlock, u32 *pLength) ;
                                                       
                                                     
                                  
 

void func_8002DB84(void *arg0) ;
                 
                                            
                            
                 
                                    
                           
                           
 

void func_8002DCA4(CIndexedSet *pThis, void **ppData, u32 *pSize) {
    *ppData = pThis->m_pData;
    *pSize = ((u32 *)pThis->m_pData)[1 + ((u32 *)pThis->m_pData)[0]];
    pThis->m_AutoDeleteData = 0;
}

void func_8002DCCC(CIndexedSet *pThis, void *pNewData, int autoDelete) ;
