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
#line 17 "PFSNUMFILES.C"
s32
osPfsNumFiles(OSPfs *pfs, s32 *max_files, s32 *files_used)
{
	int j;
	s32 ret;
	__OSDir dir;
	int files = 0;

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
	for (j = 0; j < pfs->dir_size; j++) {
		if ((ret = __osContRamRead(pfs->queue, pfs->channel,
                        (u16)(pfs->dir_table + j), (u8 *)&dir)) != 0)
                        return(ret);
		if ((dir.company_code != 0) && (dir.game_code != 0))
			files++;
	}

	*files_used = (s32)files;
	*max_files = (s32)pfs->dir_size;
	return(0);
}

