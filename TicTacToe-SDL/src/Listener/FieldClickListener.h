#pragma once
#include "../Event/EventListener.h"
#include "../Field.h"
#include <Windows.h>
#include "../Gameplay/GameplayManager.h"
#include <array>

class FieldClickListener : public EventListener
{
private:
	GameplayManager* m_GameplayManager;
public:
	FieldClickListener(GameplayManager* gameplayManager)
	{
		m_GameplayManager = gameplayManager;
	}

	void OnEvent(SDL_Event* event) override;
};
