#include "common.h"

extern float func_8008B9B0(float x, signed long y);
float func_8008B9B0(float x, signed long y);
float func_8008B9B0(float x, signed long y){
 register float temp1;
 int j;
 temp1 = 1;
 for(j = 0; j < y; j++)
  temp1 *= x;
 return temp1;
}
