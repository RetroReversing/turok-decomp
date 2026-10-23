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
extern void func_8008319C(void) ;
extern int D_80128FA0 ;
extern t_GameText D_80128FA8[8] ;
void func_8008319C(void);
void func_8008319C(void){
 int i ;
 D_80128FA0 = 0;
 for (i=0; i<8; i++)
 {
  D_80128FA8[i].Mode = GAMETEXT_NULL ;
  D_80128FA8[i].Id = 0 ;
 }
}
