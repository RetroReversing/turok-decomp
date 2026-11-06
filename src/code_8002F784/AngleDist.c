#include "common.h"

extern float AngleDist(float Phi, float Theta) ;
extern float AngleDiff(float Phi, float Theta) ;
float AngleDiff(float Phi, float Theta);
float AngleDist(float Phi, float Theta);
float AngleDist(float Phi, float Theta){
 return (((AngleDiff(Phi, Theta)) < 0) ? -(AngleDiff(Phi, Theta)) : (AngleDiff(Phi, Theta))) ;
}
