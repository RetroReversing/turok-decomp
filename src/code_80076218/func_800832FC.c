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
extern int func_800832FC(int id) ;
extern t_GameText D_80128FA8[8] ;
extern t_GameText *D_80129088 ;
int func_800832FC(int id);
int func_800832FC(int id){
 int i ;
 t_GameText *active ;
 for (i=0; i<8; i++)
 {
  active = &D_80128FA8[i] ;
  if (active->Mode != GAMETEXT_NULL)
  {
   if (active->Id == id)
   {
    D_80129088 = active ;
    return 1 ;
   }
  }
 }
 return 0 ;
}
