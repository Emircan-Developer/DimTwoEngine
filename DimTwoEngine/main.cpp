#include "Game.h"

Game* game = nullptr;
int main() {

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;


	Uint32 frameStart;
	int FrameTime;
	game = new Game();
	game->init("sa",SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,800,600,true);

	while (game->isRunning()) {
		frameStart = SDL_GetTicks();

		game->EventHandle();
		game->update();
		game->render();

		FrameTime = SDL_GetTicks() - frameStart;
			std::cout << FrameTime <<std::endl;
		
		if (frameDelay > FrameTime) {

			SDL_Delay(frameDelay - FrameTime);

		}
	}game->clear();
	return 0;
}
