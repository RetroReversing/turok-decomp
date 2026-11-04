#include "decompdecomp_sync_a717874fdbea6adf5f71.h"
#line 1 "func.c"
#line 1615 "reference.c"
void CPause__DrawBar(Gfx **ppDLP, float x, float y, float w, float h, float a)
{
	Vtx 			*vtxs ;
	float			fade ;
	float			h1, h2 ;
	float			r1, g1, b1 ;
	float			r2, g2, b2 ;
	float			r1a, g1a, b1a ;
	float			r1b, g1b, b1b ;
	int			vertex,
					i;
	float			blend, t1, t2 ;

	vtxs = D_80129140[D_800B6AF4];
	vertex = D_801293A8 ;

	fade = w/3 ;			// xoffset for fading alpha

	h1 = (h/3) ;			// yoffsets for fading alphas
	h2 = h-(h/3) ;

     
                                           
                                           
                                              
            
      

	D_800EC0C0 += .06 * D_800B6B00 ;
	if (D_800EC0C0 >2)
		D_800EC0C0 -= 2 ;

	if (D_800EC0C0 >1)
		blend = 2-D_800EC0C0 ;
	else
		blend = D_800EC0C0 ;

	r1 = BlendFLOAT(blend, 128, 128/2) ;
	g1 = BlendFLOAT(blend, 80, 80/2) ;
	b1 = BlendFLOAT(blend, 80, 80/2) ;
	r2 = BlendFLOAT(blend, 128, 128/2) ;
	g2 = BlendFLOAT(blend, 128, 128/2) ;
	b2 = BlendFLOAT(blend, 60, 60/2) ;

	t1 = h1/h ;
	t2 = h2/h ;
	r1a = BlendFLOAT(t1, r1, r2) ;
	g1a = BlendFLOAT(t1, g1, g2) ;
	b1a = BlendFLOAT(t1, b1, b2) ;
	r1b = BlendFLOAT(t2, r1, r2) ;
	g1b = BlendFLOAT(t2, g1, g2) ;
	b1b = BlendFLOAT(t2, b1, b2) ;




	// top left
	vtxs[D_801293A8].v.ob[0] = x ;
	vtxs[D_801293A8].v.ob[1] = y ;
	vtxs[D_801293A8].v.cn[0] = r1 ;
	vtxs[D_801293A8].v.cn[1] = g1 ;
	vtxs[D_801293A8].v.cn[2] = b1 ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// top mid left
	vtxs[D_801293A8].v.ob[0] = x+fade ;
	vtxs[D_801293A8].v.ob[1] = y ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT(fade/w, r1, r2) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT(fade/w, g1, g2) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT(fade/w, b1, b2) ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// top mid right
	vtxs[D_801293A8].v.ob[0] = x+w-fade ;
	vtxs[D_801293A8].v.ob[1] = y ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT((w-fade)/w, r1, r2) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT((w-fade)/w, g1, g2) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT((w-fade)/w, b1, b2) ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// top right
	vtxs[D_801293A8].v.ob[0] = x+w ;
	vtxs[D_801293A8].v.ob[1] = y ;
	vtxs[D_801293A8].v.cn[0] = r2 ;
	vtxs[D_801293A8].v.cn[1] = b2 ;
	vtxs[D_801293A8].v.cn[2] = g2 ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 


	
	// top2 left
	vtxs[D_801293A8].v.ob[0] = x ;
	vtxs[D_801293A8].v.ob[1] = y+h1 ;
	vtxs[D_801293A8].v.cn[0] = r1a ;
	vtxs[D_801293A8].v.cn[1] = g1a ;
	vtxs[D_801293A8].v.cn[2] = b1a ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// top2 mid left
	vtxs[D_801293A8].v.ob[0] = x+fade ;
	vtxs[D_801293A8].v.ob[1] = y+h1 ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT(fade/w, r1a, r1b) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT(fade/w, g1a, g1b) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT(fade/w, b1a, b1b) ;
	vtxs[D_801293A8].v.cn[3] = 255 *a;
	D_801293A8++ ; 

	// top2 mid right
	vtxs[D_801293A8].v.ob[0] = x+w-fade ;
	vtxs[D_801293A8].v.ob[1] = y+h1 ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT((w-fade)/w, r1a, r1b) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT((w-fade)/w, g1a, g1b) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT((w-fade)/w, b1a, b1b) ;
	vtxs[D_801293A8].v.cn[3] = 255 *a;
	D_801293A8++ ; 

	// top2 right
	vtxs[D_801293A8].v.ob[0] = x+w ;
	vtxs[D_801293A8].v.ob[1] = y+h1 ;
	vtxs[D_801293A8].v.cn[0] = r1b ;
	vtxs[D_801293A8].v.cn[1] = b1b ;
	vtxs[D_801293A8].v.cn[2] = g1b ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 



	// top3 left
	vtxs[D_801293A8].v.ob[0] = x ;
	vtxs[D_801293A8].v.ob[1] = y+h2 ;
	vtxs[D_801293A8].v.cn[0] = r1b ;
	vtxs[D_801293A8].v.cn[1] = g1b ;
	vtxs[D_801293A8].v.cn[2] = b1b ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// top3 mid left
	vtxs[D_801293A8].v.ob[0] = x+fade ;
	vtxs[D_801293A8].v.ob[1] = y+h2 ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT(fade/w, r1b, r1a) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT(fade/w, g1b, g1a) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT(fade/w, b1b, b1a) ;
	vtxs[D_801293A8].v.cn[3] = 255 *a;
	D_801293A8++ ; 

	// top3 mid right
	vtxs[D_801293A8].v.ob[0] = x+w-fade ;
	vtxs[D_801293A8].v.ob[1] = y+h2 ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT((w-fade)/w, r1b, r1a) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT((w-fade)/w, g1b, g1a) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT((w-fade)/w, b1b, b1a) ;
	vtxs[D_801293A8].v.cn[3] = 255 *a;
	D_801293A8++ ; 

	// top3 right
	vtxs[D_801293A8].v.ob[0] = x+w ;
	vtxs[D_801293A8].v.ob[1] = y+h2 ;
	vtxs[D_801293A8].v.cn[0] = r1a ;
	vtxs[D_801293A8].v.cn[1] = b1a ;
	vtxs[D_801293A8].v.cn[2] = g1a ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 




	// bottom left
	vtxs[D_801293A8].v.ob[0] = x ;
	vtxs[D_801293A8].v.ob[1] = y+h ;
	vtxs[D_801293A8].v.cn[0] = r2 ;
	vtxs[D_801293A8].v.cn[1] = g2 ;
	vtxs[D_801293A8].v.cn[2] = b2 ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// bottom mid left
	vtxs[D_801293A8].v.ob[0] = x+fade ;
	vtxs[D_801293A8].v.ob[1] = y+h ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT(fade/w, r2, r1) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT(fade/w, g2, b1) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT(fade/w, b2, g1) ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// bottom mid right
	vtxs[D_801293A8].v.ob[0] = x+w-fade ;
	vtxs[D_801293A8].v.ob[1] = y+h ;
	vtxs[D_801293A8].v.cn[0] = BlendFLOAT((w-fade)/w, r2, r1) ;
	vtxs[D_801293A8].v.cn[1] = BlendFLOAT((w-fade)/w, g2, g1) ;
	vtxs[D_801293A8].v.cn[2] = BlendFLOAT((w-fade)/w, b2, b1) ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	// bottom right
	vtxs[D_801293A8].v.ob[0] = x+w ;
	vtxs[D_801293A8].v.ob[1] = y+h ;
	vtxs[D_801293A8].v.cn[0] = r1 ;
	vtxs[D_801293A8].v.cn[1] = g1 ;
	vtxs[D_801293A8].v.cn[2] = b1 ;
	vtxs[D_801293A8].v.cn[3] = 0 ;
	D_801293A8++ ; 

	gSPVertex((*ppDLP)++,
     			 RSP_ADDRESS(vtxs),
     			 D_801293A8, 0);

	for (i=0; i<3; i++)
	{
		gSP2Triangles((*ppDLP)++,
						  vertex+0, vertex+1, vertex+4, 0,
						  vertex+1, vertex+5, vertex+4, 0);
		gSP2Triangles((*ppDLP)++,
						  vertex+1, vertex+2, vertex+5, 0,
						  vertex+2, vertex+6, vertex+5, 0);
		gSP2Triangles((*ppDLP)++,
						  vertex+2, vertex+3, vertex+6, 0,
						  vertex+3, vertex+7, vertex+6, 0);

		vertex += 4;
	}
}

