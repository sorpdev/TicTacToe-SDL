#pragma once
#include <SDL.h>

class GameObject
{
public:
	float X = 0;
	float Y = 0;
	float W = 0;
	float H = 0;
	SDL_Texture* Texture;
	GameObject* Child = nullptr;

	GameObject(SDL_Texture* texture, const float x, const float y, const float w, const float h)
	{
		this->Texture = texture;
		this->X = x;
		this->Y = y;
		this->H = h;
		this->W = w;
	}

	~GameObject()
	{
		//Destroy child if existing
		delete Child;
	}

	void Update();
	void Render(SDL_Renderer* renderer) const;

	void SetChild(GameObject* child)
	{
		Child = child;
	}

	bool IsInBounds(int x, int y) const;
};
