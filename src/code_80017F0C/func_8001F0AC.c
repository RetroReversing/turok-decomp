#include "decompdecomp_sync_12290b8fe35ba76471dc.h"
#line 1 "func.c"
#line 2230 "reference.c"
void func_8001F0AC(CGameStaticInstance *pThis, Gfx **ppDLP,
										 CCartCache *pCache, CCacheEntry *pceTextureSetsIndex)
{
	CIndexedSet		isObjectIndex,
						isGeometry,
						isNodes;
	ROMAddress		*rpGeometryAddress;
	DWORD				geometrySize;
	void				*pbNodes;
	CCacheEntry		*pceGeometry;
// TEST
                   
                             
                                      
      

	// Draw in "pickup key" cinema?
	if (    (pThis->ih.m_pEA->m_wTypeFlags3 & AI_TYPE3_DONTDRAWONCINEMA) 
		  && (D_80112C20 == CAMERA_CINEMA_TUROK_PICKUP_KEY_MODE) )
		return ;


	// make sure object index is current
	pThis->m_pceObjectIndex = NULL;

	// request object index
   CCartCache__RequestBlock(pCache,
                            NULL, NULL, NULL,
									 &pThis->m_pceObjectIndex,
                            pThis->m_rpObjectIndexAddress, IS_INDEX_SIZE(CART_GRAPHOBJ_nItems),
                            ((char*)&D_800F0D84));

	if (pThis->m_pceObjectIndex)
	{
		CIndexedSet__ConstructFromRawData(&isObjectIndex,
												 	 CCacheEntry__GetData(pThis->m_pceObjectIndex),
												 	 FALSE);

		// calculate address of geometry
   	rpGeometryAddress = CIndexedSet__GetROMAddressAndSize(&isObjectIndex,
																	  			pThis->m_rpObjectIndexAddress,
																	  			CART_GRAPHOBJ_isGeometry, &geometrySize);

		// pick proper geometry version for lighting
		rpGeometryAddress = (ROMAddress*) ((DWORD) rpGeometryAddress | CACHE_BLOCK_VERSION(pThis->m_dwFlags & STATIC_INSTANCE_GEOMVER_MASK));

		// request geometry data (will be decompressed)
		CGeometry__RequestBlock(&pThis->m_Geometry, pCache,
	  						 			rpGeometryAddress, geometrySize,
										pceTextureSetsIndex);

		pceGeometry = CGeometry__GetCacheEntry(&pThis->m_Geometry);
		if (pceGeometry)
		{
			CIndexedSet__ConstructFromRawData(&isGeometry,
														 CCacheEntry__GetData(pceGeometry),
														 FALSE);

			pbNodes = CIndexedSet__GetAddress(&isGeometry, CART_GEOMETRY_isNodes);
			CIndexedSet__ConstructFromRawData(&isNodes, pbNodes, FALSE);

			// draw static instance
			ASSERT(CIndexedSet__GetBlockCount(&isNodes) == 1); // static instances should have exactly 1 node


                   
       
                      
    
                                               
                                                                                         
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
                                               
                                                                                         
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
                                               
                                                                                         
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
                                               
                                                                                         
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
    
                      
                      
                                               
                                                                                 
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
                                               
                                                                                 
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
                                               
                                                                                 
                                                
                                              

                          
                                        
                                                  

                                                                                                          

                                             
                      
      

			// instance orientation
  			gSPMatrix((*ppDLP)++,
						 RSP_ADDRESS(&pThis->m_mOrientation),
	   				 G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);

			CGeometry__DrawPart(&pThis->m_Geometry, ppDLP, pCache, 0,
									  pThis->ih.m_pEA->m_nModel,
									  !((DrawApp()->m_Mode == MODE_INTRO) || (DrawApp()->m_Mode == MODE_TITLE)/* || (DrawApp()->m_Mode == MODE_LEGALSCREEN)*/),
                  
                
     
									  (DrawApp()->m_bPause) || (DrawApp()->m_Mode == MODE_INTRO) || (DrawApp()->m_Mode == MODE_TITLE) || (DrawApp()->m_Mode == MODE_LEGALSCREEN),
      
									  pThis->ih.m_pEA->m_nTexture);

			CIndexedSet__Destruct(&isGeometry);
			CIndexedSet__Destruct(&isNodes);
		}

		CIndexedSet__Destruct(&isObjectIndex);
	}
}

