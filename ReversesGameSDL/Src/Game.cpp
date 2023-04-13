#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Pawn.h"
#include <array>
#include "Algorithms.h"

Map* map;

SDL_Renderer* Game::renderer = nullptr;
static int cntColor = Black;

PawnSet mainSet;

Manager managerMain;

Game::Game(){}

Game::~Game(){}

int UnhidenPawn = -1;

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	
	int flags = 0;

	if (fullscreen)
		flags = SDL_WINDOW_FULLSCREEN; 

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems initialised!..." << std::endl;

		window = SDL_CreateWindow(title,xpos,ypos,width,height,flags);

		if (window)
			std::cout << "Window created!..." << std::endl;

		renderer = SDL_CreateRenderer(window, -1, 0);

		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Render created!..." << std::endl;
		}

		map = new Map();
		mainSet.addPawn();
		mainSet.drawStartPawns();
		isRunning = true;
	}
	else { 
		isRunning = false; 
	}


}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_MOUSEBUTTONDOWN:
			if (event.motion.x >= 128 && event.motion.x <= 640 && event.motion.y >= 64 && event.motion.y <= 576)
			{
				int button_x = event.motion.x;
				int button_y = event.motion.y;
				UnhidenPawn = NumberOfPawn(MultiX(button_x), MultiY(button_y));
				
				if(cntColor==White)
				{ 
					mainSet.pawns[UnhidenPawn]->changeColorWhite();				
					if(RelisedLogic(White, UnhidenPawn) == true)
						cntColor = Black;
				}
				else
				{
					if(RelisedLogic(Black, UnhidenPawn) ==true)
						cntColor = White;
				}

				std::cout << "X: " << button_x << " Y: " << button_y << std::endl;
			}
		default:
			break;

	}
}
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	managerMain.draw();
	SDL_RenderPresent(renderer);
}
void Game::update()
{
	managerMain.update();
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned!..." << std::endl;
}
bool Game::running()
{
	return isRunning;
}