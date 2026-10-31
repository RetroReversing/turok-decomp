#include "decompdecomp_sync_298e88a300f0afd6412f.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
__osCheckPackId(OSPfs *pfs, __OSPackId *temp)
{

	u16 index[4];
	s32 ret = 0;
	u16 sum, isum;
	int i,j;

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}

	index[0] = PFS_ID_0AREA;
	index[1] = PFS_ID_1AREA;
	index[2] = PFS_ID_2AREA;
	index[3] = PFS_ID_3AREA;

	for (i = 1; i < 4; i++) {

		/* check id */
		if ((ret = __osContRamRead(pfs->queue, pfs->channel, 
					index[i], (u8 *)temp)) != 0)
			return(ret);
		__osIdCheckSum((u16 *)temp, &sum, &isum);
		if ((temp->checksum == sum) && 
			(temp->inverted_checksum == isum))
			break;
	}
	if (i == 4)
		return(PFS_ERR_ID_FATAL);	/* can not find any good id */

	/* copy good id to all of the id areas */

	for (j=0; j < 4; j++) {
		if (j != i) {
			if ((ret = __osContRamWrite(pfs->queue, pfs->channel, 
					index[j], (u8 *)temp, PFS_FORCE)) != 0)
				return(ret);
		}
	}
	return(0);
}

