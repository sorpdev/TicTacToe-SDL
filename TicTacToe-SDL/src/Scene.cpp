#include "Scene.h"


void Scene::Activate()
{
	Init();
	m_Enabled = true;
}


void Scene::Init()
{
	//Register event listeners
	static FieldClickListener fieldClickListener(&m_GamePlayManager);
	EventHandler::AddListener(SDL_MOUSEBUTTONDOWN, &fieldClickListener);

	//Create fields
	m_GamePlayManager.CreatePlayfield();
}


void Scene::Update() const
{
	if (!m_Enabled) return;

	//Update fields
	const auto fields = m_GamePlayManager.GetFields();
	for (const auto& _field : fields)
	{
		for (const auto field : _field)
		{
			field->GetGameObject()->Update();
		}
	}
}

void Scene::Render(SDL_Renderer* renderer) const
{
	if (!m_Enabled) return;

	//Render text
	constexpr SDL_Rect titleRect = {370, 20, 549, 138};
	SDL_RenderCopy(renderer, TextureManager::TextureArray[static_cast<int>(TextureManager::Texture::Text)], nullptr,
	               &titleRect);

	if (m_GamePlayManager.Winner == Player::X)
	{
		FontRenderer::RenderFont(renderer, "X is the winner!", 570, 150);
	}
	else if (m_GamePlayManager.Winner == Player::O)
	{
		FontRenderer::RenderFont(renderer, "O is the winner!", 570, 150);
	}
	else if (m_GamePlayManager.CurrentPlayer == Player::None)
	{
		FontRenderer::RenderFont(renderer, "Draw! No winner!", 570, 150);
	}

	//Render fields
	const auto fields = m_GamePlayManager.GetFields();
	for (const auto& _field : fields)
	{
		for (const auto field : _field)
		{
			field->GetGameObject()->Render(renderer);
		}
	}
}

void Scene::Destroy()
{
	//Destroy gameManager
	m_GamePlayManager.Destroy();
}
