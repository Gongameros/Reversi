#include "Game.h"
#undef main

Game* game = nullptr;

int main(int argc, const char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;
	game = new Game();
	game->init("Reversi", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 768, 640, false);
	while (game->running())
	{

		frameStart = SDL_GetTicks64();
		game->handleEvents();
		game->update();
		game->render();
		
		frameTime = SDL_GetTicks64() - frameStart;
		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}