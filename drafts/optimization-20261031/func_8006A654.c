#include "context_8d698fdff8b3.h"
#line 1 "func.c"
extern s32 func_8001D398(void);
extern s32 func_800210FC(void *);
extern void func_8005EED0(void *, s32, f32, s32);
void func_8006A654(void *arg0, void * volatile arg1, void * volatile arg2, void * volatile arg3)
{
  s32 n = func_8001D398();
  switch (n)
  {
    case 0:
      func_8005EED0(arg0, 0xD8, 1.0f, 0);
      break;

    case 1:
      switch (func_800210FC(*((void **) (((u8 *) arg0) + 0x14))))
    {
      case 0:
        func_8005EED0(arg0, 0xB5, 1.0f, 0);
        break;

      case 1:
        func_8005EED0(arg0, 0xBA, 1.0f, 0);
 if (1) { }
        break;

      case 2:
        func_8005EED0(arg0, 0xBC, 1.0f, 0);
        break;

      case 3:
        func_8005EED0(arg0, 0xBB, 1.0f, 0);
        break;

      default:
        func_8005EED0(arg0, 0xBB, 1.0f, 0);
        break;

    }

      break;

    case 2:
      func_8005EED0(arg0, 0xDE, 1.0f, 0);
      break;

    case 3:
      func_8005EED0(arg0, 0xE6, 1.0f, 0);
      break;

    case 4:
      func_8005EED0(arg0, 0xFA, 1.0f, 0);
      break;

    case 5:
      func_8005EED0(arg0, 0xED, 1.0f, 0);
      break;

    case 6:
      func_8005EED0(arg0, 0x125, 1.0f, 0);
      break;

    case 7:
      func_8005EED0(arg0, 0x134, 1.0f, 0);
      break;

    case 8:
      func_8005EED0(arg0, 0x13C, 1.0f, 0);
      if (!arg0)
    {
    }
      break;

    case 1001:
      func_8005EED0(arg0, 0x157, 1.0f, 0);
      break;

    case 1002:

    case 1003:
      func_8005EED0(arg0, 0xB5, 1.0f, 0);
      break;

    case 22:

    case 1000:
      break;

  }

}

