typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef struct OSMesgQueue OSMesgQueue;
typedef struct {
	int		status;
	OSMesgQueue 	*queue;
	int		channel;
	u8		id[32];
	u8		label[32];
	int		version;
	int		dir_size;
	int		inode_table;		/* block location */
	int		minode_table;		/* mirrioring inode_table */
	int		dir_table;		/* block location */
	int		inode_start_page;	/* page # */
	u8		banks;
	u8		activebank;
} OSPfs;
typedef struct {
	u32	repaired;
	u32	random;
	u64	serial_mid;
	u64	serial_low;
	u16	deviceid;
	u8	banks;
	u8	version;
	u16	checksum;
	u16	inverted_checksum;
} __OSPackId;

#define BLOCKSIZE 32
#define PFS_ONE_PAGE 8
#define DEF_DIR_PAGES 2
#define PFS_ID_0AREA 1
#define PFS_LABEL_AREA 7
#define PFS_ERR_ID_FATAL 10
#define PFS_ERR_DEVICE 11
s32 __osPfsSelectBank(OSPfs*);
s32 __osContRamRead(OSMesgQueue*,int,u16,u8*);
s32 __osIdCheckSum(u16*,u16*,u16*);
s32 __osCheckPackId(OSPfs*,__OSPackId*);
s32 __osRepairPackId(OSPfs*,__OSPackId*,__OSPackId*);

