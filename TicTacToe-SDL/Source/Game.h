#pragma once
#include <SDL.h>
#include "Scene.h"
#include "TextureManager.h"
#include "Event/EventHandler.h"
#include <SDL_ttf.h>
#include "FontRenderer.h"
#include "Time.h"

class Game
{
private:
	SDL_Window* m_Window = nullptr;
	SDL_Renderer* m_Renderer = nullptr;
	Scene m_Scene;
	bool m_Running = false;
public:
	Game(const char* title, int x, int y, int w, int h, Uint32 flags);
	~Game();
	void Init();
	void Loop();
	void Update() const;
	void Draw() const;

	bool IsRunning() const;
};
