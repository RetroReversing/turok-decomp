#include "decompdecomp_sync_298e88a300f0afd6412f.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
__osPfsRWInode(OSPfs *pfs, __OSInode *inode, u8 flag, u8 bank)
{
	u8 sum;
	int j;
	s32 ret;
	int offset;
	u8 *addr;

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}

	/* get checksum */

	offset = ((bank > 0) ? 1 : pfs->inode_start_page);
		
	if (flag == PFS_WRITE) {
		inode->inode_page[0].inode_t.page = 		
			(u8)__osSumcalc((u8 *)(inode->inode_page + offset), 
			(PFS_INODE_SIZE_PER_PAGE - offset) * 2);
		}
	
	for (j=0; j < PFS_ONE_PAGE; j++) {
		addr = (u8 *)(((u8 *)inode) + (j * BLOCKSIZE));
		if (flag == PFS_WRITE) {
			ret = __osContRamWrite(pfs->queue, pfs->channel, 
			   (u16)(pfs->inode_table + (bank * PFS_ONE_PAGE) + j),
			     addr, 0);
			ret = __osContRamWrite(pfs->queue, pfs->channel, 
			   (u16)(pfs->minode_table + (bank * PFS_ONE_PAGE) + j),
			     addr, 0);
		} else {
			ret = __osContRamRead(pfs->queue, pfs->channel, 
			   (u16)(pfs->inode_table + (bank * PFS_ONE_PAGE) + j),
			     addr);
		}
		if (ret)
			return(ret);
	}

	/* check checksum */

	if (flag == PFS_READ) {
		sum = (u8)__osSumcalc((u8 *)(inode->inode_page + offset),
			(PFS_INODE_SIZE_PER_PAGE - offset) * 2);
		if (sum != inode->inode_page[0].inode_t.page) {
			for (j=0; j < PFS_ONE_PAGE; j++) {
				addr = (u8 *)(((u8 *)inode) + (j * BLOCKSIZE));
				ret = __osContRamRead(pfs->queue, pfs->channel,
				(u16)(pfs->minode_table+(bank*PFS_ONE_PAGE)+j),
			 	addr);
			}
			if (sum != inode->inode_page[0].inode_t.page) 
				return(PFS_ERR_INCONSISTENT);
			for (j=0; j < PFS_ONE_PAGE; j++) {
				addr = (u8 *)(((u8 *)inode) + (j * BLOCKSIZE));
				ret = __osContRamWrite(pfs->queue, pfs->channel,
				(u16)(pfs->inode_table+(bank*PFS_ONE_PAGE)+j),
			 	addr, 0);
			}
		} else {
			for (j=0; j < PFS_ONE_PAGE; j++) {
				addr = (u8 *)(((u8 *)inode) + (j * BLOCKSIZE));
				ret = __osContRamWrite(pfs->queue, pfs->channel,
				(u16)(pfs->minode_table+(bank*PFS_ONE_PAGE)+j),
			 	addr, 0);
			}

		}
	} 
	return(0);
}

