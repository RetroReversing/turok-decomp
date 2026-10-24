#include "common.h"

enum TitleSelections
{
 TITLE_START,
 TITLE_LOAD,
 TITLE_TRAINING,
 TITLE_OPTIONS,
 TITLE_DIFFICULTY,
 TITLE_ENTERCHEAT,
 TITLE_CHEATMENU,
 TITLE_END_SELECTION
} ;
typedef struct CPause_t
{
 signed long m_Mode ;
 float m_Alpha ;
 signed long m_Selection ;
 int m_RealSelection;
} CPause ;
extern char D_801293A0[TITLE_END_SELECTION];
extern int func_80084E44(CPause *pThis);
int func_80084E44(CPause *pThis);
int func_80084E44(CPause *pThis){
 int nTotal = 0,
   cnt;
 for (cnt=0; cnt<TITLE_END_SELECTION; cnt++)
  nTotal += D_801293A0[cnt];
 return nTotal;
}
