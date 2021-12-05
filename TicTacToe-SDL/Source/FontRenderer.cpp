#include "FontRenderer.h"

void FontRenderer::LoadFont(const char* file, const int size)
{
	Font::Font = TTF_OpenFont(file, size);
}


void FontRenderer::RenderFont(SDL_Renderer* renderer, const char* text, const int x, const int y)
{
	constexpr SDL_Color color = {0, 0, 0};
	SDL_Surface* surface = TTF_RenderText_Solid(Font::Font, text, color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

	//Render text
	const SDL_Rect rect{x, y, surface->w, surface->h};
	SDL_RenderCopy(renderer, texture, nullptr, &rect);

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}
