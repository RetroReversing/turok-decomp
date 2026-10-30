#include "common.h"

extern void guMtxIdentF(float *);
void guOrthoF(float m[4][4], float l, float r, float b, float t, float n, float f, float scale)
{
  register float dx;
  register float new_var;
  register float dy;
  register float dz;
  register int i; register int j;
  guMtxIdentF(&m[0][0]);
  dx = r - l;
  dy = t - b;
  m[0][0] = 2.0f / dx;
  dz = f - n;
  m[1][1] = 2.0f / dy;
  m[2][2] = (-2.0f) / dz;
  new_var = (-(t + b)) / dy;
  m[3][0] = (-(r + l)) / dx;
  m[3][1] = new_var;
  m[3][2] = (-(f + n)) / dz;
  m[3][3] = 1.0f;
  for (i = 0; i < 4; i++)
  {
    for(j=0;j<4;j++) m[i][j] *= scale;
  }

}
