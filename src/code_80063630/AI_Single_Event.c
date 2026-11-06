#include "decompdecomp_sync_dbe1ef56f08e11b320fd.h"
#line 1 "func.c"
#line 504 "reference.c"
void AI_Single_Event(CInstanceHdr *pThis, CInstanceHdr *pOrigin, int Event, CVector3 vPos, float Value)
{
	switch (Event)
	{
		case AI_SEVENT_ACIDINCOMING:
			D_8006BC54 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ACIDSPITPART:
			D_8006BBFC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ACIDSPITSND:
			D_8006BBE8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_BLOWGUNFIRE:
			D_8006BBB4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_BREATHPART:
			AI_SEvent_BreathPart ( pThis, vPos, Value );
			break;

		case AI_SEVENT_BREATHSND:
			D_8006BAF4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_CHARGEHEADSLAM:
			D_8006BAE0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATHRAINPART:
			D_8006BA88 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATHRAINSND:
			D_8006BA54 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_EARTHQUAKE:
			D_8006BA20 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ENERGYBLASTPART:
			AI_SEvent_EnergyBlastPart ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ENERGYBLASTSND:
			D_8006B984 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_EXPLOSIVELAUNCHED:
			D_8006B950 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_EYEFIREPART:
			D_8006B8F8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_EYEFIRESND:
			D_8006B8C4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_FIREBALLPART:
			AI_SEvent_FireBallPart ( pThis, vPos, Value );
			break;

		case AI_SEVENT_FIREBALLSND:
			D_8006B804 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_JAWSSNAP:
			D_8006B7F0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SHOCKWAVEPART:
			D_8006B798 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SHOCKWAVESND:
			D_8006B764 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SPELLCASTPART:
			D_8006B70C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SPELLCASTSND:
			D_8006B6D8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SWINGFISTSWEAPON:
			D_8006B6A4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WEAPONFIRE:
			D_8006B690 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WEAPONROUND:
			AI_SEvent_WeaponRound ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WEAPONCOCK:
			D_8006B1B4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_LOOKOFFSET:
			D_8006B184 ( pThis, Value );
			break;

		case AI_SEVENT_CHITTER:
			AI_SEvent_Chitter ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SURFACEIMPACT:
			AI_SEvent_SurfaceImpact ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALERT:
			AI_SEvent_Alert ( pThis, vPos, Value );
			break;

		case AI_SEVENT_HYDRAULICS:
			D_8006ABE4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SHUTDOWN:
			D_8006ABB0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SWIVEL:
			D_8006AB7C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_JETPACKOUTOFCTRL:
			D_8006AB48 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_BURSTFROMGROUND:
			D_8006AB34 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_CHESTTHUMP:
			D_8006AB24 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATH:
			AI_SEvent_Death ( pThis, vPos, Value );
			break;

		case AI_SEVENT_EXPLODE:
			D_8006A8C8 ( pThis, vPos, Value );

			break;

		case AI_SEVENT_FOOTFALL:
			D_8006A654 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GRUNT:
			AI_SEvent_Grunt ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GURGLE:
			D_8006A640 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_HANDFALL:
			D_8006A5F8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_HISS:
			D_8006A5E4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_HITGROUND:
			D_8006A5D0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_LICKING:
			D_8006A5BC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_RAGE:
			D_8006A574 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ROCKNOISE1:
			D_8006A540 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_RUBBINGSKIN:
			D_8006A52C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SCRATCH:
			D_8006A518 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SCREECH:
			D_8006A4E4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SNIFF:
			D_8006A4B0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SWOOSH:
			D_8006A47C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_TURNTOSTONE:
			D_8006A448 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_VIOLENTDEATH:
			AI_SEvent_ViolentDeath ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WINGFLAP:
			D_8006A20C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GROWL:
			D_8006A1BC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALERT1:
			D_80069F84 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALERT2:
			D_80069F74 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALERT3:
			D_80069F64 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALERT4:
			D_80069F50 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATH1:
			D_80069F40 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATH2:
			D_80069F30 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATH3:
			D_80069F20 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DEATH4:
			D_80069F10 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_INJURY1:
			D_80069F00 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_INJURY2:
			D_80069EF0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_INJURY3:
			D_80069EE0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_LONG1:
			D_80069ECC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_LONG2:
			D_80069EB8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_LONG3:
			D_80069EA4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_TAUNT1:
			D_80069E5C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_TAUNT2:
			D_80069E14 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_TAUNT3:
			D_80069E00 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_VIOLENTDEATH1:
			D_80069DEC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_VIOLENTDEATH2:
			D_80069DD8 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SCREENSHAKE:
			D_80069C48 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SCREENTREMOR:
			AI_SEvent_ScreenTremor ( pThis, vPos, Value );
			break;

		case AI_SEVENT_INVINCIBLE:
			D_80069BC4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_BLOODARCPARTICLES:
			D_80069B78 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_MUZZLEFLASH:
			D_80069B2C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_HULK_BLASTER:
			D_80069AE0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ALIEN_PROJECTILE:
			D_80069A94 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_KNIFEFORWARD:
			D_80069A48 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_KNIFELEFT:
			D_800699FC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_KNIFERIGHT:
			D_800699B0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GREENBLOODARCPARTICLES:
			AI_SEvent_GreenBloodArcParticles ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SPURT_BLOODPARTICLES:
			AI_SEvent_SpurtBloodArcParticles ( pThis, vPos, Value );
			break;

		case AI_SEVENT_FOUNTAIN_BLOODPARTICLES:
			D_8006965C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GUSH_BLOODPARTICLES:
			D_80069610 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_DROOL_PARTICLES:
			D_800695C4 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ARTERIAL_BLOODPARTICLES:
			D_80069578 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_SPURT_GBLOODPARTICLES:
			D_8006952C ( pThis, vPos, Value );
			break;

		case AI_SEVENT_FOUNTAIN_GBLOODPARTICLES:
			D_800694E0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_GUSH_GBLOODPARTICLES:
			D_80069494 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ARTERIAL_GBLOODPARTICLES:
			D_80069448 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WATER_DROP:
			D_800693FC ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WATER_FOAM:
			D_800693B0 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WATER_STEAM:
			D_80069364 ( pThis, vPos, Value );
			break;

		case AI_SEVENT_ARROW_DAMAGE:
			AI_SEvent_Arrow_Damage(pThis, pOrigin, vPos, Value);
			break;

		case AI_SEVENT_DAMAGETARGET:
			AI_SEvent_Damage_Target(pThis, pOrigin, vPos, Value);
			break;

		case AI_SEVENT_DAMAGENUDGETARGET:
			D_8006905C(pThis, pOrigin, vPos, Value);
			break;

		case AI_SEVENT_GENERIC1:
			D_80069010(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC2:
			D_80068FC4(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC3:
			D_80068F78(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC4:
			D_80068F2C(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC5:
			D_80068EE0(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC6:
			D_80068E94(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC7:
			D_80068E48(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC8:
			D_80068DFC(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC9:
			D_80068DB0(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC10:
			D_80068D64(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC11:
			D_80068D18(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC12:
			D_80068CCC(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC13:
			D_80068C80(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC14:
			D_80068C34(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC15:
			D_80068BE8(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC16:
			D_80068B9C(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC17:
			D_80068B50(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC18:
			D_80068B04(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC19:
			D_80068AB8(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC20:
			D_80068A6C(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC21:
			D_80068A20(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC22:
			D_800689D4(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC23:
			D_80068988(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC24:
			D_8006893C(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC25:
			D_800688F0(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC26:
			D_800688A4(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC27:
			D_80068858(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC28:
			D_8006880C(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC29:
			D_800687C0(pThis, vPos, Value);
			break;
		case AI_SEVENT_GENERIC30:
			D_80068774(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC31:
			D_80068728(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC32:
			D_800686DC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC33:
			D_80068690(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC34:
			D_80068644(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC35:
			D_800685F8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC36:
			D_800685AC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC37:
			D_80068560(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC38:
			D_80068514(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC39:
			D_800684C8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC40:
			D_8006847C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC41:
			D_80068430(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC42:
			D_800683E4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC43:
			D_80068398(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC44:
			D_8006834C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC45:
			D_80068300(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC46:
			D_800682B4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC47:
			D_80068268(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC48:
			D_8006821C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC49:
			D_800681D0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC50:
			D_80068184(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC51:
			D_80068138(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC52:
			D_800680EC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC53:
			D_800680A0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC54:
			D_80068054(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC55:
			D_80068008(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC56:
			D_80067FBC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC57:
			D_80067F70(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC58:
			D_80067F24(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC59:
			D_80067ED8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC60:
			D_80067E8C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC61:
			D_80067E40(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC62:
			D_80067DF4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC63:
			D_80067DA8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC64:
			D_80067D5C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC65:
			D_80067D10(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC66:
			D_80067CC4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC67:
			D_80067C78(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC68:
			D_80067C2C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC69:
			D_80067BE0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC70:
			D_80067B94(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC71:
			D_80067B48(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC72:
			D_80067AFC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC73:
			D_80067AB0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC74:
			D_80067A64(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC75:
			D_80067A18(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC76:
			D_800679CC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC77:
			D_80067980(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC78:
			D_80067934(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC79:
			D_800678E8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC80:
			D_8006789C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC81:
			D_80067850(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC82:
			D_80067804(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC83:
			D_800677B8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC84:
			D_8006776C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC85:
			D_80067720(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC86:
			D_800676D4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC87:
			D_80067688(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC88:
			D_8006763C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC89:
			D_800675F0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC90:
			D_800675A4(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC91:
			D_80067558(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC92:
			D_8006750C(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC93:
			D_800674C0(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC94:
			D_80067474(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC95:
			D_80067428(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC96:
			D_800673DC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC97:
			D_80067390(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC98:
			D_80067344(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC99:
			D_800672F8(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC100:
			D_800672AC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERIC101:	D_80067260(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC102:	D_80067214(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC103:	D_800671C8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC104:	D_8006717C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC105:	D_80067130(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC106:	D_800670E4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC107:	D_80067098(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC108:	D_8006704C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC109:	D_80067000(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC110:	D_80066FB4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC111:	D_80066F68(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC112:	D_80066F1C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC113:	D_80066ED0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC114:	D_80066E84(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC115:	D_80066E38(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC116:	D_80066DEC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC117:	D_80066DA0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC118:	D_80066D54(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC119:	D_80066D08(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC120:	D_80066CBC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC121:	D_80066C70(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC122:	D_80066C24(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC123:	D_80066BD8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC124:	D_80066B8C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC125:	D_80066B40(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC126:	D_80066AF4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC127:	D_80066AA8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC128:	D_80066A5C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC129:	D_80066A10(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC130:	D_800669C4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC131:	D_80066978(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC132:	D_8006692C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC133:	D_800668E0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC134:	D_80066894(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC135:	D_80066848(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC136:	D_800667FC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC137:	D_800667B0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC138:	D_80066764(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC139:	D_80066718(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC140:	D_800666CC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC141:	D_80066680(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC142:	D_80066634(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC143:	D_800665E8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC144:	D_8006659C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC145:	D_80066550(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC146:	D_80066504(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC147:	D_800664B8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC148:	D_8006646C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC149:	D_80066420(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC150:	D_800663D4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC151:	D_80066388(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC152:	D_8006633C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC153:	D_800662F0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC154:	D_800662A4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC155:	D_80066258(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC156:	D_8006620C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC157:	D_800661C0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC158:	D_80066174(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC159:	D_80066128(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC160:	D_800660DC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC161:	D_80066090(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC162:	D_80066044(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC163:	D_80065FEC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC164:	D_80065FA0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC165:	D_80065F54(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC166:	D_80065F08(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC167:	D_80065EBC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC168:	D_80065E70(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC169:	D_80065E24(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC170:	D_80065DD8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC171:	D_80065D8C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC172:	D_80065D40(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC173:	D_80065CF4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC174:	D_80065CA8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC175:	D_80065C5C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC176:	D_80065C10(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC177:	D_80065BC4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC178:	D_80065B78(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC179:	D_80065B2C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC180:	D_80065AE0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC181:	D_80065A94(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC182:	D_80065A48(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC183:	D_800659FC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC184:	D_800659B0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC185:	D_80065964(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC186:	D_80065918(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC187:	D_800658CC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC188:	D_80065880(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC189:	D_80065834(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC190:	D_800657E8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC191:	D_8006579C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC192:	D_80065750(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC193:	D_80065704(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC194:	D_800656B8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC195:	D_8006566C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC196:	D_80065620(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC197:	D_800655D4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC198:	D_80065588(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC199:	D_8006553C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC200:	D_800654F0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC201:	D_800654A4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC202:	D_80065458(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC203:	D_8006540C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC204:	D_800653C0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC205:	D_80065374(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC206:	D_80065328(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC207:	D_800652DC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC208:	D_80065290(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC209:	D_80065244(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC210:	D_800651F8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC211:	D_800651AC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC212:	D_80065160(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC213:	D_80065114(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC214:	D_800650C8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC215:	D_8006507C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC216:	D_80065030(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC217:	D_80064FE4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC218:	D_80064F98(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC219:	D_80064F4C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC220:	D_80064F00(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC221:	D_80064EB4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC222:	D_80064E68(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC223:	D_80064E1C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC224:	AI_SEvent_Generic224(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC225:	D_80064CC8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC226:	D_80064C7C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC227:	D_80064C30(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC228:	D_80064BE4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC229:	D_80064B98(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC230:	D_80064B4C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC231:	D_80064B00(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC232:	D_80064AB4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC233:	D_80064A68(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC234:	D_80064A1C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC235:	D_800649D0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC236:	D_80064984(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC237:	D_80064938(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC238:	D_800648EC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC239:	D_800648A0(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC240:	D_80064854(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC241:	D_80064808(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC242:	D_800647BC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC243:	D_80064770(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC244:	D_80064724(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC245:	D_800646D8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC246:	D_8006468C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC247:	D_80064640(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC248:	AI_SEvent_Generic248(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC249:	D_80064590(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC250:	D_80064544(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC251:	D_800644F8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC252:	D_800644AC(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC253:	D_80064460(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC254:	D_80064414(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC255:	D_800643C8(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC256:	D_8006437C(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC257:	D_80064330(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC258:	D_800642E4(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC259:	D_80064298(pThis, vPos, Value);	break;
		case AI_SEVENT_GENERIC260:	D_8006424C(pThis, vPos, Value);	break;

		case AI_SEVENT_PLASMA2_PARTICLE:
			AI_SEvent_Plasma2Particle ( pThis, vPos, Value );
			break;

		case AI_SEVENT_WATER_BUBBLE:
			AI_SEvent_Water_Bubble(pThis, vPos, Value);
			break;

		case AI_SEVENT_WATER_RIPPLE:
			D_800640DC(pThis, vPos, Value);
			break;

		case AI_SEVENT_WATER_SPLASH:
			D_80064090(pThis, vPos, Value);
			break;

		case AI_SEVENT_DOOR_ALLOWENTRY:
			DoorAI_SEvent_AllowBlockEntry(pThis, vPos, TRUE);
			break;

		case AI_SEVENT_DOOR_BLOCKENTRY:
			DoorAI_SEvent_AllowBlockEntry(pThis, vPos, FALSE);
			break;

		case AI_SEVENT_GENERATE_PICKUPS:
			AI_SEvent_GeneratePickups(pThis, vPos);
			break;

		case AI_SEVENT_GENERATE_PICKUP:
			AI_SEvent_Generate_Pickup(pThis, vPos, Value);
			break;

		case AI_SEVENT_MAKE_INVISIBLE:
			D_80063BEC(pThis, vPos, Value);
			break;

		case AI_SEVENT_GENERAL_SOUND:
/*
			if (	(pThis)
				&&	(AI_GetDyn((CGameObjectInstance *)pThis)->m_dwStatusFlags2	& AI_IGNORESOUNDEVENTS))
			{
				break ;
			}
			else
*/
			AI_SEvent_GeneralSound(pThis, vPos, Value);
			break;

		case AI_SEVENT_SWOOSH_ALL_HANDS:
			AI_SEvent_SwooshAllHands(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_LEFT_HAND:
			D_80042B40(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_RIGHT_HAND:
			D_80042B8C(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_ALL_FEET:
			D_80042C00(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_LEFT_FOOT:
			D_80042D9C(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_RIGHT_FOOT:
			D_80042E10(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_WEAPON1:
			AI_SEvent_SwooshWeapon1(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_WEAPON2:
			D_80042EF8(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_TAIL:
			D_80042F44(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_LEFT_TOES:
			D_80042F90(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_SWOOSH_RIGHT_TOES:
			D_80042FDC(pThis, vPos, Value) ;
			break ;

		case AI_SEVENT_NEXT_CINEMATIC_STAGE:
			GetApp()->m_Camera.m_NextCinematicStage = TRUE ;
			break ;

		case AI_SEVENT_BOUNCY_ROCK:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_ROCK);
			break ;
		case AI_SEVENT_BOUNCY_ALIEN_HEAD:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_ALIEN_HEAD);
			break ;
		case AI_SEVENT_BOUNCY_ALIEN_HAND:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_ALIEN_HAND);
			break ;
		case AI_SEVENT_BOUNCY_ALIEN_FOOT:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_ALIEN_FOOT);
			break ;
		case AI_SEVENT_BOUNCY_ALIEN_TORSO:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_ALIEN_TORSO);
			break ;
		case AI_SEVENT_BOUNCY_LEAPER_HEAD:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_LEAPER_HEAD);
			break ;
		case AI_SEVENT_BOUNCY_LEAPER_HAND:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_LEAPER_HAND);
			break ;
		case AI_SEVENT_BOUNCY_LEAPER_FOOT:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_LEAPER_FOOT);
			break ;
		case AI_SEVENT_BOUNCY_LEAPER_TORSO:
			AI_SEvent_GenerateBouncy(pThis, vPos, AI_OBJECT_BOUNCY_LEAPER_TORSO);
			break ;

		case AI_SEVENT_INSTANTDEATH:
			AI_SEvent_InstantDeath(pThis);
			break;

		case AI_SEVENT_RANDOM_BIG_SWOOSH_SOUND:
			AI_SEvent_RandBigSwooshSnd(pThis,vPos,Value) ;
			break ;

		case AI_SEVENT_RANDOM_SMALL_SWOOSH_SOUND:
			AI_SEvent_RandSmallSwooshSnd(pThis,vPos,Value) ;
			break ;

		case AI_SEVENT_RANDOM_GRUNT_SOUND:
			AI_SEvent_RandGruntSnd(pThis,vPos,Value) ;
			break ;

		case AI_SEVENT_START_FIRE_SOUND:
			AI_SEvent_StartFireSound(pThis,vPos,Value) ;
			break ;
		case AI_SEVENT_STOP_FIRE_SOUND:
			func_8005EE28(pThis,vPos,Value) ;
			break ;
	}
}

