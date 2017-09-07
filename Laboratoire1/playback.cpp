#include <dshow.h>
#include "playback.h"

Playback::Playback()
{
	IGraphBuilder * graph = NULL;
	IMediaControl * control = NULL;
	IMediaEvent   * event = NULL;

	HRESULT result = NULL;
}

Playback::~Playback()
{
	
}

HRESULT Playback::InitCOM()
{
	result = CoInitialize(NULL);

	if (FAILED(result))
	{
		printf("ERROR - Could not initialize the COM library\n");
	}

	if (SUCCEEDED(result))
	{
		printf("SUCCESS - COM library initialized\n");
	}

	return result;
}

HRESULT Playback::InitGraph()
{
	result = CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
		IID_IGraphBuilder, (void **)&graph);

	if (FAILED(result))
	{
		printf("ERROR - Could not create the Filter Graph Manager\n");
	}

	if (SUCCEEDED(result))
	{
		printf("SUCCESS - Filter Graph Manager created\n");
	}

	return result;
}

HRESULT Playback::QueryInterface()
{
	result = graph->QueryInterface(IID_IMediaControl, (void **)&control);

	if (FAILED(result))
	{
		printf("ERROR - Could not query the interface\n");
	}

	result = graph->QueryInterface(IID_IMediaEvent, (void **)&event);

	if (FAILED(result))
	{
		printf("ERROR - Could not create the Filter Graph Manager\n");
	}

	if (SUCCEEDED(result))
	{
		printf("SUCCESS - Interface successufully queried\n");
	}

	return result;
}

HRESULT Playback::BuildGraph(LPCWSTR filePath)
{
	result = graph->RenderFile(filePath, NULL);

	if (FAILED(result))
	{
		printf("ERROR - Could not build the graph\n");
	}

	if (SUCCEEDED(result))
	{
		printf("SUCCESS - Graph successfully generated\n");
	}

	return result;
}

HRESULT Playback::RunGraph()
{

	if (FAILED(result))
	{
		printf("ERROR - Could not run the graph\n");
	}

	if (SUCCEEDED(result))
	{
		printf("SUCCESS - Running the graph\n");

		result = control->Run();

		if (FAILED(result))
		{
			printf("ERROR - The run failed to complete\n");
		}

		if (SUCCEEDED(result))
		{
			printf("SUCCESS - The run was successufully started\n");

			printf("INFO - Waiting for event completion\n");

			long evCode;
			event->WaitForCompletion(INFINITE, &evCode);

			// Note: Do not use INFINITE in a real application, because it
			// can block indefinitely.
		}
	}

	printf("INFO - Event completed\n");

	return result;
}

void Playback::Cleanup()
{
	control->Release();
	event->Release();
	graph->Release();
	CoUninitialize();

	printf("SUCCESS - Cleanup successufully executed\n");
}

HRESULT Playback::Play()
{
	return E_NOTIMPL;
}

HRESULT Playback::Pause()
{
	return E_NOTIMPL;
}

HRESULT Playback::FastForward()
{
	return E_NOTIMPL;
}

HRESULT Playback::Restart()
{
	return E_NOTIMPL;
}

HRESULT Playback::Stop()
{
	return E_NOTIMPL;
}
