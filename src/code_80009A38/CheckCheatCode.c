#include "common.h"

typedef unsigned long sa_u32;
extern char D_800B81D0[32];
typedef struct s_cheatcode
{
 char *string ;
 int length ;
 char *code ;
 sa_u32 flags ;
} t_cheatcode ;
extern t_cheatcode D_800B8484[];
int CheckCheatCode(int numb);
int CheckCheatCode(int numb){
 int c ;
 for (c=0; c<D_800B8484[numb].length; c++)
 {
  if (D_800B81D0[c] != D_800B8484[numb].code[c])
   return 0 ;
 }
 return 1 ;
}
