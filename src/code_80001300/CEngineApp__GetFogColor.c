#include "common.h"
#define TRUE	1
#define FALSE	0

#define BOOL	int
#define BYTE	unsigned char
#define DWORD	unsigned long
#define WORD	unsigned short
#define INT32  signed long
#define UINT32 unsigned long
#define UINT	unsigned long

#define FLOAT	float
#define UINT16 unsigned short
#define INT16	signed short
#define INT8	signed char
#define UINT8	unsigned char



/* Partial retail layout: m_FogColor is independently located by the three original byte loads. */
typedef struct { unsigned char _unknown_00000[0x1F8CC]; BYTE m_FogColor[3]; } CEngineApp;
void CEngineApp__GetFogColor(CEngineApp *pThis, BYTE *pR, BYTE *pG, BYTE *pB)
{
	// mask off bottom 3 bits so background and fog will be the same color
	*pR = pThis->m_FogColor[0] & 0xf8;
	*pG = pThis->m_FogColor[1] & 0xf8;
	*pB = pThis->m_FogColor[2] & 0xf8;
}
