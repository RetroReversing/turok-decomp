#include "common.h"

typedef struct 
{
  u32 pad;
  u32 x;
  u32 y;
  u32 z;
} Vec;
typedef struct 
{
  u32 x;
  u32 y;
  u32 z;
} Vec3;
typedef struct 
{
  u8 p0[0x18];
  void *target;
  u8 p1[0x44];
  f32 threshold;
  u8 p2[0x148];
  f32 a1ac;
  u8 p3[0xC];
  f32 a1bc;
  u8 p4[0x10];
  s32 flags;
  u8 p5[0x50];
  Vec *v224;
} Obj;
extern f32 func_8005EDD8(Obj *);
extern f32 func_800747C0(Obj *, Vec3, void *, f32);
extern f32 func_8005F34C(Obj *, Vec3);
extern void func_80072144(Obj *, f32);
extern void func_8005F2B8(Obj *, s32, s32);
extern f32 D_800B6B00;
extern f64 D_800F5C08;
extern u8 *D_8010201C;

#define DEBUG_STAND_AI 0
static __inline s32 IsPlayerAlive(void){ return (*(s16 *)(D_8010201C+0x1dc)>0); }
void func_80079090(Obj *pMe)
{
	float						turnang,
								dist,
								avoidrad;
	Obj	*pDest;
	Vec3					vDestPos;

#if DEBUG_STAND_AI
	rmonPrintf("AI_Standard_TeleportMoveSlow\r\n") ;
#endif

	// get avoidance radius
	avoidrad = func_8005EDD8(pMe);

	// get target
	pDest = pMe->v224;
	vDestPos = (*(Vec3 *)((u8 *)pDest+4));

	(pMe)->a1bc =
	turnang = func_800747C0(pMe, vDestPos, pDest, avoidrad);

	// how close is this ai to destination ?
	dist = func_8005F34C(pMe, vDestPos);

	// make ai go towards target
	func_80072144(pMe, turnang);

	// increase teleport time
	(pMe)->a1ac -= D_800B6B00*D_800F5C08;
	if (    ((pMe)->a1ac < 0)
		  || (dist <= (*(f32 *)((u8*)pMe->target+0x28))) )
	{
		(pMe)->flags &= (~0x400000);
		(pMe)->flags &= (~0x800000);
	}

	// keep agitation up, now that we are fighting (only if ai we are attacking is alive)
	if (IsPlayerAlive())
		func_8005F2B8(pMe, 300, 300);
}
