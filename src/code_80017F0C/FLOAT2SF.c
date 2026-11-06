#include "common.h"

typedef unsigned short SF;
extern SF FLOAT2SF(float fValue);
SF FLOAT2SF(float fValue);
SF FLOAT2SF(float fValue){
 return (unsigned short) ((*((unsigned long*) (&fValue))) >> 16);
}
