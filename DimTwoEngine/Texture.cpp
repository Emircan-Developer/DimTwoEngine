#include "Texture.h"
#include <iostream>
void Texture::CreatePlayer(const char* ImgWay,SDL_Renderer* sdlRenderer,int x,int y){
	 SDL_Surface* surface = IMG_Load(ImgWay);
	 if (!surface) {
		 std::cout << "Error while openning File : Error is a : " << SDL_GetError()<< std::endl;

	 }
	 playerTexture = SDL_CreateTextureFromSurface(sdlRenderer,surface);
	 
	 SDL_FreeSurface(surface);
	 std::cout << surface << std::endl;
	 this->x = x;
	 this->y = y;
}

void Texture::Render(SDL_Renderer* renderer,int sourcePoint,int destinationPoint)
{
	

	SDL_RenderCopy(renderer,playerTexture,&sourceRect,&destinationRect);
}

void Texture::Update()
{

	x+= 1;
	y+= 1;
	sourceRect.h = 32;
	sourceRect.w = 32;

	sourceRect.y = 0;
	sourceRect.x = 0;

	destinationRect.x = x;
	destinationRect.y = y;

	destinationRect.w = sourceRect.w * 2;
	destinationRect.h = sourceRect.h * 2;
}
