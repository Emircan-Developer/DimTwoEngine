#include "Game.h"
#include "Texture.h"

bool scale = false;
Game::~Game()
{

}

Game::Game()
{

}
Texture* player = nullptr;
Texture* enemy = nullptr;

void Game::init(const char* WindowName, int posX, int posY, int Width, int Height, bool Fullscreen)
{
	player = new Texture();
	enemy = new Texture();

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subs inited" << std::endl;
		window = SDL_CreateWindow(WindowName,posX,posY,Width,Height,0);
		if (window) {
			std::cout << "Window Created" << std::endl;

		}
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255,255);
			std::cout << "Renderer created" << std::endl;

		}Running = true;

	}

	player->CreatePlayer("./b.png", renderer, 0, 0);
	enemy->CreatePlayer("./Arts/indir.png",renderer,2,4);
	//enemy->CreatePlayer("./b.png", renderer);

}

void Game::update()
{
	player->Update();
	enemy->Update();
	if (scale) {

	}
	else {

	}


}

void Game::render()
{
	SDL_RenderClear(renderer);
	player->Render(renderer,0,10);
	enemy->Render(renderer,0,5);
	SDL_RenderPresent(renderer);

}

void Game::clear()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

void Game::EventHandle()
{
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		Running = false;
		break;
	case SDL_KEYDOWN:
		break;
	default:
		break;
	}


}
