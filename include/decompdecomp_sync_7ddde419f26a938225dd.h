typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef unsigned int size_t;
typedef double ldouble;
typedef struct {union{long long ll;ldouble ld;}v;char*s;int n0,nz0,n1,nz1,n2,nz2,prec,width;size_t nchar;unsigned int flags;char qual;} _Pft;
typedef struct {long long quot,rem;} lldiv_t;
lldiv_t lldiv(long long,long long);
void *memcpy(void*,const void*,size_t);
#define memcpy memcpy
#define _FSP 1
#define _FPL 2
#define _FMI 4
#define _FNO 8
#define _FZE 16
char D_800EF770[]="0123456789abcdef";
char D_800EF784[]="0123456789ABCDEF";
#define ldigs D_800EF770
#define udigs D_800EF784

u64 func_8009D38C(u64,u64);u64 __ull_div(u64,u64);

