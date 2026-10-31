#include "decompdecomp_sync_a6e657a27752ad48ce4a.h"
#line 1 "func.c"
#line 72 "reference.c"
s32
osPfsReadWriteFile(OSPfs *pfs, s32 file_no, u8 flag, int offset, 
		   int size_in_bytes, u8 *data_buffer)
{
    s32		  ret;
    __OSDir 	  dir;
    __OSInode 	  inode;
    __OSInodeUnit cur_page;
    int		  cur_block;
    int		  siz_block;
    u8 		  *buffer;
    u8  	  bank;
    u16		  blockno;

    if ((file_no >= (s32)pfs->dir_size) || (file_no < 0))
        return(PFS_ERR_INVALID);
    if ((size_in_bytes <= 0) || ((size_in_bytes % BLOCKSIZE) != 0))
        return(PFS_ERR_INVALID);
    if ((offset < 0) || ((offset % BLOCKSIZE) != 0))
        return(PFS_ERR_INVALID);
    if (!(pfs->status & PFS_INITIALIZED))
        return(PFS_ERR_INVALID);
  
    if (__osCheckId(pfs) == PFS_ERR_NEW_PACK) {
        return(PFS_ERR_NEW_PACK);
    }
  
    /* Get dir and inode structures */
  
    if (pfs->activebank != 0) {
        pfs->activebank = 0;
        if ((ret = __osPfsSelectBank(pfs)) != 0)
            return(ret);
    }
    if ((ret = __osContRamRead(pfs->queue, pfs->channel,
			     (u16)(pfs->dir_table + (int)file_no),
			     (u8 *)&dir)) != 0)
        return(ret);	
	
    if (!CHECK_IPAGE(dir.start_page, *pfs)) {
        if (dir.start_page.ipage == PFS_EOF) {
            return(PFS_ERR_INVALID);
        }
        return(PFS_ERR_INCONSISTENT);
    }
  
    if ((flag == PFS_READ) && ((dir.status & PFS_WRITTEN) == 0))
        return(PFS_ERR_BAD_DATA);
  
    /* inode buffer is empty, so set "bank" to dummy value */
    bank = 255;
  
    /* get offset */
    cur_block = offset / BLOCKSIZE;
    cur_page  = dir.start_page;
  
    /* seek to the specified offset */
    while (cur_block >= 8) {
        if ((ret = __osPfsGetNextPage(pfs,&bank,&inode,&cur_page)) != 0) {
            return (ret);
        }
        cur_block -= 8;
    }
  
    /* read/write data from/to memory pack */
  
    siz_block = size_in_bytes / BLOCKSIZE;
    buffer = data_buffer;
  
    while (siz_block > 0) {
    
        /* check if end of block in current page */
        if (cur_block == 8) {
            if ((ret = __osPfsGetNextPage(pfs,&bank,&inode,&cur_page)) != 0) {
	        return (ret);
            }
            cur_block = 0;
        }  /* if */
    
        /* check active bank */
        if (pfs->activebank != cur_page.inode_t.bank) {
            pfs->activebank = cur_page.inode_t.bank;
            if ((ret = __osPfsSelectBank(pfs)) != 0) {
	        return(ret);
            }
        }  /* if */

        blockno = (u16)((u16)cur_page.inode_t.page * PFS_ONE_PAGE + cur_block);
        if (flag == PFS_READ) {
            ret = __osContRamRead(pfs->queue, pfs->channel, blockno, buffer);
        } else {	
            ret = __osContRamWrite(pfs->queue, pfs->channel,blockno,buffer,0);
        }
        if (ret != 0) return(ret);
    
        buffer += BLOCKSIZE;
        cur_block ++;
        siz_block --;
    }  /* while */

    if (flag == PFS_WRITE && !(dir.status & PFS_WRITTEN)) {
        dir.status |= PFS_WRITTEN;
        pfs->activebank = 0;
        if ((ret = __osPfsSelectBank(pfs)) != 0) return(ret);
        if ((ret = __osContRamWrite(pfs->queue, pfs->channel,
				(u16)(pfs->dir_table + (int)file_no),
				(u8 *)&dir, 0)) != 0)
            return(ret);
    }  /* if */

    return(0);
}

