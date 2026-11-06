#include "decompdecomp_sync_3a6c5450f0e703b552aa.h"

void NormalizeRotation(f32 *pTheta){if((f64)*pTheta < -3.14159265358979323846){do{*pTheta=(f64)*pTheta+6.28318530717958647692;}while((f64)*pTheta < -3.14159265358979323846);}if(3.14159265358979323846<=(f64)*pTheta){do{*pTheta=(f64)*pTheta-6.28318530717958647692;}while(3.14159265358979323846<=(f64)*pTheta);}}
