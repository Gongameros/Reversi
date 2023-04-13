#pragma once
#include <iostream>
#include "Game.h"
#include <vector>
#include "Pawn.h"

extern PawnSet mainSet;

std::vector<std::vector<int>> MatrixSituation();

std::vector<int> MatrixSituation1D();

bool RelisedLogic(int color, int index_for_place);

std::vector<int> Transform2DMatrix(std::vector<std::vector<int>> a);

std::vector<std::vector<int>> AlgorithmChanging(int color, int index_for_place);

int From2Darr(int x, int y);

void changeMatrixColor(int IndexColor);

int MultiX(int x);

int NumberOfPawn(int x, int y);

int MultiY(int y);
