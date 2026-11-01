#include "decompdecomp_sync_3320d380231f519b1269.h"
#line 1 "func.c"
#line 41 "reference.c"
s32
func_800A8D94(OSPfs *pfs)
{
	
	int k;
	u16 sum, isum;
	u8 temp[BLOCKSIZE];
	__OSPackId newid;
	s32 ret;
	__OSPackId *id;

	/* switch to bank 0 which has System_id, inode, and dir structure */

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}

	/* check id */
	if ((ret = __osContRamRead(pfs->queue, pfs->channel, 
					PFS_ID_0AREA, temp)) != 0)
		return(ret);
	__osIdCheckSum((u16 *)temp, &sum, &isum);
	id = (__OSPackId *)temp;
	if ((id->checksum != sum) || (id->inverted_checksum != isum)) {

		/* PackId has been trashed */

		if ((ret = __osCheckPackId(pfs, id)) == PFS_ERR_ID_FATAL) {

			/* need to recover ID area */

			ret = __osRepairPackId(pfs, id, &newid);
			if (ret)
				return(ret);
			id = &newid;
		} else if (ret != 0)
			return (ret);
	}

	/* make sure the device is memory pack */

	if ((id->deviceid & 0x01) == 0) {
		ret = __osRepairPackId(pfs, id, &newid);
		if (ret)
			return(ret);
		id = &newid;
		if ((id->deviceid & 0x01) == 0)
			return(PFS_ERR_DEVICE);
	}

	for( k = 0 ; k < BLOCKSIZE; k++)
		pfs->id[k] = *(u8 *)((int)id +k);
	
	pfs->version = (int)id->version;

	/* 
	 * we only allow to have 16 files for this release.
	 * 1 page for System ID, 2 pages for Dir, and 1 page for each bank.
	 */

	pfs->banks = id->banks;
	pfs->inode_start_page = 1 + DEF_DIR_PAGES + (2 * pfs->banks); 
	pfs->dir_size =   DEF_DIR_PAGES * PFS_ONE_PAGE;

	/* inode table state from page 1 to page n, 1 page per bank */

	pfs->inode_table = 1 * PFS_ONE_PAGE;	
	pfs->minode_table = (1 + pfs->banks) * PFS_ONE_PAGE;
	pfs->dir_table = pfs->minode_table + (pfs->banks * PFS_ONE_PAGE);

		
	if ((ret = __osContRamRead(pfs->queue, pfs->channel,
					PFS_LABEL_AREA,(u8 *)pfs->label)) != 0)
		return(ret);
		
	return(0);
}

