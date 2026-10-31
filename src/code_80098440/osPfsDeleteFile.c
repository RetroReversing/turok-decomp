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
#line 17 "PFSDELETEFILE.C"
s32
osPfsDeleteFile(OSPfs *pfs, u16 company_code, u32 game_code,
	     u8 *game_name, u8 *ext_name)
{

	s32 file_no;
	int k;
	s32 ret;
	__OSInode inode ;
	__OSDir dir;
	u16 sum = 0;
	__OSInodeUnit last_page;
	u8 startpage;
	u8 bank;

	if ((company_code == 0) || (game_code == 0))
		return(PFS_ERR_INVALID);

	if (!(pfs->status & PFS_INITIALIZED))
		return(PFS_ERR_INVALID);

	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK){
		return(PFS_ERR_NEW_PACK);
	}

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}
	if ((ret = osPfsFindFile(pfs, company_code, game_code, 
				game_name, ext_name, &file_no))!= 0)
		return(ret);
	if (file_no == -1)	
		return(PFS_ERR_INVALID);

	/* get dir structure */

	if ((ret = __osContRamRead(pfs->queue, pfs->channel,
		(u16)(pfs->dir_table + (int)file_no), (u8 *)&dir)) != 0)
		return(ret);

	/* release pages */

	/* loop through all the banks */

	startpage = dir.start_page.inode_t.page;
	for (bank = dir.start_page.inode_t.bank ; bank < pfs->banks; ) {

		if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0)
			return(ret);

		if ((ret = __osPfsReleasePages(pfs, &inode, startpage,
			 &sum, bank, &last_page, PFS_DELETE )) != 0)
				return(ret);
		if ((ret = __osPfsRWInode(pfs, &inode, PFS_WRITE, bank)) != 0)
			return(ret);
		if (last_page.ipage == PFS_EOF)
			break;

		bank = last_page.inode_t.bank;
		startpage = last_page.inode_t.page;
	}

	if (bank >= pfs->banks)
		return(PFS_ERR_INCONSISTENT);

	/* update dir */

	dir.game_code = 0;
	dir.company_code = 0;
	dir.start_page.ipage = 0;
	dir.data_sum = 0;
	
	for( k = 0 ; k < PFS_FILE_NAME_LEN ; k++)
		dir.game_name[k] = 0;
	for( k = 0 ; k < PFS_FILE_EXT_LEN ; k++)
		dir.ext_name[k] = 0;
	dir.status = 0;

	ret = __osContRamWrite(pfs->queue, pfs->channel,
		(u16)(pfs->dir_table + (int)file_no), (u8 *)&dir, 0);
	return(ret);
}

