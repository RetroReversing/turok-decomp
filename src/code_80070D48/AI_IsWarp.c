#include "common.h"

extern int AI_IsWarp (int nType);
int AI_IsWarp(int nType);
int AI_IsWarp(int nType){
 return ((nType >= 600) && (nType <= 600));
}
