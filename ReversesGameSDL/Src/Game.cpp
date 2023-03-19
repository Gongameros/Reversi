#include "Game.h"
#include "TextureManager.h"
#include "Map.h"
#include "ECS/Components.h"
#include "Vector2D.h"
#include "Pawn.h"

Map* map;

static int cnt = 0;
SDL_Renderer* Game::renderer = nullptr;
Manager manager;

Entity& pawn(manager.addEntity());
Entity& pawn2(manager.addEntity());
//std::vector<Entity> pawns;



Game::Game(){}

Game::~Game(){}



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

		isRunning = true;
	}
	else { 
		isRunning = false; 
	}
	map = new Map();
	//pawns[0].addComponent<TransformComponent>();
	//pawns[0].addComponent<SpriteComponent>("assets/pawn.png");
	//pawns[1].addComponent<TransformComponent>(100, 500);
	//pawns[1].addComponent<SpriteComponent>("assets/pawn.png");
	pawn.addComponent<TransformComponent>();
	pawn.addComponent<SpriteComponent>("assets/pawn.png");
	pawn2.addComponent<TransformComponent>(100, 500);
	pawn2.addComponent<SpriteComponent>("assets/pawn.png");


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

		default:
			break;

	}
}
void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	manager.draw();
	SDL_RenderPresent(renderer);
}
void Game::update()
{
	
	//if (cnt < 2)
	//{
	//	pawns.emplace_back(Entity(manager.addEntity()));
	//}
	manager.update();
	pawn.getComponent<TransformComponent>().position.add(Vector2D(0, 0));
	if (pawn.getComponent<TransformComponent>().position.x>100)
	{
		pawn.getComponent<SpriteComponent>().setTex("assets/pawnWhite.png");

	}
	
	cnt++;
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