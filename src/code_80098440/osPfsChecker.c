#include "decompdecomp_sync_ea2d06fd4b9a1b3fc06a.h"
#line 1 "func.c"
#line 1 "reference.c"
s32
osPfsChecker(OSPfs *pfs)
{
  int j;
  s32 ret;
  __OSInodeUnit next_page;
  __OSInode checked_inode;
  __OSInode tmp_inode;
  __OSDir tmp_dir;
  __OSInodeUnit file_next_node[16];
  
  __OSInodeCache	cache;
  
  int fixed = 0;
  u8 bank;
  s32 cc, cl;
  int offset;

  /* check  status */


  ret = __osCheckId(pfs);
  
  if (ret == PFS_ERR_NEW_PACK)
    ret = __osGetId(pfs);
  
  if (ret)
    return(ret);

  
  /*
   * loop through all files to make sure that there are no
   * file's start pages have been marked NOT_USED.
   */
  
  if ((ret = corrupted_init(pfs, &cache)) != 0) return(ret);
  
  for (j = 0; j < pfs->dir_size; j++) {
    if ((ret = __osContRamRead(pfs->queue, pfs->channel,
			       (u16)(pfs->dir_table + j),
			       (u8 *)&tmp_dir)) != 0){
      return(ret);
    }
    
    if ((tmp_dir.company_code != 0) && (tmp_dir.game_code != 0)) {
      
      /* file exist */
      next_page = tmp_dir.start_page;
      
      /* dir is valid */
      cl = cc = 0;
      bank = -1; 
	
      while(CHECK_IPAGE(next_page)){
	
	if (bank != next_page.inode_t.bank){
	  bank = next_page.inode_t.bank;
	  ret = __osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);
	  if ((ret != 0) && (ret != PFS_ERR_INCONSISTENT)){
	    return(ret);
	  }
	} 	 
	
	if ((cc = corrupted(pfs, next_page, &cache) - cl) != 0){
	  break;
	}
	cl = 1;
	
	next_page = tmp_inode.inode_page[next_page.inode_t.page];	  
      }

      if ((cc != 0) || (next_page.ipage != PFS_EOF)){
	
	/* corrupted */
	tmp_dir.company_code = 0;
	tmp_dir.game_code = 0;
	tmp_dir.start_page.ipage = 0;
	tmp_dir.status = 0;
	tmp_dir.data_sum = 0;
	
	if (pfs->activebank != 0) {
	  pfs->activebank = 0;
	  if ((ret = __osPfsSelectBank(pfs)) != 0)
	    return(ret);
	}
	if ((ret = __osContRamWrite(pfs->queue, pfs->channel,
				    (u16)(pfs->dir_table + j),
				    (u8 *)&tmp_dir, 0)) != 0){
	  return(ret);
	}
	
	/* free inode pages */
	fixed++;
      }
    } else if ((tmp_dir.company_code != 0) || (tmp_dir.game_code != 0)) {

	/* corrupted */
	tmp_dir.company_code = 0;
	tmp_dir.game_code = 0;
	tmp_dir.start_page.ipage = 0;
	tmp_dir.status = 0;
	tmp_dir.data_sum = 0;
	
	if (pfs->activebank != 0) {
	  pfs->activebank = 0;
	  if ((ret = __osPfsSelectBank(pfs)) != 0)
	    return(ret);
	}
	if ((ret = __osContRamWrite(pfs->queue, pfs->channel,
				    (u16)(pfs->dir_table + j),
				    (u8 *)&tmp_dir, 0)) != 0){
	  return(ret);
	}
	
	/* free inode pages */
	fixed++;
    } 
  }

	/* 
	 * return all pages that are not in any file back to NOT_USED.
	 */
        /* BY YASU */
        
        /* Get inode start page */
        for (j = 0; j < pfs->dir_size; j++) {   
          if ((ret = __osContRamRead(pfs->queue, pfs->channel,
                                     (u16)(pfs->dir_table +j),
                                     (u8 *)&tmp_dir)) != 0)
            return(ret);

          /* Check if file exists */
          if ((tmp_dir.company_code != 0) && (tmp_dir.game_code != 0) &&
              (tmp_dir.start_page.ipage >= (u16)pfs->inode_start_page)) {
            file_next_node[j].ipage = tmp_dir.start_page.ipage;
          } else {
            file_next_node[j].ipage = 0;
          }
        }
        
        /* Check all */
	for(bank = 0; bank < pfs->banks; bank++) {
	  
	  /* load inode */
	  ret =__osPfsRWInode(pfs, &tmp_inode, PFS_READ, bank);
	  if ((ret != 0) && (ret != PFS_ERR_INCONSISTENT))
	    return(ret);
	  
	  /* setup default inode structure */
	  offset = ((bank > 0) ? 1 : pfs->inode_start_page);
	  for (j = 0; j < offset; j ++){
	    checked_inode.inode_page[j].ipage =
	      tmp_inode.inode_page[j].ipage;
	  }
	  for (; j < PFS_INODE_SIZE_PER_PAGE; j++) 
	    checked_inode.inode_page[j].ipage = PFS_PAGE_NOT_USED;
            
	  /* read file info */
	  for (j = 0; j < pfs->dir_size; j++) {
	    while(file_next_node[j].inode_t.bank == bank &&
		  file_next_node[j].ipage >= (u16)pfs->inode_start_page){
	      u8 pp;
	      pp = file_next_node[j].inode_t.page;
	      file_next_node[j] =
		checked_inode.inode_page[pp] = tmp_inode.inode_page[pp];
	    } 
	  }
	  if ((ret = __osPfsRWInode(pfs, &checked_inode, PFS_WRITE, bank))
	      != 0)
	    return(ret);
	}

	if (fixed != 0)
		pfs->status |= PFS_CORRUPTED;
	else
		pfs->status &= ~PFS_CORRUPTED;
	return(0);
}

