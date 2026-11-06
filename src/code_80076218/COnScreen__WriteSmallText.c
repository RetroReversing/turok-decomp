#include "decompdecomp_sync_2421ef00b71489ca5b52.h"
#line 1 "func.c"
#line 2820 "reference.c"
void COnScreen__WriteSmallText(Gfx **ppDLP, char *String, float nX, float nY, float XScale, float YScale)
{
	int	c ;

	while (*String)
	{
		c = *String ;

		if (FontType == SMALL_FONT)
		{
			if (c==' ')
				c = 0;
			else if (c>=0x30 && c<=0x39)
				c -= 0x20 ;
			else if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
				c = (c &0x1f) + 0x19 ;
			else
			{
				switch (c)
				{
					case '!':	c = 0x34 ; break ;
					case '"':	c = 0x35 ; break ;
					case '#':	c = 0x36 ; break ;
					case 0x27:	c = 0x37 ; break ;	// '
					case '*':	c = 0x38 ; break ;
					case '+':	c = 0x39 ; break ;
					case ',':	c = 0x3a ; break ;
					case '-':	c = 0x3b ; break ;
					case '.':	c = 0x3c ; break ;
					case '/':	c = 0x3d ; break ;
					case ':':	c = 0x3e ; break ;
					case '=':	c = 0x3f ; break ;
					case '?':	c = 0x40 ; break ;
					case '@':	c = 0x41 ; break ;
					case '(':	c = 0x0d ; break ;
					case ')':	c = 0x0e ; break ;
					case '{':	c = 0x0b ; break ;
					case '}':	c = 0x0c ; break ;
					case '&':	c = 0x0a ; break ;


					default:		c = 0 ;

				}
			}
			if (c)
				COnScreen__DrawSmallFontTexture(ppDLP, &SmallFont[c*64], nX, nY, XScale, YScale) ;
		}
		// nintendo format
		else
		{
			if ((c > 0x09) && (c!=15) && (c<66))
				COnScreen__DrawSmallFontTexture(ppDLP, &SmallFont[c*64], nX, nY, XScale, YScale) ;
            else if(c != 15)
                COnScreen__DrawSmallFontTexture(ppDLP, D_800C1ED3, nX, nY, XScale, YScale);
		}

  		nX += (8 *XScale);

		String++ ;
	}
}

