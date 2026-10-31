#include "common_local_source_3645.h"

#line 76 "reference.c"
void main(void)
{
	u32 TransferLength,Dest;
	u32 DecompFlag;
	u32 *ptr;
	u8	 method;
	//
	// Grab the code file header to check for RNC compression
	//
	func_80000450((u32)_codeSegmentRomStart,(u32)_codeSegmentStart,12);

	DecompFlag = ( (_codeSegmentStart[0]=='R') && (_codeSegmentStart[1]=='N') &&
		 		   (_codeSegmentStart[2]=='C') );
	if ( DecompFlag )
	{
		TransferLength = ((_codeSegmentStart[8])<<24) | ((_codeSegmentStart[9])<<16) |
						 ((_codeSegmentStart[10])<< 8) | (_codeSegmentStart[11]);
		//
		// Round up to nearest word and add on length for header transfers
		//
		TransferLength = (TransferLength+23) & ~3;
		Dest = (u32)_mempoolSegmentStart;
	}
	else
	{
		TransferLength = (u32)_codeSegmentRomEnd - (u32)_codeSegmentRomStart;
		Dest = (u32)_codeSegmentStart;
	}
	//
	// Grab the main body of the file and then decompress if needed
	//
	func_80000450((u32)_codeSegmentRomStart,Dest,TransferLength);

	if ( DecompFlag )
	{
		method = _codeSegmentStart[3];
		if (method == 1)
		{
			Propack_UnpackM1((void *)Dest,_codeSegmentStart);
		}
		else
		{
			Propack_UnpackM2((void *)Dest,_codeSegmentStart);
		}
	}
	//
	// Clear I & D caches, we cheat a little because the O/S should now
	// be alive!
	osInvalICache(_codeSegmentStart, _codeSegmentEnd-_codeSegmentStart);
	osWritebackDCacheAll();


	//
	// Clear out the code area BSS and then call the entry point
	//
	TransferLength = ((u32)_codeSegmentBssEnd-(u32)_codeSegmentBssStart)/4;
	ptr = (u32 *)_codeSegmentBssStart;
	while ( TransferLength-- )
	{
		*ptr++=0x0;
		// *ptr++=0xc9;		// ?
	}

	boot();
}
