#include "common.h"

extern int AI_IsPickup (int nType);
int AI_IsPickup(int nType);
int AI_IsPickup(int nType){
 return ((nType >= 400) && (nType <= 457));
}
