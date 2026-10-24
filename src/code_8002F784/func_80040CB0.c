#include "common.h"

extern float func_80040CB0(float Phi, float Theta) ;
extern float func_80040C80(float Phi, float Theta) ;
float func_80040C80(float Phi, float Theta);
float func_80040CB0(float Phi, float Theta);
float func_80040CB0(float Phi, float Theta){
 return (((func_80040C80(Phi, Theta)) < 0) ? -(func_80040C80(Phi, Theta)) : (func_80040C80(Phi, Theta))) ;
}
