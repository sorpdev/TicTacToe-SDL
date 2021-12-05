#pragma once
#include <SDL.h>
#include "TextureManager.h"
#include "Event/EventHandler.h"
#include "GameObject.h"
#include "Field.h"
#include "Listener/FieldClickListener.h"
#include "Gameplay/GameplayManager.h"
#include <array>
#include "FontRenderer.h"
#include <string>

class Scene
{
private:
	GameplayManager m_GamePlayManager{};
	mutable bool m_Enabled = false;
public:
	void Activate();
	void Init();
	void Update() const;
	void Render(SDL_Renderer* renderer) const;
	void Destroy();

	void Deactivate() const { m_Enabled = false; }
};
