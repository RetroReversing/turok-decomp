#include "common.h"

extern const double D_800F2418;
float func_80040BFC(float Theta);
float func_80040BFC(float Theta)
{
  while (Theta < D_800F2418)
    Theta += 2 * 3.14159265358979323846;

  while (Theta > 3.14159265358979323846)
    Theta -= 2 * 3.14159265358979323846;

  return -Theta;
}
