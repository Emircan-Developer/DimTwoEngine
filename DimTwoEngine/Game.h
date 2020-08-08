#pragma once
#define SDL_MAIN_HANDLED
#include "Librarys/SDL_IMAGES/include/SDL_image.h"

#include "Librarys/SDL2/include/SDL.h"

#include <iostream>
class Game
{
public:
	~Game();
	Game();
	void init(const char* WindowName,int posX,int posY,int Width,int Height,bool Fullscreen);
	void update();
	void render();
	void clear();
	void EventHandle();

	bool isRunning() {
		return Running;
	}
private:
	SDL_Event event;
	bool Running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

