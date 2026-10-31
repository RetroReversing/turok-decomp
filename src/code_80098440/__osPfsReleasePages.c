#include "decompdecomp_sync_8d698fdff8b312cb3f4a.h"
#line 1 "func.c"
typedef void OSMesgQueue;
typedef struct {int status;OSMesgQueue*queue;int channel;u8 id[32];u8 label[32];int version,dir_size,inode_table,minode_table,dir_table,inode_start_page;u8 banks,activebank;}OSPfs;
typedef union{struct{u8 bank,page;}inode_t;u16 ipage;}__OSInodeUnit;
typedef struct{u32 game_code;u16 company_code;__OSInodeUnit start_page;u8 status;s8 reserved;u16 data_sum;char ext_name[4];char game_name[16];}__OSDir;
typedef struct{__OSInodeUnit inode_page[128];}__OSInode;
s32 __osCheckId(OSPfs*);s32 __osPfsSelectBank(OSPfs*);s32 __osContRamRead(OSMesgQueue*,int,u16,u8*);s32 __osPfsRWInode(OSPfs*,__OSInode*,u8,u8);
#define PFS_INITIALIZED 1
#define PFS_ERR_INVALID 5
#define PFS_ERR_NEW_PACK 2
#define PFS_READ 0
#define PFS_INODE_SIZE_PER_PAGE 128
#define PFS_PAGE_NOT_USED 3
#define PFS_ONE_PAGE 8
#define BLOCKSIZE 32
typedef struct{u32 file_size,game_code;u16 company_code;char ext_name[4],game_name[16];}OSPfsState;
#define PFS_EOF 1
#define PFS_ERR_INCONSISTENT 3
#define PFS_PAGE_SIZE 256
#define PFS_FILE_NAME_LEN 16
#define PFS_FILE_EXT_LEN 4
s32 osPfsFindFile(OSPfs*,u16,u32,u8*,u8*,s32*);s32 osPfsFreeBlocks(OSPfs*,s32*);
s32 __osContRamWrite(OSMesgQueue*,int,u16,u8*,int);
s32 __osPfsReleasePages(OSPfs*,__OSInode*,u8,u16*,u8,__OSInodeUnit*,int);
s32 __osPfsDeclearPage(OSPfs*,__OSInode*,int,int*,u8,int*,int*);
s32 __osBlockSum(OSPfs*,u8,u16*,u8);
#define PFS_WRITE 1
#define PFS_DELETE 1
#define PFS_ERR_EXIST 9
#define PFS_DATA_FULL 7
#define PFS_DIR_FULL 8
#line 102 "PFSDELETEFILE.C"
s32
__osPfsReleasePages(OSPfs *pfs, __OSInode *inode, 
  u8 start_page, u16 *sum, u8 bank, __OSInodeUnit *last_page, int flag)
{
	__OSInodeUnit next_page, old_page;
	s32 ret = 0;
	int offset;

	next_page = inode->inode_page[start_page];
	if (next_page.ipage != PFS_EOF)
		offset = ((next_page.inode_t.bank > 0) ? 1 : pfs->inode_start_page);
	else
		offset = ((bank> 0) ? 1 : pfs->inode_start_page);
	if ((next_page.inode_t.page  < offset) && (next_page.ipage != PFS_EOF))
		return(PFS_ERR_INCONSISTENT);

	*last_page = next_page;
	if (flag == PFS_DELETE)
		inode->inode_page[start_page].ipage = PFS_PAGE_NOT_USED;
	ret = __osBlockSum(pfs, start_page, sum, bank);
	if (ret)
		return(ret);
	if (next_page.ipage == PFS_EOF){
		return(0);
	}
	while (next_page.ipage >= pfs->inode_start_page ) {
		old_page = next_page;
		next_page = inode->inode_page[next_page.inode_t.page];
		inode->inode_page[old_page.inode_t.page].ipage = PFS_PAGE_NOT_USED;
		ret = __osBlockSum(pfs, old_page.inode_t.page, sum, bank);
		if (ret)
			return(ret);
		if (next_page.inode_t.bank != bank)
			break;
	}
	if (next_page.ipage >= pfs->inode_start_page)
	    inode->inode_page[next_page.inode_t.page].ipage = PFS_PAGE_NOT_USED;
	*last_page = next_page;

	return(0);
}

