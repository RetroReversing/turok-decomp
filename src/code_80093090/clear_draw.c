#include "common.h"

typedef unsigned short sa_u16;
extern void clear_draw(void);
extern sa_u16 *D_80130D74;
extern sa_u16 D_800EE068;
void clear_draw(void);
void clear_draw(void){
  int i;
  sa_u16 *r;
  r = D_80130D74;
  for (i = 0; i < 320*2 * 240*2; i ++)
    *r++ = D_800EE068;
}
