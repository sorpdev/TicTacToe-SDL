#pragma once
#include "../Event/EventListener.h"
#include "../Field.h"
#include "../Gameplay/GameplayManager.h"
#include <array>

class FieldClickListener : public EventListener
{
private:
	GameplayManager* m_GameplayManager;
	uint32_t m_Cooldown;
public:
	FieldClickListener(GameplayManager* gameplayManager) : m_GameplayManager(gameplayManager)
	{
	}

	void OnEvent(SDL_Event* event) override;
};
