#include "common.h"

typedef struct {
  u8 p[0x3c];
  u32 pickupFlags;
} EnemyAttributes;
typedef struct {
  u8 p[0x18];
  EnemyAttributes *attributes;
  u8 q[0x1b4];
  s32 mortalWoundStatus;
} EnemyInstance;
typedef struct {
  s32 x;
  s32 y;
  s32 z;
} PickupPosition;
extern s32 func_800137A0(void);
extern void func_80063C4C(EnemyInstance *, PickupPosition, s32, f32);
void func_80063DE8(EnemyInstance *enemy, PickupPosition position)
{
  /* Spawn the pickup types selected by this enemy's attribute flags. */
  volatile u32 pickupFlags = enemy->attributes->pickupFlags;
  u32 mask = 1;
  s32 remaining = 30;
  s32 pickupType;
  do
  {
    if (pickupFlags & mask)
    {
      switch (mask)
      {
        case 1:
          pickupType = 0x1AB;
          break;

        case 2:
          pickupType = 0x1AE;
          break;

        case 4:
          pickupType = 0x191;
          break;

        case 8:
          pickupType = 0x193;
          break;

        case 16:
          pickupType = 0x194;
          break;

        case 32:
          pickupType = 0x190;
          break;

        case 64:
          pickupType = 0x192;
          break;

        case 128:
          pickupType = 0x1AD;
          break;

        case 256:
          if ((enemy->mortalWoundStatus << 1) < (((enemy->mortalWoundStatus << 1) < 0) * 0))
        {
          if ((func_800137A0() % 100) < 15)
          {
            pickupType = 0x195;
          }
          else
          {
            pickupType = 0;
          }
        }
        else
        {
          pickupType = 0;
        }
          break;

        case 512:
          pickupType = 0x1B2;
          break;

        case 1024:
          pickupType = 0x1A9;
          break;

        case 2048:
          pickupType = 0x1B0;
          break;

        case 4096:
          pickupType = 0x1B1;
          break;

        case 8192:
          pickupType = 0x1A7;
          break;

        default:
          pickupType = 0;
          break;

      }

      if (pickupType != 0)
      {
        func_80063C4C(enemy, position, pickupType, 120.0);
      }
    }
    mask = mask * 2;
  }
  while (remaining--);
}
