#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

typedef unsigned short sa_u16;
extern sa_u16 D_800B8190[32];
extern int D_800B81F4;
extern int D_800B81F8;
extern void CCheatCode__ClearData(void) ;
void CCheatCode__ClearData(void);
//-----------------------------------------------------------------------------------------------------
// Clear data, and positional vars
//-----------------------------------------------------------------------------------------------------
void CCheatCode__ClearData(void)
{
	int	i ;
	D_800B81F4 = 0 ;
	D_800B81F8 = 0 ;

	for (i=0; i<sizeof(D_800B8190) / sizeof(sa_u16); i++)
		D_800B8190[i] = 0 ;
}
