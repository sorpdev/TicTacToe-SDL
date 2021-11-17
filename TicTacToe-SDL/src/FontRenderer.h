#pragma once
#include <SDL.h>
#include <SDL_ttf.h>

namespace Font
{
	static TTF_Font* Font;
}

class FontRenderer
{
public:
	static void LoadFont(const char* file, int size);
	static void RenderFont(SDL_Renderer* renderer, const char* text, int x, int y);
};
