#include "common.h"

typedef unsigned short SF;
extern float SF2FLOAT(SF sfValue);
float SF2FLOAT(SF sfValue);
float SF2FLOAT(SF sfValue){
 unsigned long dwValue = sfValue << 16;
 return *((float*) (&dwValue));
}
