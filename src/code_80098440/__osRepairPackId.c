#include "decompdecomp_sync_a6e657a27752ad48ce4a.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
__osRepairPackId(OSPfs *pfs, __OSPackId *badid, __OSPackId *newid)
{
	s32 ret = 0;
	u8 temp[BLOCKSIZE];
	u8 comp[BLOCKSIZE];
	u8 mask = 0;
	int i, j;
	u16 index[4];

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}

	newid->repaired = 0xffffffff;
	newid->random = osGetCount();
	newid->serial_mid = badid->serial_mid;
	newid->serial_low = badid->serial_low;

	j = 0;
	do {
	  /* Select bank -- by YASU */
	  pfs->activebank = (u8)j;
	  if ((ret = __osPfsSelectBank(pfs)) != 0)
		 return(ret);
	  
	  /* Check if memory */
	  if ((ret = __osContRamRead(pfs->queue,
				     pfs->channel, 0, temp)) != 0)
	    return(ret);
	  temp[0] = (u8)(j|0x80);
	  for (i = 1; i < BLOCKSIZE; i++)
	    temp[i] = (u8)~temp[i];

	  if ((ret = __osContRamWrite(pfs->queue,
				      pfs->channel, 0, temp, 0)) != 0)
	    return(ret);
	  if ((ret = __osContRamRead(pfs->queue,
				     pfs->channel, 0, comp)) != 0)
	    return(ret);
	  for (i = 0; i < BLOCKSIZE; i++)
	    if (comp[i] != temp[i]) break;
	  if (i != BLOCKSIZE) break;
	  
	  
	  /* Check if lapped */
	  if (j > 0){
	    pfs->activebank = 0;
	    if ((ret = __osPfsSelectBank(pfs)) != 0) 
		return(ret);
	    if ((ret = __osContRamRead(pfs->queue,
				       pfs->channel, 0, temp)) != 0)
	      return(ret);
	    if (temp[0] != (u8)0x80) break;
	  }
	  
	  j ++;
	} while (j < PFS_MAX_BANKS);
	
	pfs->activebank = 0;
	if ((ret = __osPfsSelectBank(pfs)) != 0) return(ret);
	
	mask = (u8)((j > 0) ? 1 : 0);
	newid->deviceid = (u16)((badid->deviceid & 0xfffe) | mask);
	newid->banks    = (u8)j;
	newid->version  = badid->version;
	__osIdCheckSum((u16 *)newid, &(newid->checksum),
				&(newid->inverted_checksum));	

	/* write the recovered id to all id areas */

	index[0] = PFS_ID_0AREA;
	index[1] = PFS_ID_1AREA;
	index[2] = PFS_ID_2AREA;
	index[3] = PFS_ID_3AREA;
	for (i=0; i < 4; i++) {
		if ((ret = __osContRamWrite(pfs->queue, pfs->channel, 
					index[i], (u8 *)newid, PFS_FORCE)) != 0)
				return(ret);
	}
	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 
					PFS_ID_0AREA, temp)) != 0)
		return(ret);
	for( i = 0 ; i < BLOCKSIZE; i++)
		if (temp[i] != *(u8 *)((int)newid + i))
			return(PFS_ERR_ID_FATAL);	/* dead ram pack */
	return(0);
}

