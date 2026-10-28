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
extern float CTControl__Action ( CTControl *pThis,
                   sa_u16 Action,
                     sa_u16 Pre,
                     sa_u16 Type,
                   sa_u16 Not );
float CTControl__Action ( CTControl *pThis, sa_u16 Action, sa_u16 Pre, sa_u16 Type, sa_u16 Not );
float CTControl__Action ( CTControl *pThis, sa_u16 Action, sa_u16 Pre, sa_u16 Type, sa_u16 Not ){
 /* Return the mapped digital state or scaled stick movement for an action. */
 CControlState *pCState;
 pCState = pThis->pCState;
 if ( (Pre == 0) || (pCState->BDown & Pre) )
 {
  if ( pCState->BDown & Not ) return 0;
  switch ( Type )
  {
   case CTTYPE_DOWN:
    return ( Action & pCState->BDown ) ? CT_MAX_OUTPUT : 0;
   case CTTYPE_UP:
    return ( Action & pCState->BUp ) ? CT_MAX_OUTPUT : 0;
   case CTTYPE_SINGLE:
    return ( Action & pCState->BSingle ) ? CT_MAX_OUTPUT : 0;
   case CTTYPE_DBL:
    return ( Action & pCState->BDbl ) ? CT_MAX_OUTPUT : 0;
   case CTTYPE_DBLHOLD:
    return ( Action & pCState->BDblHold ) ? CT_MAX_OUTPUT : 0;
   case CTTYPE_STICK_FORWARD:
    if ( pCState->StickY <= +pThis->CenteringY )
     return 0;
    else
     return (pCState->StickY - pThis->CenteringY) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringY);
   case CTTYPE_STICK_BACKWARD:
    if ( pCState->StickY >= -pThis->CenteringY )
     return 0;
    else
     return ((-pCState->StickY) - pThis->CenteringY) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringY);
   case CTTYPE_STICK_LEFT:
    if ( pCState->StickX >= -pThis->CenteringX )
     return 0;
    else
     return ((-pCState->StickX) - pThis->CenteringX) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringX);
   case CTTYPE_STICK_RIGHT:
    if ( pCState->StickX <= +pThis->CenteringX )
     return 0;
    else
     return (pCState->StickX - pThis->CenteringX) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringX);
   case CTTYPE_STICK_SFORWARD:
    if ( pCState->SStickY <= +pThis->CenteringY )
     return 0;
    else
     return (pCState->SStickY - pThis->CenteringY) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringY);
   case CTTYPE_STICK_SBACKWARD:
    if ( pCState->SStickY >= -pThis->CenteringY )
     return 0;
    else
     return ((-pCState->SStickY) - pThis->CenteringY) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringY);
   case CTTYPE_STICK_SLEFT:
    if ( pCState->SStickX >= -pThis->CenteringX )
     return 0;
    else
     return ((-pCState->SStickX) - pThis->CenteringX) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringX);
   case CTTYPE_STICK_SRIGHT:
    if ( pCState->SStickX <= +pThis->CenteringX )
     return 0;
    else
     return (pCState->SStickX - pThis->CenteringX) * CT_MAX_STICK / (CT_MAX_STICK-pThis->CenteringX);
  }
 }
 return 0;
}
