#include "common.h"

typedef struct EA { char pad[0x4e]; s8 m_AttackStyle; } EA;
typedef struct CInstanceHdr { char pad[0x18]; EA *m_pEA; } CInstanceHdr;
typedef struct CVector3 { f32 x,y,z; } CVector3;
extern s32 func_8001D398(CInstanceHdr *);
extern s32 func_800137A0(void);
extern s32 func_8005EED0(CInstanceHdr *,s32,f32,s32);
void func_8006A220 (CInstanceHdr *pThis, CVector3 vPos, float Value ){
 /* Play a species specific violent death sound for an AI event. */
 int soundChoice, soundId;
                                                                  ;
 switch (func_8001D398(pThis))
 {
  case 0:
   break;
  case 20:
   break;
  case 21:
   break;
  case 22:
   break;
  case 1:
   func_8005EED0(pThis, 0xdc, 1, 0);
   break;
  case 2:
   if ( (pThis->m_pEA->m_AttackStyle >= 25)
     && (pThis->m_pEA->m_AttackStyle <= 27) )
   {
    func_8005EED0(pThis, 0x11c, 1, 0);
   }
   else
   {
    soundChoice = (func_800137A0() % (3));
    switch (soundChoice)
    {
     case 0: soundId = 0x116; break;
     case 1: soundId = 0x117; break;
     default: soundId = 0x118; break;
    }
    if ( (pThis->m_pEA->m_AttackStyle >= 28)
      && (pThis->m_pEA->m_AttackStyle <= 29) )
    {
     func_8005EED0(pThis, soundId, 1, (1 << 7));
    }
    else
    {
     func_8005EED0(pThis, soundId, 1, (1 << 1));
    }
   }
   break;
  case 3:
   func_8005EED0(pThis, 0xe4, 1, 0);
   break;
  case 4:
   func_8005EED0(pThis, 0xeb, 1, 0);
   break;
  case 5:
   func_8005EED0(pThis, 0xfb, 1, 0);
   break;
  case 6:
   func_8005EED0(pThis, 0xf3, 1, 0);
   break;
  case 7:
   func_8005EED0(pThis, 0xf8, 1, 0);
   break;
  case 8:
   func_8005EED0(pThis, 0x124, 1, 0);
   break;
  case 9:
   func_8005EED0(pThis, 0x12b, 1, 0);
   break;
  case 10:
   func_8005EED0(pThis, 0x133, 1, 0);
   break;
  case 11:
   func_8005EED0(pThis, 0x13a, 1, 0);
   break;
  case 12:
   func_8005EED0(pThis, 0x147, 1, 0);
   break;
  case 13:
   break;
  case 14:
   break;
  case 1000:
   func_8005EED0(pThis, 0x156, 1, 0);
   break;
 }
}
