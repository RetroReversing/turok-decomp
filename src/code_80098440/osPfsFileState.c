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
#line 17 "PFSFILESTATE.C"
s32
osPfsFileState(OSPfs *pfs, s32 file_no, OSPfsState *state)
{
	s32 ret;
	int pages;
	__OSInode inode;
	__OSDir dir;
	__OSInodeUnit next_page;
	int j;
	u8 bank;
	u8 start_page;

	/* 
	 * typedef struct {
	 *	u32     file_size;
	 *	u32     game_code;
	 *	u16     company_code;
	 *	char    ext_name[4];
	 *	char    game_name[16];
	 * } OSPfsState;
	 */
	

	/* Check valid ID and parameters */

	if ((file_no >= (s32)pfs->dir_size) || (file_no < 0))
		return(PFS_ERR_INVALID);
	if (!(pfs->status & PFS_INITIALIZED))
		return(PFS_ERR_INVALID);

	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK){
		return(PFS_ERR_NEW_PACK);
	}

	/* get dir and inode structures */

	if (pfs->activebank != 0) {
		pfs->activebank = 0;
		if ((ret = __osPfsSelectBank(pfs)) != 0)
			return(ret);
	}

	if ((ret = __osContRamRead(pfs->queue, pfs->channel,
                (u16)(pfs->dir_table + (int)file_no), (u8 *)&dir)) != 0)
                return(ret);
	if ((dir.company_code == 0) || (dir.game_code == 0))
		return(PFS_ERR_INVALID);
	if (dir.start_page.ipage < pfs->inode_start_page)
		return(PFS_ERR_INCONSISTENT);

	
	/* get file status and calculate file size */

	pages = 0;
	start_page = dir.start_page.inode_t.page;
	for (bank = dir.start_page.inode_t.bank; bank < pfs->banks; ) {
		if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0)
			return(ret);
	
		next_page = inode.inode_page[start_page];
		pages++;

		while (next_page.ipage >= pfs->inode_start_page) {
			pages++;
			next_page = inode.inode_page[next_page.inode_t.page];
			if (next_page.inode_t.bank != bank){
				bank = next_page.inode_t.bank;
				start_page = next_page.inode_t.page;
				break;
			}
		}
		if (next_page.ipage == PFS_EOF){
			break;
		}
	}
	if (next_page.ipage != PFS_EOF)
		return(PFS_ERR_INCONSISTENT);
	state->file_size = (u32)(pages * PFS_PAGE_SIZE);
	state->company_code = dir.company_code;
	state->game_code = dir.game_code;
	for (j = 0; j < PFS_FILE_NAME_LEN; j++) 
		state->game_name[j] = dir.game_name[j];
	for (j = 0; j < PFS_FILE_EXT_LEN; j++) 
		state->ext_name[j] = dir.ext_name[j];
	return(0);
}

