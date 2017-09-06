// For infos and legals, see EOF

#include <dshow.h>

#pragma comment(lib, "Strmiids.lib")

#define BUFFSIZE 256

// Doesn't work
LPCWSTR charToLPCWSTR(char * message) 
{
	wchar_t tempMessage[BUFFSIZE] = {0};
	size_t sizeToCopy = strlen(message) + 1; // Plus null
	size_t charReceived = 0;

	int result = mbstowcs_s(&charReceived, tempMessage, sizeToCopy, message, sizeToCopy);
	if (FAILED(result))
	{
		printf("ERROR - Could not cast char * to LPCWSTR");
	}

	LPCWSTR castedMessage = tempMessage;

	return castedMessage;
};

int main(int argc, char * argv[])
{
	// Pointer to important data structures 
	IGraphBuilder * pGraph = NULL;
	IMediaControl * pControl = NULL;
	IMediaEvent   * pEvent = NULL;

	// Hold results of operations
	HRESULT result = NULL;

	// Initialize the COM library.
	result = CoInitialize(NULL);
	if (FAILED(result))
	{
		printf("ERROR - Could not initialize the COM library");
		return 1;
	}

	// Create the filter graph manager and query for interfaces.
	result = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder, (void **)&pGraph);
	if (FAILED(result))
	{
		printf("ERROR - Could not create the Filter Graph Manager.");
		return 1;
	}

	result = pGraph->QueryInterface(IID_IMediaControl, (void **)&pControl);
	result = pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);

	// Build the graph. IMPORTANT: Change this string to a file on your system.
	LPCWSTR filePath = L"C:\\users\\mukki\\Downloads\\Example.avi";

	result = pGraph->RenderFile(filePath, NULL);
	if (SUCCEEDED(result))
	{
		// Run the graph.
		result = pControl->Run();
		if (SUCCEEDED(result))
		{
			// Wait for completion.
			long evCode;
			pEvent->WaitForCompletion(INFINITE, &evCode);

			// Note: Do not use INFINITE in a real application, because it
			// can block indefinitely.
		}
	}
	pControl->Release();
	pEvent->Release();
	pGraph->Release();
	CoUninitialize();

	return 0;
}

/*******************************************************************************

	Laboratoire 1 - Architectures des logiciels

	(c) Jeremy Bouchard	- jeremy.bouchard1@uqac.ca
		Emile Belanger	- emile.belanger1@uqac.ca 

*******************************************************************************/