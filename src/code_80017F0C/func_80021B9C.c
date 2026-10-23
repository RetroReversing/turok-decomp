#include "common.h"

typedef unsigned short SF;
extern SF func_80021B9C(float fValue);
SF func_80021B9C(float fValue);
SF func_80021B9C(float fValue){
 return (unsigned short) ((*((unsigned long*) (&fValue))) >> 16);
}
