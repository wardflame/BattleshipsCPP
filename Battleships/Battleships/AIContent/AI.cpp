#include "AI.h"
#include "../ShipContent/Ships/PatrolShip.h"
#include "../ShipContent/Ships/SubmarineShip.h"
#include "../ShipContent/Ships/DestroyerShip.h"
#include "../ShipContent/Ships/BattleshipShip.h"
#include "../ShipContent/Ships/CarrierShip.h"

AI::AI(Board& aiBoard, Board& playerBoard) : m_aiBoard(aiBoard), m_playerBoard(m_playerBoard)
{
	placeShips();
}

void AI::placeShips()
{
	std::vector<Ship> aiShips;
	aiShips.push_back(PatrolShip());
	aiShips.push_back(SubmarineShip());
	aiShips.push_back(DestroyerShip());
	aiShips.push_back(BattleshipShip());
	aiShips.push_back(CarrierShip());
	for (size_t i = 0; i < aiShips.size(); i++)
	{
		bool placed = false;
		while (!placed)
		{
			int x = rand() % (BOARD_SIZE + 1);
			int y = rand() % (BOARD_SIZE + 1);
			bool horizontal = rand() % 2;

			if (horizontal) {
				if (!(x + aiShips[i].getLength() >= BOARD_SIZE)) {
					for (size_t i = x; i < aiShips[i].getLength(); i++)
					{
						m_aiBoard.placeShip(i, y, aiShips[i], true);
						placed = true;
					}
				}
			}
			else {
				if (!(y + aiShips[i].getLength() >= BOARD_SIZE)) {
					for (size_t i = x; i < aiShips[i].getLength(); i++)
					{
						m_aiBoard.placeShip(i, y, aiShips[i], true);
						placed = true;
					}
				}
			}
		}
	}
}

void AI::playTurn()
{
}