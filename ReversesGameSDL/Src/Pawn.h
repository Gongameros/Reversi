#pragma once
#include <vector>
#include "ECS/Components.h"
#include <memory>
#include "Game.h"

extern Manager managerMain;
class PawnSet;
class Pawn;

enum TemplatesForBlind
{
	AlreadyOnScreen = 0,
	Blinded = 1
};

enum TemplatesForColor
{
	White = 1,
	Black = 2
};

class Pawn
{
private:
	bool blind = Blinded;

	//false = white, true = black
	int Color = Black;
public:
	int temp_x = 128;
	int temp_y = 64;
	Entity& pawn_add = managerMain.addEntity();
	Pawn() {};
	~Pawn() {};
	bool getBlind() { return blind; }
	void changeBlind() { blind = AlreadyOnScreen; }
	int getColor() { return Color; }
	void changeColor()
	{
		if (Color == Black) { Color = White; }
		else { Color = Black; }
	}
	void changeColorBlack() { Color = Black; }
	void changeColorWhite() { Color = White; }
};

class PawnSet
{
private:
	size_t SIZE = 0;
public:
	std::vector<std::unique_ptr<Pawn>> pawns;
	PawnSet() {};
	~PawnSet(){};
	void addPawn();
	void drawStartPawns();
	void drawEntirePosition(int n);
};


