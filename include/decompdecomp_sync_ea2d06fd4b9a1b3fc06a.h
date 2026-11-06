typedef signed char s8;typedef unsigned char u8;typedef signed short s16;typedef unsigned short u16;typedef signed int s32;typedef unsigned int u32;typedef signed long long s64;typedef unsigned long long u64;typedef float f32;typedef double f64;
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
typedef void*OSMesg;
typedef struct{u16 type;u8 status,errno;}OSContStatus;
typedef struct{u32 ramarray[15];u32 pifstatus;}OSPifRam;
typedef struct{u8 dummy,txsize,rxsize,cmd,typeh,typel,status,dummy1;}__OSContRequesFormat;
typedef struct{u8 dummy,txsize,rxsize,cmd;u16 address;u8 data[32];u8 datacrc;}__OSContRamReadFormat;
typedef struct{u32 repaired,random;u64 serial_mid,serial_low;u16 deviceid;u8 banks,version;u16 checksum,inverted_checksum;}__OSPackId;
extern OSPifRam D_80137C90;extern u8 D_80137C40,D_80137C41;
void __osSiGetAccess(void);void __osSiRelAccess(void);s32 __osSiRawStartDma(s32,void*);s32 osRecvMesg(OSMesgQueue*,OSMesg*,s32);
void __osPfsRequestData(u8);void __osContGetInitData(u8*,OSContStatus*);void __osPackRamReadData(int,u16);void __osPackRamWriteData(int,u16,u8*);
u8 __osContAddressCrc(u16);u8 __osContDataCrc(u8*);s32 __osPfsGetStatus(OSMesgQueue*,int);
s32 __osIdCheckSum(u16*,u16*,u16*);u16 __osSumcalc(u8*,int);u32 osGetCount(void);s32 __osClearPage(OSPfs*,int,u8*,u8);
#define __osPfsPifRam D_80137C90
#define __osContLastCmd D_80137C40
#define __osMaxControllers D_80137C41
#define __osSiGetAccess __osSiGetAccess
#define __osSiRelAccess __osSiRelAccess
#define __osSiRawStartDma __osSiRawStartDma
#define __osPfsGetInitData __osContGetInitData
#define MAXCONTROLLERS 4
#define OS_WRITE 1
#define OS_READ 0
#define OS_MESG_BLOCK 1
#define CONT_REQUEST 0
#define CONT_RAM_READ 2
#define CONT_RAM_WRITE 3
#define PIFRAMSIZE 16
#define CONT_FORMAT 1
#define FORMAT_END 0xfe
#define CON_ERR_MASK 0xc0
#define CONT_ADDR_CRC_ER 4
#define CONT_CARD_ON 1
#define PFS_ERR_CONTRFAIL 4
#define PFS_FORCE 1
#define PFS_ID_0AREA 1
#define PFS_ID_1AREA 3
#define PFS_ID_2AREA 4
#define PFS_ID_3AREA 6
#define PFS_ERR_ID_FATAL 10
s32 __osPfsGetNextPage(OSPfs*,u8*,__OSInode*,__OSInodeUnit*);
#define PFS_WRITTEN 2

#define NULL ((void*)0)
#define PFS_LABEL_AREA 7
#define PFS_ERR_DEVICE 11

#define PFS_MAX_BANKS 62
#define PFS_ERR_BAD_DATA 6

#define osGetCount osGetCount
#define CHECK_IPAGE(p,pfs) (((p).ipage >= (pfs).inode_start_page) && ((p).inode_t.bank < (pfs).banks) && ((p).inode_t.page >= 0x01) && ((p).inode_t.page < 0x80))

#undef CHECK_IPAGE
#define CHECK_IPAGE(p) (((p).ipage >= pfs->inode_start_page) && ((p).inode_t.bank < pfs->banks) && ((p).inode_t.page >= 0x01) && ((p).inode_t.page < 0x80))
#define PFS_BANK_LAPPED_BY 8
#define PFS_SECTOR_PER_BANK 32
#define PFS_INODE_DIST_MAP 256
#define PFS_SECTOR_SIZE 4
#define PFS_CORRUPTED 2
typedef struct{__OSInode inode;u8 bank;u8 map[256];}__OSInodeCache;
s32 corrupted_init(OSPfs*,__OSInodeCache*);s32 corrupted(OSPfs*,__OSInodeUnit,__OSInodeCache*);s32 __osGetId(OSPfs*);

#define __osGetId func_800A8D94
