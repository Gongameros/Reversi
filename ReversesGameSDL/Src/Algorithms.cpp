#include "Algorithms.h"

bool AcceptStep = false;

int MultiX(int x)
{
    int multi_X = 0;
    while (x >= 0)
    {
        x -= 64;
        multi_X++;
    }
    multi_X--;
    return (multi_X - 2);
}
int MultiY(int y)
{
    int multi_Y = 0;
    while (y >= 0)
    {
        y -= 64;
        multi_Y++;
    }
    multi_Y--;
    return (multi_Y - 1);
}

int NumberOfPawn(int x, int y)
{
    int temp = x;
    while (y > 0)
    {
        temp += 8;
        y--;
    }
    return temp;
}


int From2Darr(int x, int y)
{
    y = ((8 * (x + 1)) - 1)+y;
    return y;
}

std::vector<std::vector<int>> AlgorithmChanging(int color, int index_for_place)
{
    std::vector<std::vector<int>> matrix = MatrixSituation();
    int x = (index_for_place + 1) / 8;
    int y = index_for_place % 8;

    //перевірка чи пуста клітинка
    if (matrix[x][y] == 0) {
        //перевірки чи валідні значення
        bool is_valid = false;
        //перевірка по вертикалі вниз
        if (x < 6 && matrix[x + 1][y] != 0) {
            int x_copy = x + 1;
            while (x_copy != 8) {
                if (matrix[x_copy][y] == color && x_copy - x > 1) {
                    is_valid = true;
                    for (int i = x; i < x_copy; ++i) {
                        matrix[i][y] = color;
                    }
                    break;
                }
                x_copy++;
            }
        }

        //перевірка по вертикалі вгору
        if (x > 1 && matrix[x - 1][y] != 0) {
            int x_copy = x - 1;
            while (x_copy != -1) {
                if (matrix[x_copy][y] == color && x - x_copy > 1) {
                    is_valid = true;
                    for (int i = x_copy; i <= x; ++i) {
                        matrix[i][y] = color;
                    }
                    break;
                }
                x_copy--;
            }
        }

        //перевірка по горизонталі вправо
        if (y < 6 && matrix[x][y + 1] != 0) {
            int y_copy = y + 1;
            while (y_copy != 8) {
                if (matrix[x][y_copy] == color && y_copy - y > 1) {
                    is_valid = true;
                    for (int i = y; i < y_copy; ++i) {
                        matrix[x][i] = color;
                    }
                    break;
                }
                y_copy++;
            }
        }

        //перевірка по горизонталі вліво
        if (y > 1 && matrix[x][y - 1] != 0) {
            int y_copy = y - 1;
            while (y_copy != -1) {
                if (matrix[x][y_copy] == color && y - y_copy > 1) {
                    is_valid = true;
                    for (int i = y_copy; i <= y; ++i) {
                        matrix[x][i] = color;
                    }
                    break;
                }
                y_copy--;
            }
        }


        if (is_valid) { AcceptStep = true; }
        else { AcceptStep = false; }


    }

    return matrix;
}

void changeMatrixColor(int IndexColor, int Color)
{
    if (White == Color)
    {
        mainSet.pawns[IndexColor]->changeColorWhite();
        mainSet.pawns[IndexColor]->changeBlind();
        mainSet.drawEntirePosition(IndexColor);
    }
    else
    {
        mainSet.pawns[IndexColor]->changeColorBlack();
        mainSet.pawns[IndexColor]->changeBlind();
        mainSet.drawEntirePosition(IndexColor);
    }
        
        
}

std::vector<int> Transform2DMatrix(std::vector<std::vector<int>> a)
{
    std::vector<int> normal(64);
    int temp = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            normal[temp] = a[i][j];
            temp++;
        }
    }
    return normal;
}

bool RelisedLogic(int color, int index_for_place)
{
    std::vector<std::vector<int>>temp1 = AlgorithmChanging(color, index_for_place);
    std::vector<int> mainArr = Transform2DMatrix(temp1);
    std::vector<int> comparable = MatrixSituation1D();
    for (int i = 0; i < 64; i++)
    {
        if (mainArr[i] == comparable[i]){}
        else
        {
            if (White == color)
                changeMatrixColor(i,White);
            else
                changeMatrixColor(i, Black);
            
        }
    }

    return AcceptStep;
}

std::vector<std::vector<int>> MatrixSituation()
{
    std::vector<int> temp_base(8);
    std::vector<std::vector<int>> temp_situation(8,temp_base);
    int j = 0;
    for (int i = 0; i < 64; i++)
    {

        if (mainSet.pawns[i]->getBlind() == Blinded)
            temp_situation[j][(i % 8)] = 0;

        else
        {
            if (mainSet.pawns[i]->getColor() == White)
                temp_situation[j][(i % 8)] = 1;
            else
                temp_situation[j][(i % 8)] = 2;
        }
        if ((i + 1) % 8 == 0 && j != 8)
            j++;
    }
    return temp_situation;
}

std::vector<int> MatrixSituation1D()
{
    std::vector<int> temp_situation(64);
    for (int i = 0; i < 64; i++)
    {

        if (mainSet.pawns[i]->getBlind() == Blinded)
            temp_situation[i] = 0;

        else
        {
            if (mainSet.pawns[i]->getColor() == White)
                temp_situation[i] = 1;
            else
                temp_situation[i] = 2;
        }
    }
    return temp_situation;
}