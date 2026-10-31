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
#line 17 "PFSSEARCHFILE.C"
s32
osPfsFindFile(OSPfs *pfs, u16 company_code, u32 game_code, 
		u8 *game_name, u8 *ext_name, s32 *file_no)
{
	s32 j;
	int i;
	__OSDir dir;
	s32 ret = 0;
	int fail;
	
	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK){
		return(PFS_ERR_NEW_PACK);
	}

	for (j = 0; j < (s32)pfs->dir_size; j++) {
		if ((ret = __osContRamRead(pfs->queue, pfs->channel,
			(u16)(pfs->dir_table + (int)j), (u8 *)&dir)) != 0)
			return(ret);
		if ((dir.company_code == company_code) && 
					(dir.game_code == game_code)) {
			fail = 0;
			if (game_name != 0) {
				for(i = 0 ; i < PFS_FILE_NAME_LEN ; i++)
					if (dir.game_name[i] != game_name[i]) {
						fail = 1;
						break;
					}
			}
			if ((ext_name != 0) && (fail == 0)){
				for(i = 0 ; i < PFS_FILE_EXT_LEN ; i++)
					if (dir.ext_name[i] != ext_name[i]){
						fail = 1;
						break;
					}
			}
			if (fail == 0) {
				*file_no = j;
				return(ret);
			}
		}
	}
	*file_no = -1;
	return(PFS_ERR_INVALID);	/* file not found */
}

