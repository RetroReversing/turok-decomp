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
extern t_GameText *COnScreen__AddGameText(char *String) ;
extern t_GameText *COnScreen__AddGameTextWithId(char *String, int id) ;
extern int COnScreen__SearchForId(int id) ;
t_GameText *COnScreen__AddGameText(char *String);
extern t_GameText *D_80129088 ;
t_GameText *COnScreen__AddGameTextWithId(char *String, int id);
int COnScreen__SearchForId(int id);
t_GameText *COnScreen__AddGameTextWithId(char *String, int id){
 if (COnScreen__SearchForId(id) == 0)
 {
  t_GameText *Active = COnScreen__AddGameText(String) ;
  if (Active)
  {
   Active->Id = id ;
  }
  return Active ;
 }
 else
 {
  D_80129088->Time = 2 ;
  D_80129088->String = String ;
 }
 return ((void*)0) ;
}
