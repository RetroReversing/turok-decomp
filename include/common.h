/* context.h for TUROK_DINOSAUR_HUNTE: shared by every function. Agents grow it with edit_context:
 * add a prototype or struct the moment you work one out, so the next function benefits. */

typedef signed char s8;
typedef unsigned char u8;
typedef signed short s16;
typedef unsigned short u16;
typedef signed int s32;
typedef unsigned int u32;
typedef signed long long s64;
typedef unsigned long long u64;
typedef float f32;
typedef double f64;
typedef volatile u8 vu8;
typedef volatile u16 vu16;
typedef volatile u32 vu32;
typedef volatile s32 vs32;
typedef int s32_bool;

#define NULL ((void *)0)
#define TRUE 1
#define FALSE 0
#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))

/* tcontrol.h: input action types and output limits. */
#define CTTYPE_DOWN 1
#define CTTYPE_UP 2
#define CTTYPE_SINGLE 3
#define CTTYPE_DBL 4
#define CTTYPE_DBLHOLD 5
#define CTTYPE_STICK_FORWARD 6
#define CTTYPE_STICK_BACKWARD 7
#define CTTYPE_STICK_LEFT 8
#define CTTYPE_STICK_RIGHT 9
#define CTTYPE_STICK_SFORWARD 10
#define CTTYPE_STICK_SBACKWARD 11
#define CTTYPE_STICK_SLEFT 12
#define CTTYPE_STICK_SRIGHT 13
#define CT_MAX_OUTPUT -1
#define CT_MAX_STICK 80
