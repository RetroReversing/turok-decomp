#include "decompdecomp_sync_ac01e13bb0cb906c7f3d.h"
#line 1 "func.c"
#line 1 "reference.c"
s32
corrupted(OSPfs *pfs, __OSInodeUnit fpage, __OSInodeCache *cache)
{
	int j, n;
	int hit = 0;
	u8  bank;
	int offset;
	s32 ret = 0;
	
	n = (int)(fpage.inode_t.page / PFS_SECTOR_SIZE)
	  + PFS_SECTOR_PER_BANK 
	    * (int)(fpage.inode_t.bank % PFS_BANK_LAPPED_BY);
	
	for (bank = 0; bank < pfs->banks; bank++) {
	    offset = ((bank > 0) ? 1 : pfs->inode_start_page);
	    if ((bank == fpage.inode_t.bank) ||
		(cache->map[n] & (1 << (bank % PFS_BANK_LAPPED_BY))) != 0){
	      if (bank != cache->bank){
		ret = __osPfsRWInode(pfs, &(cache->inode), PFS_READ, bank);
		if ((ret != 0) && (ret != PFS_ERR_INCONSISTENT))
		        return(ret);
		cache->bank = bank;
	      }
	      for (j = offset; ((hit < 2) && (j < PFS_INODE_SIZE_PER_PAGE)); 
		   j++) {
		if (cache->inode.inode_page[j].ipage == fpage.ipage) {
		  hit++;
		}
	      }
	      if (hit >= 2)
		return(2);
	    }
	}
	return hit;
}

