#include "Map.h"
#include "TextureManager.h"

int bacground[10][12]{
	{0,0,0,0,0,0,0,0,0,0,0,0},
	//board
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	{0,0,1,1,1,1,1,1,1,1,0,0},
	//end board
	{0,0,0,0,0,0,0,0,0,0,0,0}
};

Map::Map()
{
	square = TextureManager::LoadTexture("assets/square 64x64.png");
	board = TextureManager::LoadTexture("assets/board.png");
	LoadMap(bacground);

	srcR.x = srcR.y = 0;
	srcR.h = destR.h = 64;
	srcR.w = destR.w = 64;
	destR.x = destR.y = 0;

}
Map::~Map()
{

}
void Map::LoadMap(int arr[10][12])
{
	for (size_t i = 0; i < 10; i++)
	{
		for (size_t j = 0; j < 12; j++)
		{
			map[i][j] = arr[i][j];
		}
	}
}
void Map::DrawMap()
{
	int type = 0;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			type = map[i][j];

			destR.x = j * 64;
			destR.y = i * 64;

			switch (type)
			{
			case 0:
				TextureManager::Draw(board, srcR, destR);
				break;
			case 1:
				TextureManager::Draw(square, srcR, destR);
				break;
			default:
				break;
			}
		}
	}
}


