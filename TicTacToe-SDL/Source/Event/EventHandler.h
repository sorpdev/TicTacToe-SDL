#pragma once
#include <map>
#include <SDL.h>
#include <utility>
#include "EventListener.h"

class EventHandler
{
private:
	//static std::map<SDL_EventType, void*> Listeners;
	static void ProcessEvent(SDL_Event*, SDL_EventType);
public:
	static void HandleEvents(bool* gameRunning);
	static void AddListener(SDL_EventType, EventListener*);
};
