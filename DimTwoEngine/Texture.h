#pragma once
#include "SDL.h"
#include "SDL_image.h"
class Texture {
public:
	void CreatePlayer(const char* ImgWay, SDL_Renderer* sdlRenderer,int x,int y);
	void Render(SDL_Renderer* renderer, int sourcePoint, int destinationPoint);
	void Update();
private:
	int x, y;
	SDL_Rect sourceRect, destinationRect;
	SDL_Texture* playerTexture;
};