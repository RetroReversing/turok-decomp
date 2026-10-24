#include "common.h"

typedef struct s_GameText
{
 float Time ;
 float DisplayTime ;
 int Mode ;
 int Alpha ;
 float Scale ;
 char *String ;
 int Id ;
} t_GameText ;
enum GameTextModes
{
 GAMETEXT_NULL,
 GAMETEXT_FADEUP,
 GAMETEXT_DISPLAY,
 GAMETEXT_FADEDOWN
} ;
extern t_GameText *func_800831E4(char *String) ;
extern int D_80128FA0 ;
extern t_GameText D_80128FA8[8] ;
t_GameText *func_800831E4(char *String);
t_GameText *func_800831E4(char *String){
 t_GameText *active ;
 active = &D_80128FA8[D_80128FA0++] ;
 D_80128FA0 &= (8 -1) ;
 active->Mode = GAMETEXT_FADEUP ;
 active->String = String ;
 active->Alpha = 0 ;
 active->Scale = 1.0 ;
 active->DisplayTime = 1*15 ;
 active->Id = 0 ;
 return active ;
}
