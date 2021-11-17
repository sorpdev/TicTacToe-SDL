#include "Game.h"

Game::Game(const char* title, const int x, const int y, const int w, const int h, const Uint32 flags)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		if (TTF_Init() == 0)
		{
			m_Window = SDL_CreateWindow(title, x, y, w, h, flags);
			if (m_Window)
			{
				FontRenderer::LoadFont("assets/arial.ttf", 25);
				m_Renderer = SDL_CreateRenderer(m_Window, -1, 0);
				if (m_Renderer)
				{
					m_Running = true;

					Init();
				}
			}
		}
	}
}

void Game::Init()
{
	//Set icon
	static SDL_Surface* icon = TextureManager::LoadIconAsSurface("icon.ico");
	SDL_SetWindowIcon(m_Window, icon);
	SDL_FreeSurface(icon);

	//Load textures
	static SDL_Texture* fieldTexture = TextureManager::LoadTexture(m_Renderer, "assets/field.png");
	static SDL_Texture* crossTexture = TextureManager::LoadTexture(m_Renderer, "assets/cross.png");
	static SDL_Texture* circleTexture = TextureManager::LoadTexture(m_Renderer, "assets/circle.png");
	static SDL_Texture* textTexture = TextureManager::LoadTexture(m_Renderer, "assets/game_text.png");
	TextureManager::AddTexture(fieldTexture, TextureManager::Texture::Field);
	TextureManager::AddTexture(crossTexture, TextureManager::Texture::Cross);
	TextureManager::AddTexture(circleTexture, TextureManager::Texture::Circle);
	TextureManager::AddTexture(textTexture, TextureManager::Texture::Text);

	//Activate scene
	m_Scene.Activate();
}

void Game::Loop()
{
	Time::Now = 0;
	Time::Last = SDL_GetTicks();
	Time::DeltaTime = 0;

	while (m_Running)
	{
		Time::Now = SDL_GetTicks();
		Time::DeltaTime = static_cast<float>(Time::Now - Time::Last) / 1000;
		Time::Last = Time::Now;

		if (Time::DeltaTime > 1.5f)
			Time::DeltaTime = 1.5f;

		EventHandler::HandleEvents(&m_Running);
		Update();
		Draw();

		SDL_Delay(1);
	}
}

void Game::Update() const
{
	m_Scene.Update();
}


void Game::Draw() const
{
	//Set background color
	SDL_SetRenderDrawColor(m_Renderer, 198, 156, 109, 255);

	//Set scale to 1,1 as default
	SDL_RenderSetScale(m_Renderer, 1, 1);

	SDL_RenderClear(m_Renderer);

	//Render scene
	m_Scene.Render(m_Renderer);

	SDL_RenderPresent(m_Renderer);
}


bool Game::IsRunning() const
{
	return m_Running;
}

Game::~Game()
{
	//Destroy scene
	m_Scene.Destroy();
	//Destroy SDL stuff
	SDL_DestroyWindow(m_Window);
	SDL_DestroyRenderer(m_Renderer);

	TTF_Quit();
	SDL_Quit();
}
