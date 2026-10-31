#include "decompdecomp_sync_f42677841a62f7392683.h"
#line 1 "func.c"
#line 70 "reference.c"
s32
__osPfsDeclearPage(OSPfs *pfs, __OSInode *inode, int file_size_in_pages, 
 		   int *first_page, u8 bank, int *decleared, int *last_page)
{
	int j;
	int spage, old_page;
	u8 tmp_data[BLOCKSIZE];
	int i;
	s32 ret = 0;
	int offset;

	
	offset = ((bank > 0) ? 1 : pfs->inode_start_page);
	for (j = offset ; j <PFS_INODE_SIZE_PER_PAGE; j++) {
		if (inode->inode_page[j].ipage == PFS_PAGE_NOT_USED)
			break;
	}
	if (j == PFS_INODE_SIZE_PER_PAGE) {
		*first_page = -1;
		return(ret); 	/* no free page */
	}

	for (i = 0; i < BLOCKSIZE; i++)
		tmp_data[i] = 0;
	
	spage = j;
	*decleared = 1;
	old_page = j;
	j++;
	while((file_size_in_pages > *decleared)&& (j<PFS_INODE_SIZE_PER_PAGE)) {
		if (inode->inode_page[j].ipage == PFS_PAGE_NOT_USED) {
			inode->inode_page[old_page].inode_t.bank = (u8)bank;
			inode->inode_page[old_page].inode_t.page = (u8)j;
			ret = __osClearPage(pfs, old_page, tmp_data, bank);
			if (ret)
				return(ret);
			old_page = j;
			(*decleared)++;
		}
		j++;
	}
	*first_page = spage;
	if ((j == (PFS_INODE_SIZE_PER_PAGE )) && 
		(file_size_in_pages > *decleared)) {
		*last_page = old_page;
		return(ret);		/* no enough free pages in this bank*/
	} else {
		/* mark the end page */
		inode->inode_page[old_page].ipage = PFS_EOF;	
		ret = __osClearPage(pfs, old_page, tmp_data, bank);
		*last_page = 0;
		return(ret);
	}
}

