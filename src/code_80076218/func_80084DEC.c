#include "common.h"

enum PauseSelections
{
 PAUSE_RESUME,
 PAUSE_OPTIONS,
 PAUSE_KEYS,
 PAUSE_LOAD,
 PAUSE_ENTERCHEAT,
 PAUSE_CHEATMENU,
 PAUSE_RESTART_GAME,
 PAUSE_END_SELECTION
} ;
typedef struct CPause_t
{
 signed long m_Mode ;
 float m_Alpha ;
 signed long m_Selection ;
 int m_RealSelection;
} CPause ;
extern char D_80129384[PAUSE_END_SELECTION];
extern int func_80084DEC(CPause *pThis);
int func_80084DEC(CPause *pThis);
int func_80084DEC(CPause *pThis){
 int nTotal = 0,
   cnt;
 for (cnt=0; cnt<PAUSE_END_SELECTION; cnt++)
  nTotal += D_80129384[cnt];
 return nTotal;
}
