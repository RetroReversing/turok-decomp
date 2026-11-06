#include "common.h"

extern int AI_IsBouncy (int nType);
int AI_IsBouncy(int nType);
int AI_IsBouncy(int nType){
 return ((nType >= 700) && (nType <= 709));
}
