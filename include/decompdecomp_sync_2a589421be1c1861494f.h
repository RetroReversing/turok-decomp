typedef unsigned short u16;
#define NULL ((void*)0)
void guMtxIdentF(float[4][4]);float sqrtf(float);float sinf(float);float cosf(float);

#define sqrtf sqrtf
#define sinf __sinf
#define cosf __cosf

float sqrtf(float);float __sinf(float);float __cosf(float);
