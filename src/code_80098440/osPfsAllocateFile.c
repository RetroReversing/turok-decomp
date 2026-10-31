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
#line 21 "PFSALLOCATEFILE.C"
s32
osPfsAllocateFile(OSPfs *pfs, u16 company_code, u32 game_code,
	      u8 *game_name, u8 *ext_name, int file_size_in_bytes,
	      s32 *file_no)
{
	int  start_page, decleared, last_page;
	int   old_last_page = 0;
	int j;
	s32 ret = 0;
	int file_size_in_pages ;
	__OSInode inode, backup_inode;
	__OSDir dir;
	u8 bank;
	u8 old_bank = 0;
	int firsttime = 0;
	s32 bytes;
	__OSInodeUnit fpage;

	if ((company_code == 0) || (game_code == 0))
		return(PFS_ERR_INVALID);


	file_size_in_pages = 
		(file_size_in_bytes + PFS_PAGE_SIZE -1) / PFS_PAGE_SIZE;

	if (!(pfs->status & PFS_INITIALIZED))
		return(PFS_ERR_INVALID);

	if (__osCheckId(pfs) == PFS_ERR_NEW_PACK){
		return(PFS_ERR_NEW_PACK);
	}

	/* Allocate a file */

	if (((ret = osPfsFindFile(pfs, company_code, game_code, 
	   game_name, ext_name, file_no))!= 0) && (ret != PFS_ERR_INVALID))
		return(ret);
	if (*file_no != -1) 
		/* If the file exists, return PFS_ERR_EXIST */
		return(PFS_ERR_EXIST);

	/* 
	 * Preallocate a file and declare file pages. Files 
	 * are not allow to grow on a write. The pages need to
	 * be decleared on open.
	 */

	ret = osPfsFreeBlocks(pfs, &bytes);
	if (file_size_in_bytes > (int)bytes)
		return(PFS_DATA_FULL);

	if (file_size_in_pages != 0) {

		/* get new file id*/

		if (((ret = osPfsFindFile(pfs, 0, 0, 0, 0, file_no)) != 0)
			&& (ret != PFS_ERR_INVALID))
			return(ret);	
		if (*file_no == -1)
			return(PFS_DIR_FULL);

		/* declear pages */ 

		/* loop through all the banks */
	
		for (bank = 0; bank < pfs->banks; bank++) {
		   if ((ret = __osPfsRWInode(pfs, &inode, PFS_READ, bank)) != 0)
			return(ret);

		   ret =__osPfsDeclearPage(pfs, &inode, file_size_in_pages,
			&start_page, bank, &decleared, &last_page);
		   if (ret)
			return(ret);
		   if (start_page != -1) {
		   
			if (firsttime == 0) {
			  fpage.inode_t.page = (u8)start_page;
			  fpage.inode_t.bank = bank;
			} else {
			  backup_inode.inode_page[old_last_page].inode_t.bank = 
									bank;
			  backup_inode.inode_page[old_last_page].inode_t.page = 
								(u8)start_page;
			  if ((ret = __osPfsRWInode(pfs, &backup_inode, 
					PFS_WRITE, old_bank)) != 0)
					return(ret);
			}
			for (j = 0; j < PFS_INODE_SIZE_PER_PAGE; j++)
				backup_inode.inode_page[j].ipage = 
				inode.inode_page[j].ipage;
			old_last_page = last_page;
			old_bank = bank;
			firsttime++;
		   	if (file_size_in_pages > decleared) {

				file_size_in_pages -= decleared;
		   	} else {
				file_size_in_pages = 0;
				break;
			}
		   }
	        }
		if ((file_size_in_pages > 0) || (start_page == -1))
			return(PFS_ERR_INCONSISTENT);

		backup_inode.inode_page[old_last_page].inode_t.bank = 
							bank;
		backup_inode.inode_page[old_last_page].inode_t.page = 
							(u8)start_page;
		if ((ret = __osPfsRWInode(pfs, &backup_inode, 
			PFS_WRITE, old_bank)) != 0)
			return(ret);
		
		/* setup Dir structure */

		dir.start_page = fpage;
		dir.company_code = company_code;
		dir.game_code = game_code;
		dir.data_sum = 0;
		for (j = 0; j < PFS_FILE_NAME_LEN; j++)  {

			dir.game_name[j] = *game_name++;
		}
		for (j = 0; j < PFS_FILE_EXT_LEN; j++)  {

			dir.ext_name[j] = *ext_name++;
		}

		/* write Dir structure back to Pack */

		if ((ret = __osContRamWrite(pfs->queue, pfs->channel, 
		(u16)(pfs->dir_table + (int)*file_no), (u8 *)&dir, 0)) != 0)
				return(ret);

		return(ret);
	}
	else 
		return(PFS_ERR_INVALID);
}

