/*******************************************************************************

	Laboratoire 1 - Architectures des logiciels

	(c) Jeremy Bouchard	- jeremy.bouchard1@uqac.ca
		Emile Belanger	- emile.belanger1@uqac.ca 

*******************************************************************************/

#include "playback.h"

#pragma comment(lib, "Strmiids.lib")

int main(int argc, char * argv[])
{
	Playback Playback;

	Playback.RunVideo(L"C:\\users\\mukki\\Downloads\\Example.avi");

	return 0;
}
