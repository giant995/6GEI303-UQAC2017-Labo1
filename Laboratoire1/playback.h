# pragma once

#include <dshow.h>

enum PlaybackState
{
	STATE_NO_GRAPH,
	STATE_RUNNING,
	STATE_PAUSED,
	STATE_STOPPED,
};

class Playback
{
private:
	IGraphBuilder * graph;
	IMediaControl * control;
	IMediaEvent   * event;

	HRESULT result;

	HRESULT Play();
	HRESULT Pause();
	HRESULT FastForward();
	HRESULT Restart();
	HRESULT Stop();

public:
	Playback();
	~Playback();

	HRESULT InitCOM();
	HRESULT InitGraph();
	HRESULT QueryInterface();
	HRESULT BuildGraph(LPCWSTR filePath);
	HRESULT RunGraph();
	void Cleanup();
};