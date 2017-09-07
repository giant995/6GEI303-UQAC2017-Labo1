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
