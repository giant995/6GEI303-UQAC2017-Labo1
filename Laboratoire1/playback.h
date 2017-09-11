#pragma once

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
	IMediaSeeking * seek;

	HRESULT result;
	PlaybackState state;

	HRESULT OnChar(char ch);

	HRESULT PlayPause();
	HRESULT FastForward();
	HRESULT Restart();
	HRESULT Stop();
	HRESULT Help();

	HRESULT InitCOM();
	HRESULT InitGraph();
	HRESULT QueryInterface();
	HRESULT BuildGraph(LPCWSTR filePath);
	HRESULT RunGraph();

public:
	Playback();
	~Playback();

	void RunVideo(LPCWSTR filePath);
};