#include "decompdecomp_sync_ac01e13bb0cb906c7f3d.h"
#line 1 "func.c"
#line 1 "reference.c"
s32     corrupted_init(OSPfs *pfs, __OSInodeCache *cache)
{
  int           i, n;
  int           offset;
  u8            bank;
  __OSInodeUnit	tpage;
  __OSInode     tmp_inode;
  s32           ret;
  
  for (i = 0; i < PFS_INODE_DIST_MAP; i ++){
    cache->map[i] = 0;
  }
  cache->bank = 255;
  
  for (bank = 0; bank < pfs->banks; bank ++){
    offset = ((bank > 0) ? 1 : pfs->inode_start_page);
    
    ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);
    if ((ret != 0) && (ret != PFS_ERR_INCONSISTENT)) return(ret);
    
    for (i = offset; i < PFS_INODE_SIZE_PER_PAGE; i ++){
      tpage = tmp_inode.inode_page[i];
      if (tpage.ipage >= pfs->inode_start_page){
	if (tpage.inode_t.bank != bank){
	  n = (int)(tpage.inode_t.page / PFS_SECTOR_SIZE)
	    + PFS_SECTOR_PER_BANK
	      * (int)(tpage.inode_t.bank % PFS_BANK_LAPPED_BY);
	  cache->map[n] |= (1 << (bank % PFS_BANK_LAPPED_BY));
	}
      }
    }
  }
  return(0);
}

