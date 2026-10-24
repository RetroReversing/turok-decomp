#include "common.h"

typedef unsigned short SF;
extern float func_8001F298(SF sfValue);
float func_8001F298(SF sfValue);
float func_8001F298(SF sfValue){
 unsigned long dwValue = sfValue << 16;
 return *((float*) (&dwValue));
}
