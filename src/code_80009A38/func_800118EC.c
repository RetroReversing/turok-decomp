#include "decompdecomp_sync_961dfec7b89edf84e995.h"
#line 1 "func.c"
#line 635 "reference.c"
int func_800118EC(int index)
{
	int	ret ;
	s32	size ;
	u8		*data ;

	StartSerialQ() ;

	size = CScene__GetPersistantDataSize(&D_800FA3C8) ;
	data = (u8 *)CScene__GetPersistantDataAddress(&D_800FA3C8) ;

	size /= 256 ;
	size++ ;
	size *= 256 ;

	ret = osPfsFileState(&ControllerPak, FileDirectory[index].index, &FileState) ;
	if (ret == 0)
	{
		// check if turok game
		if ((FileState.company_code == CompanyCode) && (FileState.game_code == GameCode) && (FileState.file_size == size))
		{
			//osWritebackDCache(data, size);
			LowestAvailableTurokFile = FileState.ext_name[0];
			DeleteCurrent(index);
			ret = SaveNew();								// area to write from
			//rmonPrintf("actual save ret:%d\n", ret);
			//rmonPrintf("writing %d bytes to %5s%4s\n", FileState.file_size, FileState.game_name, FileState.ext_name);
		}
		else
		{
			//rmonPrintf("filesize:%d  datasize:%d\n", FileState.file_size, size);

			ret = -1 ;
		}
	}
//	else
//		rmonPrintf("save current ret:%d\n", ret) ;

	EndSerialQ() ;
	return ret ;
}

