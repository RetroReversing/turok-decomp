#include "source_ScanFileList.h"

extern char D_800B86FC[];
extern void *func_8009FA50(void*,const void*,s32);
#line 1 "reference.c"
int ScanFileList(BOOL showall)
{
	int	ret, i, c ;
	BOOL	Turok ;
	u16	available ;

	ret = func_800112D8() ;

	switch (ret)
	{
		case PFS_ERR_NEW_PACK:
			func_80011224() ;
			ScanFileList(showall) ;			// potential for infinite loop, but if nintendo did it right, it shouldn't happen
			break ;

		case PFS_ERR_NOPACK:
			break ;
		case PFS_ERR_CONTRFAIL:
			break ;
		case PFS_ERR_INVALID:
			func_8009FA50(D_80119AC8[0].string, D_800B86FC, 8) ;
			D_80119AB0 = 0 ;
			D_80119AB8 = 0 ;
			break ;
	}


	if (ret == 0)
	{
		available = 0 ;
		D_80119AB8 = 0 ;
		D_80119ABC = 0 ;
		D_80119AC0 = 0x1a ;	// 'a' in nintendo font
		for (i=0; i<D_80119AB4; i++)
		{
			Turok = FALSE ;

			ret = func_80011364(i) ;
			if (ret == 0)
			{
				// TUROK file
				if ((D_80119A90.company_code == D_800B86D8) && (D_80119A90.game_code == D_800B86DC))
				{
					available |= 1<< (D_80119A90.ext_name[0] - 0x1a) ;
//					if (FileState.ext_name[0] == LowestAvailableTurokFile)
//						LowestAvailableTurokFile++ ;

					D_80119ABC++ ;
					Turok = TRUE ;
				}
				
				if ((showall) || (Turok))
				{
					D_80119AC8[D_80119AB8].index = i ;
					D_80119AC8[D_80119AB8].pages = D_80119A90.file_size/256 ;
					// copy name
					for (c=0; c<16; c++)
						D_80119AC8[D_80119AB8].string[c] = (D_80119A90.game_name[c] !=0) ? D_80119A90.game_name[c] : 1 ;

					// space & first letter of extension
					D_80119AC8[D_80119AB8].string[16] = 1 ;
					D_80119AC8[D_80119AB8].string[17] = D_80119A90.ext_name[0] ;
					D_80119AC8[D_80119AB8].string[18] = 0 ;

					D_80119AB8++ ;
					if (D_80119AB8>15)
						break ;
				}
			}
			else if (showall)
			{
				D_80119AC8[D_80119AB8].index = i ;
				D_80119AC8[D_80119AB8].pages = 0 ;
				func_8009FA50(&D_80119AC8[D_80119AB8].string, D_800B86F4, 8) ;
				D_80119AB8++ ;
				if (D_80119AB8>15)
					break ;
			}
		}

		// find lowest numbered available file...
		for (i=0; i<D_80119AB4; i++)
		{
			if ((available & (1<<i)) == 0)
			{
				D_80119AC0 = 0x1a + i ;
				break ;
			}
		}

		if (D_80119AB8 == 0)
			func_8009FA50(&D_80119AC8[0].string, D_800B86F4, 8) ;
	}
	return ret ;
}
