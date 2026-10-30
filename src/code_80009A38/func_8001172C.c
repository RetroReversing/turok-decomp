#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef unsigned long sa_u32;
typedef unsigned long long sa_u64;
typedef signed char sa_s8;
typedef long sa_s32;
typedef float sa_f32;
typedef double sa_f64;
typedef sa_s32 OSPri;
typedef sa_s32 OSId;
typedef union {
    struct {
        sa_f32 f_odd;
        sa_f32 f_even;
    } f;
    sa_f64 d;
} __OSfp;
typedef struct {
    sa_u64 at, v0, v1, a0, a1, a2, a3;
    sa_u64 t0, t1, t2, t3, t4, t5, t6, t7;
    sa_u64 s0, s1, s2, s3, s4, s5, s6, s7;
    sa_u64 t8, t9;
    sa_u64 gp, sp, sa_s8, ra;
    sa_u64 lo, hi;
    sa_u32 sr, pc, cause, badvaddr, rcp;
    sa_u32 fpcsr;
    __OSfp fp0, fp2, fp4, fp6, fp8, fp10, fp12, fp14;
    __OSfp fp16, fp18, fp20, fp22, fp24, fp26, fp28, fp30;
} __OSThreadContext;
typedef struct {
    sa_u32 flag;
    sa_u32 count;
    sa_u64 time;
} __OSThreadprofile_s;
typedef struct OSThread_s {
    struct OSThread_s *next;
    OSPri priority;
    struct OSThread_s **queue;
    struct OSThread_s *tlnext;
    sa_u16 state;
    sa_u16 flags;
    OSId id;
    int fp;
    __OSThreadprofile_s *thprof;
    __OSThreadContext context;
} OSThread;
typedef void *OSMesg;
typedef struct OSMesgQueue_s {
    OSThread *mtqueue;
    OSThread *fullqueue;
    sa_s32 validCount;
    sa_s32 first;
    sa_s32 msgCount;
    OSMesg *msg;
} OSMesgQueue;
typedef struct {
 int status;
 OSMesgQueue *queue;
 int channel;
 sa_u8 id[32];
 sa_u8 label[32];
 int version;
 int dir_size;
 int inode_table;
 int minode_table;
 int dir_table;
 int inode_start_page;
 sa_u8 banks;
 sa_u8 activebank;
} OSPfs;
typedef struct {
 sa_u32 file_size;
   sa_u32 game_code;
   sa_u16 company_code;
   char ext_name[4];
   char game_name[16];
} OSPfsState;
extern sa_s32 osPfsDeleteFile(OSPfs *, sa_u16, sa_u32, sa_u8 *, sa_u8 *);
extern sa_s32 osPfsFileState(OSPfs *, sa_s32, OSPfsState *);
extern OSPfs D_80119A08 ;
extern OSPfsState D_80119A90 ;
typedef struct s_File
{
 int index ;
 char string[20] ;
 int pages ;
} t_File ;
extern t_File D_80119AC8[] ;
extern int func_8001172C(int index) ;
extern OSPfs D_80119A08 ;
extern OSPfsState D_80119A90 ;
extern t_File D_80119AC8[16] ;
void func_80011194(void);
void func_800111F4(void);
int func_8001172C(int index);
int func_8001172C(int index){
 int ret ;
 func_80011194() ;
 ret = osPfsFileState(&D_80119A08, D_80119AC8[index].index, &D_80119A90) ;
 if (ret == 0)
 {
  osPfsDeleteFile(&D_80119A08,
        D_80119A90.company_code,
        D_80119A90.game_code,
        D_80119A90.game_name,
        D_80119A90.ext_name) ;
 }
 func_800111F4() ;
 return ret ;
}
