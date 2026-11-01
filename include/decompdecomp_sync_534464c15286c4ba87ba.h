typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16; typedef long s32; typedef unsigned long u32; typedef long long s64; typedef unsigned long long u64; typedef float f32; typedef double f64;
typedef unsigned int UINT32;
#define NULL ((void*)0)
#define FALSE 0
#define ASSERT(x)
typedef struct s_Memory {
	struct s_Memory *prev ;
	struct s_Memory *next ;
	void			*addr ;
	int				size ;
} t_Memory ;


//----	Pool allocation structure
typedef struct s_MemoryPool {
	void			*addr ;
	int				size ;			// Available memory (not including t_MemoryPool * t_Memory headers)
	struct s_Memory *free_head ;
	struct s_Memory *free_tail ;
	struct s_Memory *used_head ;
} t_MemoryPool ;


