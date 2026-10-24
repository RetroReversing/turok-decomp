#include "common.h"

typedef unsigned char sa_u8;
typedef unsigned short sa_u16;
typedef signed char sa_s8;
typedef struct CControlState_t
{
 sa_u16 BDown,
   BUp,
   BSingle,
   BDbl,
   BDblHold,
   BTimer [ 16 ];
 sa_s8 StickX,
   StickY;
 float Smooth,
   SStickX,
   SStickY;
} CControlState;
extern CControlState D_801199D0;
typedef struct
{
 CControlState *pCState;
 sa_u8 CenteringX,
       CenteringY;
 sa_u8 LookIndependant;
 sa_u16 Fire1,
       Forward,
       Backward,
       Left,
       Right,
       Duck,
       Jump,
       JumpReleased,
       MapToggle,
       SideStepLeft,
       SideStepRight,
       SelectWeaponPrev,
       SelectWeaponNext,
       SelectEnemyPrev,
       SelectEnemyNext,
       OpenDoor,
       RollRight,
       RollLeft,
       Pause,
       Start,
       StartHeld,
       UseMenu,
       LookUp,
       LookDown,
       LookLeft,
       LookRight,
       RunBackward,
       RunForward,
       RollSpeedL,
       RollSpeedR,
       GrenadeLauncherFired,
       ToggleOnScreen,
       ClickUp,
       ClickDown,
       ClickLeft,
       ClickRight,
       RunWalkToggle,
       SwimForward,
       SwimBackward,
       SwimSideStepL,
       SwimSideStepR,
       SwimUp,
       SwimBurstForward,
       MapLeft,
       MapRight,
       MapDown,
       MapUp,
       StartJump,
       AnalogLeft,
       AnalogRight,
       AnalogDown,
       AnalogUp,
       ClimbLookLeft,
       ClimbLookRight,
       ClimbUp,
       ClimbDown,
       ClimbLeft,
       ClimbRight,
       BurstSwimToggle,
       DigitalUp,
       DigitalDown,
       ZRotTog,
       ZRotLeft,
       ZRotRight,
       EnemyForward,
       EnemyBackward,
       EnemyLeft,
       EnemyRight,
       EnemyRotLeft,
       EnemyRotRight,
       FlyUp,
       FlyDown,
       FlyLeft,
       FlyRight,
       FlyForward,
       FlyBackward;
 sa_u16 PreFire1,
       PreForward,
       PreBackward,
       PreLeft,
       PreRight,
       PreDuck,
       PreJump,
       PreJumpReleased,
       PreMapToggle,
       PreSideStepLeft,
       PreSideStepRight,
       PreSelectWeaponPrev,
       PreSelectWeaponNext,
       PreSelectEnemyPrev,
       PreSelectEnemyNext,
       PreOpenDoor,
       PreRollLeft,
       PreRollRight,
       PrePause,
       PreStart,
       PreStartHeld,
       PreUseMenu,
       PreLookUp,
       PreLookDown,
       PreLookLeft,
       PreLookRight,
       PreRunBackward,
       PreRunForward,
       PreRollSpeedL,
       PreRollSpeedR,
       PreGrenadeLauncherFired,
       PreToggleOnScreen,
       PreClickUp,
       PreClickDown,
       PreClickLeft,
       PreClickRight,
       PreRunWalkToggle,
       PreSwimForward,
       PreSwimBackward,
       PreSwimSideStepL,
       PreSwimSideStepR,
       PreSwimUp,
       PreSwimBurstForward,
       PreMapLeft,
       PreMapRight,
       PreMapDown,
       PreMapUp,
       PreStartJump,
       PreAnalogLeft,
       PreAnalogRight,
       PreAnalogDown,
       PreAnalogUp,
       PreClimbLookLeft,
       PreClimbLookRight,
       PreClimbUp,
       PreClimbDown,
       PreClimbLeft,
       PreClimbRight,
       PreBurstSwimToggle,
       PreDigitalUp,
       PreDigitalDown,
       PreZRotTog,
       PreZRotLeft,
       PreZRotRight,
       PreEnemyForward,
       PreEnemyBackward,
       PreEnemyLeft,
       PreEnemyRight,
       PreEnemyRotLeft,
       PreEnemyRotRight,
       PreFlyUp,
       PreFlyDown,
       PreFlyLeft,
       PreFlyRight,
       PreFlyForward,
       PreFlyBackward;
 sa_u16 NotFire1,
       NotForward,
       NotBackward,
       NotLeft,
       NotRight,
       NotDuck,
       NotJump,
       NotJumpReleased,
       NotMapToggle,
       NotSideStepLeft,
       NotSideStepRight,
       NotSelectWeaponPrev,
       NotSelectWeaponNext,
       NotSelectEnemyPrev,
       NotSelectEnemyNext,
       NotOpenDoor,
       NotRollLeft,
       NotRollRight,
       NotPause,
       NotStart,
       NotStartHeld,
       NotUseMenu,
       NotLookUp,
       NotLookDown,
       NotLookLeft,
       NotLookRight,
       NotRunBackward,
       NotRunForward,
       NotRollSpeedL,
       NotRollSpeedR,
       NotGrenadeLauncherFired,
       NotToggleOnScreen,
       NotClickUp,
       NotClickDown,
       NotClickLeft,
       NotClickRight,
       NotRunWalkToggle,
       NotSwimForward,
       NotSwimBackward,
       NotSwimSideStepL,
       NotSwimSideStepR,
       NotSwimUp,
       NotSwimBurstForward,
       NotMapLeft,
       NotMapRight,
       NotMapDown,
       NotMapUp,
       NotStartJump,
       NotAnalogLeft,
       NotAnalogRight,
       NotAnalogDown,
       NotAnalogUp,
       NotClimbLookLeft,
       NotClimbLookRight,
       NotClimbUp,
       NotClimbDown,
       NotClimbLeft,
       NotClimbRight,
       NotBurstSwimToggle,
       NotDigitalUp,
       NotDigitalDown,
       NotZRotTog,
       NotZRotLeft,
       NotZRotRight,
       NotEnemyForward,
       NotEnemyBackward,
       NotEnemyLeft,
       NotEnemyRight,
       NotEnemyRotLeft,
       NotEnemyRotRight,
       NotFlyUp,
       NotFlyDown,
       NotFlyLeft,
       NotFlyRight,
       NotFlyForward,
       NotFlyBackward;
 sa_u8 TypeFire1,
       TypeForward,
       TypeBackward,
       TypeLeft,
       TypeRight,
       TypeDuck,
       TypeJump,
       TypeJumpReleased,
       TypeMapToggle,
       TypeSideStepLeft,
       TypeSideStepRight,
       TypeSelectWeaponPrev,
       TypeSelectWeaponNext,
       TypeSelectEnemyPrev,
       TypeSelectEnemyNext,
       TypeOpenDoor,
       TypeRollLeft,
       TypeRollRight,
       TypePause,
       TypeStart,
       TypeStartHeld,
       TypeUseMenu,
       TypeLookUp,
       TypeLookDown,
       TypeLookLeft,
       TypeLookRight,
       TypeRunBackward,
       TypeRunForward,
       TypeRollSpeedL,
       TypeRollSpeedR,
       TypeGrenadeLauncherFired,
       TypeToggleOnScreen,
       TypeClickUp,
       TypeClickDown,
       TypeClickLeft,
       TypeClickRight,
       TypeRunWalkToggle,
       TypeSwimForward,
       TypeSwimBackward,
       TypeSwimSideStepL,
       TypeSwimSideStepR,
       TypeSwimUp,
       TypeSwimBurstForward,
       TypeMapLeft,
       TypeMapRight,
       TypeMapDown,
       TypeMapUp,
       TypeStartJump,
       TypeAnalogLeft,
       TypeAnalogRight,
       TypeAnalogDown,
       TypeAnalogUp,
       TypeClimbLookLeft,
       TypeClimbLookRight,
       TypeClimbUp,
       TypeClimbDown,
       TypeClimbLeft,
       TypeClimbRight,
       TypeBurstSwimToggle,
       TypeDigitalUp,
       TypeDigitalDown,
       TypeZRotTog,
       TypeZRotLeft,
       TypeZRotRight,
       TypeEnemyForward,
       TypeEnemyBackward,
       TypeEnemyLeft,
       TypeEnemyRight,
       TypeEnemyRotLeft,
       TypeEnemyRotRight,
       TypeFlyUp,
       TypeFlyDown,
       TypeFlyLeft,
       TypeFlyRight,
       TypeFlyForward,
       TypeFlyBackward;
} CTControl;
extern CTControl* func_800502F0 (int Right);
extern CTControl D_80128A00;
extern CTControl *D_800F9E44;
extern CTControl D_80128A00;
CTControl* func_800502F0(int Right);
CTControl* func_800502F0(int Right){
 CTControl *D_800F9E44;
 D_800F9E44 = &D_80128A00;
 D_800F9E44->pCState = &D_801199D0;
 D_800F9E44->CenteringX = 5;
 D_800F9E44->CenteringY = 4;
 D_801199D0.Smooth = 2;
 D_800F9E44->LookIndependant = 0;
 D_800F9E44->PreSwimForward = 0;
 D_800F9E44->NotSwimForward = 0;
 D_800F9E44->SwimForward = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeSwimForward = 1;
 D_800F9E44->PreSwimBackward = 0;
 D_800F9E44->NotSwimBackward = 0;
 D_800F9E44->SwimBackward = Right ? 0x0004 : 0x0400;
 D_800F9E44->TypeSwimBackward = 1;
 D_800F9E44->PreSwimSideStepL = 0;
 D_800F9E44->NotSwimSideStepL = 0;
 D_800F9E44->SwimSideStepL = Right ? 0x0002 : 0x0200;
 D_800F9E44->TypeSwimSideStepL = 1;
 D_800F9E44->PreSwimSideStepR = 0;
 D_800F9E44->NotSwimSideStepR = 0;
 D_800F9E44->SwimSideStepR = Right ? 0x0001 : 0x0100;
 D_800F9E44->TypeSwimSideStepR = 1;
 D_800F9E44->PreSwimUp = 0;
 D_800F9E44->NotSwimUp = 0;
 D_800F9E44->SwimUp = Right ? 0x0010 : 0x0020;
 D_800F9E44->TypeSwimUp = 1;
 D_800F9E44->PreSwimBurstForward = 0;
 D_800F9E44->NotSwimBurstForward = 0;
 D_800F9E44->SwimBurstForward = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeSwimBurstForward = 1;
 D_800F9E44->PreFlyLeft = 0;
 D_800F9E44->NotFlyLeft = 0;
 D_800F9E44->FlyLeft = 0x0002;
 D_800F9E44->TypeFlyLeft = 1;
 D_800F9E44->PreFlyRight = 0;
 D_800F9E44->NotFlyRight = 0;
 D_800F9E44->FlyRight = 0x0001;
 D_800F9E44->TypeFlyRight = 1;
 D_800F9E44->PreFlyForward = 0;
 D_800F9E44->NotFlyForward = 0;
 D_800F9E44->FlyForward = 0x0008;
 D_800F9E44->TypeFlyForward = 1;
 D_800F9E44->PreFlyBackward = 0;
 D_800F9E44->NotFlyBackward = 0;
 D_800F9E44->FlyBackward = 0x0004;
 D_800F9E44->TypeFlyBackward = 1;
 D_800F9E44->PreFlyUp = 0;
 D_800F9E44->NotFlyUp = 0;
 D_800F9E44->FlyUp = 0x0010;
 D_800F9E44->TypeFlyUp = 1;
 D_800F9E44->PreFlyDown = 0;
 D_800F9E44->NotFlyDown = 0;
 D_800F9E44->FlyDown = 0x0020;
 D_800F9E44->TypeFlyDown = 1;
 D_800F9E44->PreMapLeft = 0;
 D_800F9E44->NotMapLeft = 0;
 D_800F9E44->MapLeft = Right ? 0x0200 : 0x0002;
 D_800F9E44->TypeMapLeft = 1;
 D_800F9E44->PreMapRight = 0;
 D_800F9E44->NotMapRight = 0;
 D_800F9E44->MapRight = Right ? 0x0100 : 0x0001;
 D_800F9E44->TypeMapRight = 1;
 D_800F9E44->PreMapUp = 0;
 D_800F9E44->NotMapUp = 0;
 D_800F9E44->MapUp = Right ? 0x0800 : 0x0008;
 D_800F9E44->TypeMapUp = 1;
 D_800F9E44->PreMapDown = 0;
 D_800F9E44->NotMapDown = 0;
 D_800F9E44->MapDown = Right ? 0x0400 : 0x0004;
 D_800F9E44->TypeMapDown = 1;
 D_800F9E44->PreAnalogLeft = 0;
 D_800F9E44->NotAnalogLeft = 0;
 D_800F9E44->AnalogLeft = 0;
 D_800F9E44->TypeAnalogLeft = 12;
 D_800F9E44->PreAnalogRight = 0;
 D_800F9E44->NotAnalogRight = 0;
 D_800F9E44->AnalogRight = 0;
 D_800F9E44->TypeAnalogRight = 13;
 D_800F9E44->PreAnalogUp = 0;
 D_800F9E44->NotAnalogUp = 0;
 D_800F9E44->AnalogUp = 0;
 D_800F9E44->TypeAnalogUp = 10;
 D_800F9E44->PreAnalogDown = 0;
 D_800F9E44->NotAnalogDown = 0;
 D_800F9E44->AnalogDown = 0;
 D_800F9E44->TypeAnalogDown = 11;
 D_800F9E44->PreForward = 0;
 D_800F9E44->NotForward = 0;
 D_800F9E44->Forward = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeForward = 1;
 D_800F9E44->PreBackward = 0;
 D_800F9E44->NotBackward = 0;
 D_800F9E44->Backward = Right ? 0x0004 : 0x0400;
 D_800F9E44->TypeBackward = 1;
 D_800F9E44->PreLeft = 0;
 D_800F9E44->NotLeft = 0;
 D_800F9E44->Left = 0;
 D_800F9E44->TypeLeft = 12;
 D_800F9E44->PreRight = 0;
 D_800F9E44->NotRight = 0;
 D_800F9E44->Right = 0;
 D_800F9E44->TypeRight = 13;
 D_800F9E44->PreRunForward = 0;
 D_800F9E44->NotRunForward = 0;
 D_800F9E44->RunForward = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeRunForward = 5;
 D_800F9E44->PreRunBackward = 0;
 D_800F9E44->NotRunBackward = 0;
 D_800F9E44->RunBackward = Right ? 0x0004 : 0x0400;
 D_800F9E44->TypeRunBackward = 5;
 D_800F9E44->PreFire1 = 0;
 D_800F9E44->NotFire1 = 0;
 D_800F9E44->Fire1 = 0x2000;
 D_800F9E44->TypeFire1 = 1;
 D_800F9E44->PreGrenadeLauncherFired = 0;
 D_800F9E44->NotGrenadeLauncherFired = 0;
 D_800F9E44->GrenadeLauncherFired = 0x2000;
 D_800F9E44->TypeGrenadeLauncherFired = 3;
 D_800F9E44->PreStartJump = 0;
 D_800F9E44->NotStartJump = 0;
 D_800F9E44->StartJump = Right ? 0x0010 : 0x0020;
 D_800F9E44->TypeStartJump = 3;
 D_800F9E44->PreJump = 0;
 D_800F9E44->NotJump = 0;
 D_800F9E44->Jump = Right ? 0x0010 : 0x0020;
 D_800F9E44->TypeJump = 1;
 D_800F9E44->PreJumpReleased = 0;
 D_800F9E44->NotJumpReleased = 0;
 D_800F9E44->JumpReleased = Right ? 0x0010 : 0x0020;
 D_800F9E44->TypeJumpReleased = 2;
 D_800F9E44->PreSelectWeaponPrev = 0;
 D_800F9E44->NotSelectWeaponPrev = 0x2000;
 D_800F9E44->SelectWeaponPrev = 0x4000;
 D_800F9E44->TypeSelectWeaponPrev = 1;
 D_800F9E44->PreSelectWeaponNext = 0;
 D_800F9E44->NotSelectWeaponNext = 0x2000;
 D_800F9E44->SelectWeaponNext = 0x8000;
 D_800F9E44->TypeSelectWeaponNext = 1;
 D_800F9E44->PreSelectEnemyPrev = 0;
 D_800F9E44->NotSelectEnemyPrev = 0;
 D_800F9E44->SelectEnemyPrev = 0x4000;
 D_800F9E44->TypeSelectEnemyPrev = 3;
 D_800F9E44->PreSelectEnemyNext = 0;
 D_800F9E44->NotSelectEnemyNext = 0;
 D_800F9E44->SelectEnemyNext = 0x8000;
 D_800F9E44->TypeSelectEnemyNext = 3;
 D_800F9E44->PreEnemyForward = 0;
 D_800F9E44->NotEnemyForward = 0;
 D_800F9E44->EnemyForward = 0x0800;
 D_800F9E44->TypeEnemyForward = 3;
 D_800F9E44->PreEnemyBackward = 0;
 D_800F9E44->NotEnemyBackward = 0;
 D_800F9E44->EnemyBackward = 0x0400;
 D_800F9E44->TypeEnemyBackward = 3;
 D_800F9E44->PreEnemyLeft = 0;
 D_800F9E44->NotEnemyLeft = 0;
 D_800F9E44->EnemyLeft = 0x0200;
 D_800F9E44->TypeEnemyLeft = 3;
 D_800F9E44->PreEnemyRight = 0;
 D_800F9E44->NotEnemyRight = 0;
 D_800F9E44->EnemyRight = 0x0100;
 D_800F9E44->TypeEnemyRight = 3;
 D_800F9E44->PreEnemyRotLeft = 0;
 D_800F9E44->NotEnemyRotLeft = 0;
 D_800F9E44->EnemyRotLeft = 0x0020;
 D_800F9E44->TypeEnemyRotLeft = 3;
 D_800F9E44->PreEnemyRotRight = 0;
 D_800F9E44->NotEnemyRotRight = 0;
 D_800F9E44->EnemyRotRight = 0x0010;
 D_800F9E44->TypeEnemyRotRight = 3;
 D_800F9E44->PreRunWalkToggle = 0;
 D_800F9E44->NotRunWalkToggle = 0;
 D_800F9E44->RunWalkToggle = Right ? (0x0400 | 0x0800 | 0x0200 | 0x0100) : (0x0004 | 0x0008 | 0x0002 | 0x0001);
 D_800F9E44->TypeRunWalkToggle = 3;
 D_800F9E44->PreBurstSwimToggle = 0;
 D_800F9E44->NotBurstSwimToggle = 0;
 D_800F9E44->BurstSwimToggle = Right ? (0x0400 | 0x0800 | 0x0200 | 0x0100) : (0x0004 | 0x0008 | 0x0002 | 0x0001);
 D_800F9E44->TypeBurstSwimToggle = 3;
 D_800F9E44->PreOpenDoor = 0;
 D_800F9E44->NotOpenDoor = 0;
 D_800F9E44->OpenDoor = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeOpenDoor = 3;
 D_800F9E44->PreMapToggle = 0;
 D_800F9E44->NotMapToggle = 0;
 D_800F9E44->MapToggle = Right ? 0x0020 : 0x0010 ;
 D_800F9E44->TypeMapToggle = 1;
 D_800F9E44->PreToggleOnScreen = 0;
 D_800F9E44->NotToggleOnScreen = 0;
 D_800F9E44->ToggleOnScreen = 0;
 D_800F9E44->TypeToggleOnScreen = 0;
 D_800F9E44->PreSideStepLeft = 0;
 D_800F9E44->NotSideStepLeft = 0;
 D_800F9E44->SideStepLeft = Right ? 0x0002 : 0x0200;
 D_800F9E44->TypeSideStepLeft = 1;
 D_800F9E44->PreSideStepRight = 0;
 D_800F9E44->NotSideStepRight = 0;
 D_800F9E44->SideStepRight = Right ? 0x0001 : 0x0100;
 D_800F9E44->TypeSideStepRight = 1;
 D_800F9E44->PreRollLeft = 0;
 D_800F9E44->NotRollLeft = 0;
 D_800F9E44->RollLeft = Right ? 0x0002 : 0x0200;
 D_800F9E44->TypeRollLeft = 4;
 D_800F9E44->PreRollRight = 0;
 D_800F9E44->NotRollRight = 0;
 D_800F9E44->RollRight = Right ? 0x0001 : 0x0100;
 D_800F9E44->TypeRollRight = 4;
 D_800F9E44->PreRollSpeedL = 0;
 D_800F9E44->NotRollSpeedL = 0;
 D_800F9E44->RollSpeedL = 0;
 D_800F9E44->TypeRollSpeedL = 12;
 D_800F9E44->PreRollSpeedR = 0;
 D_800F9E44->NotRollSpeedR = 0;
 D_800F9E44->RollSpeedR = 0;
 D_800F9E44->TypeRollSpeedR = 13;
 D_800F9E44->PrePause = 0;
 D_800F9E44->NotPause = 0;
 D_800F9E44->Pause = 0x1000;
 D_800F9E44->TypePause = 3;
 D_800F9E44->PreStart = 0;
 D_800F9E44->NotStart = 0;
 D_800F9E44->Start = 0x1000;
 D_800F9E44->TypeStart = 3;
 D_800F9E44->PreStartHeld = 0;
 D_800F9E44->NotStartHeld = 0;
 D_800F9E44->StartHeld = 0x1000;
 D_800F9E44->TypeStartHeld = 1;
 D_800F9E44->PreUseMenu = 0;
 D_800F9E44->NotUseMenu = 0;
 D_800F9E44->UseMenu = 0x8000 | 0x1000;
 D_800F9E44->TypeUseMenu = 3;
 D_800F9E44->PreZRotTog = 0;
 D_800F9E44->NotZRotTog = 0;
 D_800F9E44->ZRotTog = 0x0020 | 0x0010;
 D_800F9E44->TypeZRotTog = 1;
 D_800F9E44->PreZRotLeft = 0;
 D_800F9E44->NotZRotLeft = 0;
 D_800F9E44->ZRotLeft = 0x8000;
 D_800F9E44->TypeZRotLeft = 1;
 D_800F9E44->PreZRotRight = 0;
 D_800F9E44->NotZRotRight = 0;
 D_800F9E44->ZRotRight = 0x4000;
 D_800F9E44->TypeZRotRight = 1;
 D_800F9E44->PreClickUp = 0;
 D_800F9E44->NotClickUp = 0;
 D_800F9E44->ClickUp = 0x0800 | 0x0008;
 D_800F9E44->TypeClickUp = 3;
 D_800F9E44->PreClickDown = 0;
 D_800F9E44->NotClickDown = 0;
 D_800F9E44->ClickDown = 0x0400 | 0x0004;
 D_800F9E44->TypeClickDown = 3;
 D_800F9E44->PreClickLeft = 0;
 D_800F9E44->NotClickLeft = 0;
 D_800F9E44->ClickLeft = 0x0200 | 0x0002;
 D_800F9E44->TypeClickLeft = 3;
 D_800F9E44->PreClickRight = 0;
 D_800F9E44->NotClickRight = 0;
 D_800F9E44->ClickRight = 0x0100 | 0x0001;
 D_800F9E44->TypeClickRight = 3;
 D_800F9E44->PreDigitalUp = 0;
 D_800F9E44->NotDigitalUp = 0;
 D_800F9E44->DigitalUp = 0x0800 | 0x0008;
 D_800F9E44->TypeDigitalUp = 1;
 D_800F9E44->PreDigitalDown = 0;
 D_800F9E44->NotDigitalDown = 0;
 D_800F9E44->DigitalDown = 0x0400 | 0x0004;
 D_800F9E44->TypeDigitalDown = 1;
 D_800F9E44->PreLookUp = 0;
 D_800F9E44->NotLookUp = 0;
 D_800F9E44->LookUp = 0;
 D_800F9E44->TypeLookUp = 10;
 D_800F9E44->PreLookDown = 0;
 D_800F9E44->NotLookDown = 0;
 D_800F9E44->LookDown = 0;
 D_800F9E44->TypeLookDown = 11;
 D_800F9E44->PreLookLeft = 0;
 D_800F9E44->NotLookLeft = 0;
 D_800F9E44->LookLeft = 0;
 D_800F9E44->TypeLookLeft = 0;
 D_800F9E44->PreLookRight = 0;
 D_800F9E44->NotLookRight = 0;
 D_800F9E44->LookRight = 0;
 D_800F9E44->TypeLookRight = 0;
 D_800F9E44->PreClimbLookLeft = 0;
 D_800F9E44->NotClimbLookLeft = 0;
 D_800F9E44->ClimbLookLeft = 0;
 D_800F9E44->TypeClimbLookLeft = 12;
 D_800F9E44->PreClimbLookRight = 0;
 D_800F9E44->NotClimbLookRight = 0;
 D_800F9E44->ClimbLookRight = 0;
 D_800F9E44->TypeClimbLookRight = 13;
 D_800F9E44->PreClimbUp = 0;
 D_800F9E44->NotClimbUp = 0;
 D_800F9E44->ClimbUp = Right ? 0x0008 : 0x0800;
 D_800F9E44->TypeClimbUp = 1;
 D_800F9E44->PreClimbDown = 0;
 D_800F9E44->NotClimbDown = 0;
 D_800F9E44->ClimbDown = Right ? 0x0004 : 0x0400;
 D_800F9E44->TypeClimbDown = 1;
 D_800F9E44->PreClimbLeft = 0;
 D_800F9E44->NotClimbLeft = 0;
 D_800F9E44->ClimbLeft = Right ? 0x0002 : 0x0200;
 D_800F9E44->TypeClimbLeft = 1;
 D_800F9E44->PreClimbRight = 0;
 D_800F9E44->NotClimbRight = 0;
 D_800F9E44->ClimbRight = Right ? 0x0001 : 0x0100;
 D_800F9E44->TypeClimbRight = 1;
 return D_800F9E44;
}
