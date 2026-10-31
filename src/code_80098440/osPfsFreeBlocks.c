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
#line 17 "PFSFREEBLOCKS.C"
s32
osPfsFreeBlocks(OSPfs *pfs, s32 *bytes_not_used)
{
	int j;
	int pages = 0;
	__OSInode inode;
	s32 ret = 0;
	u8 bank;
	int offset;

	if (!(pfs->status & PFS_INITIALIZED))
		return(PFS_ERR_INVALID);

	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK){
		return(PFS_ERR_NEW_PACK);
	}

	for (bank = 0; bank < pfs->banks; bank++) {
		if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0)
			return(ret);

		offset = ((bank > 0) ? 1 : pfs->inode_start_page);
		for (j = offset ; j <PFS_INODE_SIZE_PER_PAGE; j++) {
			if (inode.inode_page[j].ipage == PFS_PAGE_NOT_USED)
				pages++;
		}
	}

	*bytes_not_used = (s32)(pages * PFS_ONE_PAGE * BLOCKSIZE);
	return(0);
}

