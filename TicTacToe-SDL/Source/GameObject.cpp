#include "GameObject.h"

void GameObject::Update()
{
};


void GameObject::Render(SDL_Renderer* renderer) const
{
	//Render self
	const SDL_Rect rect{static_cast<int>(X), static_cast<int>(Y), static_cast<int>(W), static_cast<int>(H)};
	SDL_RenderCopy(renderer, Texture,
	               nullptr,
	               &rect);

	//Render child
	if (Child) Child->Render(renderer);
}

bool GameObject::IsInBounds(const int& _x, const int& _y) const
{
	return (_x > X && _x < (X + W) && _y > Y && _y < (Y + H));
}
