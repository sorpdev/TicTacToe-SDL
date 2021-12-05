#pragma once
#include <SDL.h>

class EventListener
{
public:
	virtual ~EventListener() = default;

	virtual void OnEvent(SDL_Event* event)
	{
	}
};
