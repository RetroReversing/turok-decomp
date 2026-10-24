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
extern t_GameText *func_800831E4(char *String) ;
extern t_GameText *func_80083288(char *String, int id) ;
extern int func_800832FC(int id) ;
t_GameText *func_800831E4(char *String);
extern t_GameText *D_80129088 ;
t_GameText *func_80083288(char *String, int id);
int func_800832FC(int id);
t_GameText *func_80083288(char *String, int id){
 if (func_800832FC(id) == 0)
 {
  t_GameText *Active = func_800831E4(String) ;
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
