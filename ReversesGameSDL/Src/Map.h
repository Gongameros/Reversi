#pragma once
#include "Game.h"


class Map
{
public:
	Map();
	~Map();
	void LoadMap(int arr[10][12]);
	void DrawMap();
private:
	SDL_Rect srcR, destR;
	SDL_Texture* square;
	SDL_Texture* board;
	int map[10][12];
};

