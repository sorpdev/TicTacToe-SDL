#include "FieldClickListener.h"

void FieldClickListener::OnEvent(SDL_Event* event)
{
	if (SDL_GetTicks() < m_Cooldown) return;

	if (m_GameplayManager->CurrentPlayer == Player::None)
	{
		m_GameplayManager->RestartGame();
		m_Cooldown = SDL_GetTicks() + 250;
		return;
	}

	const int mouseX = reinterpret_cast<SDL_MouseButtonEvent*>(event)->x;
	const int mouseY = reinterpret_cast<SDL_MouseButtonEvent*>(event)->y;
	for (const auto& m_Field : m_GameplayManager->GetFields())
	{
		for (const auto field : m_Field)
		{
			//Get clicked field
			if (field->GetGameObject()->IsInBounds(mouseX, mouseY))
			{
				m_GameplayManager->MakeMove(field->Row, field->Col);
				//Check if click triggered a win
				if (m_GameplayManager->Winner != Player::None)
				{
					m_Cooldown = SDL_GetTicks() + 250;
				}
			}
		}
	}
}
