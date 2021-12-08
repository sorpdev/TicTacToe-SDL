#include "EventHandler.h"

static std::map<EventListener*, SDL_EventType> listeners;

void EventHandler::HandleEvents(bool* gameRunning)
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		*gameRunning = false;
		break;
	default:
		ProcessEvent(&event, static_cast<SDL_EventType>(event.type));
		break;
	}
}


void EventHandler::ProcessEvent(SDL_Event* event, SDL_EventType&& eventType)
{
	if (!listeners.empty())
	{
		for (const auto& x : listeners)
		{
			if (x.second == eventType)
			{
				EventListener* listener = x.first;
				listener->OnEvent(event);
			}
		}
	}
}

void EventHandler::AddListener(SDL_EventType&& eventType, EventListener* listener)
{
	listeners.insert(std::pair<EventListener*, SDL_EventType>{listener, eventType});
}
