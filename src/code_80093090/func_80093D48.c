#include "source_func_80093D48.h"

void func_80093D48(COptions *pThis)
{
	pThis->m_MusicVolume = 180 ;
	pThis->m_SFXVolume = 255;
	pThis->m_Opacity = 184 ;
	pThis->m_HAnalog = 100 ;
	pThis->m_VAnalog = 100 ;
	pThis->m_RHControl = TRUE;


	pThis->m_Blood = BLOOD_RED ;



	GetApp()->m_ActualMusicVolume = ((float)pThis->m_MusicVolume / 255.0);
	GetApp()->m_ActualSFXVolume = ((float)pThis->m_SFXVolume / 255.0);

	pThis->m_OptionsStored = FALSE ;
}
