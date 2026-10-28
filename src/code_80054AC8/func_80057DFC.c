#include "common.h"

typedef struct { char a[0x140]; s32 BulletPool,ShotgunPool,EnergyPool,ExpTekBowAmmo,ExpShotgunPool; char b[8]; s32 TekBowAmmo,MiniGunAmmo,GrenadeLauncherAmmo,RocketAmmo,TechWeapon2Ammo,ChronoscepterAmmo; char c[0x44]; s32 BackPackFlag; } WeaponAmmo;
s32 func_80057DFC(WeaponAmmo *pThis, s32 weapon, s32 explosive) {
    /* Report whether a weapon's ammo has reached its normal or backpack capacity. */
    switch(weapon) {
    case 100: return 1;
    case 101: if(explosive) if(pThis->ExpTekBowAmmo < 15) goto fail; else return 1; if(pThis->TekBowAmmo < 30) goto fail; else return 1;
    case 102: if(pThis->BackPackFlag) if(pThis->BulletPool < 200) goto fail; else return 1; if(pThis->BulletPool < 100) goto fail; else return 1;
    case 103: if(pThis->EnergyPool < 100) goto fail; else return 1;
    case 104: if(pThis->BackPackFlag) { if(explosive) if(pThis->ExpShotgunPool < 20) goto fail; else return 1; if(pThis->ShotgunPool < 40) goto fail; else return 1; }
              if(explosive) if(pThis->ExpShotgunPool < 10) goto fail; else return 1; if(pThis->ShotgunPool < 20) goto fail; else return 1;
    case 105: if(pThis->MiniGunAmmo < 125) goto fail; else return 1;
    case 106: if(pThis->ChronoscepterAmmo < 3) goto fail; else return 1;
    case 107: if(pThis->BackPackFlag) if(pThis->GrenadeLauncherAmmo < 30) goto fail; else return 1; if(pThis->GrenadeLauncherAmmo < 20) goto fail; else return 1;
    case 108: if(pThis->BackPackFlag) if(pThis->RocketAmmo < 12) goto fail; else return 1; if(pThis->RocketAmmo < 6) goto fail; else return 1;
    case 109: if(pThis->BackPackFlag) if(pThis->TechWeapon2Ammo < 3) goto fail; else return 1; if(pThis->TechWeapon2Ammo < 2) goto fail; else return 1;
    case 114: goto fail;
    default: goto fail;
    }
fail:
    return 0;
}
