#include "common.h"

typedef struct EA
{
  char pad[0x4e];
  s8 m_AttackStyle;
} EA;
typedef struct CInstanceHdr
{
  char pad[0x18];
  EA *m_pEA;
} CInstanceHdr;
typedef struct CVector3
{
  f32 x;
  f32 y;
  f32 z;
} CVector3;
extern s32 func_8001D398(CInstanceHdr *);
extern s32 func_800137A0(void);
extern s32 func_8005EED0(CInstanceHdr *, s32, f32, s32);
void func_8006A8FC(CInstanceHdr *pThis, CVector3 pos, float Value)
{
  int n;
  int s;
  switch (func_8001D398(pThis))
  {
    case 0:
      break;

    case 1:
      func_8005EED0(pThis, 0xdb, 1, 0);
      break;

    case 2:
      if ((pThis->m_pEA->m_AttackStyle >= 25) && (pThis->m_pEA->m_AttackStyle < 28))
    {
      func_8005EED0(pThis, 0x11c, 1, 0);
    }
    else
    {
      n = func_800137A0() % 3;
      switch (n)
      {
        case 0:
          s = 0x113;
          break;

        case 1:
          s = 0x114;
          break;

        default:
          s = 0x115;
          break;

      }

      if ((pThis->m_pEA->m_AttackStyle >= 28) && (pThis->m_pEA->m_AttackStyle < 30))
      {
        func_8005EED0(pThis, (0, s), 1, 0x80);
      }
      else
      {
        func_8005EED0(pThis, s, 1, 2);
      }
    }
      break;

    case 3:
      func_8005EED0(pThis, 0xe3, 1, 0);
      break;

    case 4:
      func_8005EED0(pThis, 0xea, 1, 0);
      break;

    case 5:
      func_8005EED0(pThis, 0xfb, 1, 0);
      break;

    case 6:
      func_8005EED0(pThis, 0xf2, 1, 0);
      break;

    case 7:
      func_8005EED0(pThis, 0xf8, 1, 0);
      break;

    case 8:
      func_8005EED0(pThis, 0x123, 1, 0);
      break;

    case 9:
      func_8005EED0(pThis, 0x12a, 1, 0);
      break;

    case 10:
      func_8005EED0(pThis, 0x131, 1, 0);
      break;

    case 11:
      func_8005EED0(pThis, 0x139, 1, 0);
      break;

    case 12:
      func_8005EED0(pThis, 0x147, 1, 0);
      break;

    case 1000:
      func_8005EED0(pThis, 0x151, 1, 0);
      break;

    case 13:

    case 14:

    case 20:

    case 21:

    case 22:
      break;

  }

}
