#include "common.h"

enum CheatCodeSelections
{
 CHEATCODE_GRID1,
 CHEATCODE_GRID2,
 CHEATCODE_GRID3,
 CHEATCODE_GRID4,
 CHEATCODE_DELETE,
 CHEATCODE_ENTER,
 CHEATCODE_EXIT,
 CHEATCODE_END_SELECTION
} ;
typedef struct CCheatCode_t
{
 float m_Alpha ;
 signed short m_Mode ;
 int b_Active ;
 signed long m_Selection ;
 signed long m_SubSelection ;
 signed long m_EntryPos ;
} CCheatCode ;
extern float D_800EC0C0 ;
typedef struct s_CheatCodeEntry
{
 int items ;
 int Spacing ;
 char *String ;
} t_CheatCodeEntry ;
extern t_CheatCodeEntry D_800B8210[];
void func_8000EF04(CCheatCode *pThis);
void func_8000EF04(CCheatCode *pThis){
 D_800EC0C0 = 0 ;
 pThis->m_Selection-- ;
 if (pThis->m_Selection < 0)
  pThis->m_Selection = CHEATCODE_END_SELECTION-1 ;
 if (D_800B8210[pThis->m_Selection].items != 0)
 {
  if (pThis->m_SubSelection >= D_800B8210[pThis->m_Selection].items)
   pThis->m_SubSelection = D_800B8210[pThis->m_Selection].items -1;
 }
 else
   pThis->m_SubSelection = 0 ;
}
