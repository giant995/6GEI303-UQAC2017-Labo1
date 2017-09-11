#include <conio.h>
#include "playback.h"

Playback::Playback()
{
	IGraphBuilder * graph = NULL;
	IMediaControl * control = NULL;
	IMediaEvent   * event = NULL;
	IMediaSeeking * seek = NULL;

	HRESULT result = NULL;

	PlaybackState state = STATE_NO_GRAPH;

	InitCOM();
	InitGraph();
	QueryInterface();
}

Playback::~Playback()
{
	control->Release();
	event->Release();
	graph->Release();
	CoUninitialize();
}

void Playback::RunVideo(LPCWSTR filePath)
{
	BuildGraph(filePath);
	RunGraph();
}

HRESULT Playback::InitCOM()
{
	result = CoInitialize(NULL);

	if (FAILED(result))
	{
		printf("ERROR - Could not initialize the COM library\n");
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

	return result;
}

HRESULT Playback::QueryInterface()
{
	result = graph->QueryInterface(IID_IMediaControl, (void **)&control);

	if (FAILED(result))
	{
		printf("ERROR - Could not query the control\n");
	}

	result = graph->QueryInterface(IID_IMediaEvent, (void **)&event);

	if (FAILED(result))
	{
		printf("ERROR - Could not create the event\n");
	}

	result = graph->QueryInterface(IID_IMediaSeeking, (void **)&seek);

	if (FAILED(result))
	{
		printf("ERROR - Could not create the seek\n");
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
		state = STATE_STOPPED;
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
		result = control->Run();

		if (FAILED(result))
		{
			printf("ERROR - The run failed to complete\n");
		}

		if (SUCCEEDED(result))
		{
			state = STATE_RUNNING;

			long evCode;

			while (state != STATE_STOPPED) {
				int ch = _getch();
				if (ch)
				{
					OnChar(ch);
				}

				event->WaitForCompletion(1, &evCode);
			}

			// Note: Do not use INFINITE in a real application, because it
			// can block indefinitely.
		}
	}

	return result;
}

HRESULT Playback::OnChar(char ch)
{
	switch (ch) {
		case 'p':
		case 'P':
			return PlayPause();

		case 'a':
		case 'A':
			return FastForward();

		case 'r':
		case 'R':
			return Restart();

		case 'q':
		case 'Q':
			return Stop();

		case 'h':
		case 'H':
			return Help();

		default:
			printf("Please use a valid action! or type 'h' for help!\n");
			return -1;
	}
}

HRESULT Playback::PlayPause()
{
	if (state == STATE_RUNNING)
	{
		result = control->Pause();

		if (FAILED(result))
		{
			printf("ERROR - Could not pause the video\n");
		}

		if (SUCCEEDED(result))
		{
			state = STATE_PAUSED;
		}

		return result;
	}
		
	if (state == STATE_PAUSED)
	{
		result = control->Run();

		if (FAILED(result))
		{
			printf("ERROR - Could not run the video\n");
		}

		if (SUCCEEDED(result))
		{
			state = STATE_RUNNING;
		}

		return result;
	}

	if (state == STATE_STOPPED)
	{
		printf("ERROR - Wrong state while executing PlayPause()\n");
		result = VFW_E_WRONG_STATE;
	}
}

HRESULT Playback::FastForward()
{
	double rate;
	seek->GetRate(&rate);

	if (rate == 1.0)
	{
		result = seek->SetRate(2.0);

		if (FAILED(result))
		{
			printf("ERROR - Could not set the rate to 2.0\n");
		}

		return result;
	}

	if (rate == 2.0)
	{
		result = seek->SetRate(1.0);

		if (FAILED(result))
		{
			printf("ERROR - Could not set the rate to 1.0\n");
		}

		return result;
	}
}

HRESULT Playback::Restart()
{
	printf("Restart\n");
	return E_NOTIMPL;
}

HRESULT Playback::Stop()
{
	printf("Stop\n");
	return E_NOTIMPL;
}

HRESULT Playback::Help()
{
	printf("Help\n");
	return E_NOTIMPL;
}