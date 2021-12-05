#include "TextureManager.h"

struct SDL_Texture* TextureManager::TextureArray[4] = {nullptr, nullptr, nullptr, nullptr};

SDL_Surface* TextureManager::LoadTextureAsSurface(const char* fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);
	return surface;
}

SDL_Surface* TextureManager::LoadIconAsSurface(const char* fileName)
{
	SDL_RWops* io = SDL_RWFromFile(fileName, "rb");
	if (io != nullptr)
	{
		SDL_Surface* surface = IMG_LoadICO_RW(io);
		return surface;
	}
	return nullptr;
}

SDL_Texture* TextureManager::LoadTexture(SDL_Renderer* renderer, const char* fileName)
{
	SDL_Surface* surface = IMG_Load(fileName);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	return texture;
}

void TextureManager::AddTexture(SDL_Texture* texture, Texture textureType)
{
	//Add texture to TextureArray at index for the texture type
	TextureArray[static_cast<int>(textureType)] = texture;
}
