#include "FieldClickListener.h"

void FieldClickListener::OnEvent(SDL_Event* event)
{
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
			}
		}
	}
}
