#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef struct{u8 pad[0x60];s32 inode_start_page;u8 banks;}OSPfs;
typedef union{u16 ipage;struct{u8 bank,page;}inode_t;}__OSInodeUnit;
typedef struct{__OSInodeUnit inode_page[128];}__OSInode;
s32 __osPfsRWInode(OSPfs*,__OSInode*,s32,u8);
#define PFS_READ 0
#define PFS_EOF 1
#define PFS_ERR_INVALID 5
#define PFS_ERR_INCONSISTENT 3
#define CHECK_IPAGE(p,pfs) (((p).ipage >= (pfs).inode_start_page) && ((p).inode_t.bank < (pfs).banks) && ((p).inode_t.page >= 0x01) && ((p).inode_t.page < 0x80))
#line 21 "PFSREADWRITEFILE.C"
      	s32
__osPfsGetNextPage(OSPfs *pfs, u8 *bank, __OSInode *inode, __OSInodeUnit *page)
{
    s32  ret;

    /*  If given inode data is invalid -> load new inode */
    if (page->inode_t.bank != *bank) {
	*bank = page->inode_t.bank;
	if ((ret = __osPfsRWInode(pfs, inode, PFS_READ, *bank)) != 0) {
	    return(ret);
	}
    }
    *page = inode->inode_page[page->inode_t.page];
  
    if (!CHECK_IPAGE(*page, *pfs)) {
        if (page->ipage == PFS_EOF) {
            return(PFS_ERR_INVALID);
        }
        return(PFS_ERR_INCONSISTENT);
    }
    return 0;
}

