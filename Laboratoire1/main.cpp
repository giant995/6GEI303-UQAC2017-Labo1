// For infos and legals, see EOF

#include <dshow.h>
#include "playback.h"

#pragma comment(lib, "Strmiids.lib")

int main(int argc, char * argv[])
{
	Playback Playback;

	Playback.InitCOM();
	Playback.InitGraph();
	Playback.QueryInterface();
	Playback.BuildGraph(L"C:\\users\\mukki\\Downloads\\Example.avi");
	Playback.RunGraph();

	return 0;
}

/*******************************************************************************

	Laboratoire 1 - Architectures des logiciels

	(c) Jeremy Bouchard	- jeremy.bouchard1@uqac.ca
		Emile Belanger	- emile.belanger1@uqac.ca 

*******************************************************************************/