#include "Pawn.h"

void PawnSet::addPawn()
{
	size_t i = 0;
	while (SIZE < 64)
	{
		std::unique_ptr<Pawn> temp(new Pawn);
		pawns.emplace_back(std::move(temp));
		SIZE++;
		i++;
	}
	//adding pos
	int temp_cnt = 1;
	int count_ypos = 1;
	for (size_t i = 0; i < 64; i++)
	{

		if (count_ypos > 1)
		{
			pawns[i]->temp_y = 64 * count_ypos;
		}

		pawns[i]->pawn_add.addComponent<TransformComponent>(pawns[i]->temp_x, pawns[i]->temp_y);
		if (temp_cnt == 8 && i < 63)
		{
			pawns[i + 1]->temp_y = pawns[i]->temp_y;
			pawns[i + 1]->temp_y += 64;
			pawns[i + 1]->temp_x = 128;
			temp_cnt = 0;
			count_ypos++;
		}
		else if (i < 63) {
			pawns[i + 1]->temp_x = pawns[i]->temp_x;
			pawns[i + 1]->temp_x += 64;
		}
		temp_cnt++;
	}
}

void PawnSet::drawStartPawns()
{
	pawns[27]->pawn_add.addComponent<SpriteComponent>("assets/pawn.png");
	pawns[27]->changeBlind();
	pawns[28]->pawn_add.addComponent<SpriteComponent>("assets/pawnWhite.png");
	pawns[28]->changeBlind();
	pawns[28]->changeColorWhite();
	pawns[35]->pawn_add.addComponent<SpriteComponent>("assets/pawnWhite.png");
	pawns[35]->changeBlind();
	pawns[35]->changeColorWhite();
	pawns[36]->pawn_add.addComponent<SpriteComponent>("assets/pawn.png");
	pawns[36]->changeBlind();

}
void PawnSet::drawEntirePosition(int n)
{

		if(pawns[n]->getColor()==Black)
		{ 
			pawns[n]->pawn_add.addComponent<SpriteComponent>("assets/pawn.png");
		}

			
		else
		{ 
			pawns[n]->pawn_add.addComponent<SpriteComponent>("assets/pawnWhite.png");

		}


}