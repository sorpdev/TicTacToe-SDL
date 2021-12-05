#pragma once
#include <SDL.h>
#include <SDL_image.h>

class TextureManager
{
public:
	static SDL_Texture* LoadTexture(SDL_Renderer* renderer, const char* fileName);

	enum class Texture
	{
		Field = 0,
		Cross = 1,
		Circle = 2,
		Text = 3
	};

	static SDL_Texture* TextureArray[4];
	static SDL_Surface* LoadTextureAsSurface(const char* fileName);
	static SDL_Surface* LoadIconAsSurface(const char* fileName);

	static void AddTexture(SDL_Texture* texture, Texture textureType);
};
