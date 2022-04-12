#include "AI.h"
#include "../ShipContent/Ships/PatrolShip.h"
#include "../ShipContent/Ships/SubmarineShip.h"
#include "../ShipContent/Ships/DestroyerShip.h"
#include "../ShipContent/Ships/BattleshipShip.h"
#include "../ShipContent/Ships/CarrierShip.h"
#include "../Difficulty.h"
#include "../Utilities.h"

AI::AI(Board& aiBoard, Board& playerBoard) : m_aiBoard(aiBoard), m_playerBoard(playerBoard)
{
	// Set up ships on board here.
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
			int x = rand() % (BOARD_SIZE);
			int y = rand() % (BOARD_SIZE);
			bool horizontal = rand() % 2;

			if (horizontal) {
				if (x + aiShips[i].getLength() < BOARD_SIZE) {
					std::vector<Ship> previousShip = m_aiBoard.getShipTypes(x, y, aiShips[i].getLength(), horizontal);
					m_aiBoard.placeShip(x, y, aiShips[i], true);
					placed = !m_aiBoard.isOverlapping();
					if (!placed) {
						m_aiBoard.placeShips(x, y, previousShip, true);
					}
				}
			}
			else {
				if (y + aiShips[i].getLength() < BOARD_SIZE) {
					std::vector<Ship> previousShip = m_aiBoard.getShipTypes(x, y, aiShips[i].getLength(), horizontal);
					m_aiBoard.placeShip(x, y, aiShips[i], false);
					placed = !m_aiBoard.isOverlapping();
					if (!placed) {
						m_aiBoard.placeShips(x, y, previousShip, false);
					}
				}
			}
		}
	}
}

void AI::playTurn()
{
	unsigned int x = 0;
	unsigned int y = 0;

	float guaranteedHit = (rand() % 100) / 100.f;

	if (guaranteedHit <= difficulty_threshold[(int)Utilities::getDifficulty()]) {
		for (size_t y = 0; y < BOARD_SIZE; y++)
		{
			for (size_t x = 0; x < BOARD_SIZE; x++)
			{
				Ship* playerShip = m_playerBoard.getShip(x, y);
				if (playerShip->getType() != ShipType::Ocean && playerShip->getType() != ShipType::Shot && playerShip->getType() != ShipType::Target) {
					playerShip->setHit(true);
					return;
				}
			}
		}
	}

	if (playerCoords.size() > 0 && m_noHit < 2) {
		unsigned int randOldTarget = (rand() % (playerCoords.size() / 2)) * 2;
		unsigned int oldTargetX = playerCoords[randOldTarget];
		unsigned int oldTargetY = playerCoords[randOldTarget + 1];
		unsigned int newTargetX = (rand() % 3) - 1;
		unsigned int newTargetY = (rand() % 3) - 1;
		if (newTargetX == 0 && newTargetY == 0) {
			newTargetX = -1;
		}
		newTargetX += oldTargetX;
		newTargetY += oldTargetY;
		if (newTargetX < BOARD_SIZE && newTargetY < BOARD_SIZE) {
			Ship* targetShip = m_playerBoard.getShip(newTargetX, newTargetY);
			if (targetShip->getType() != ShipType::Shot && targetShip->getType() != ShipType::Target) {
				targetShip->setHit(true);
				if (targetShip->getType() == ShipType::Ocean) {
					m_noHit++;
				}
				else {
					playerCoords.push_back(newTargetX);
					playerCoords.push_back(newTargetY);
				}
			}
			else {
				playTurn();
			}
		}
		else {
			playTurn();
		}
		if (m_noHit >= 2) {
			playerCoords.clear();
		}
	}
	else {
		unsigned int targetX = rand() % BOARD_SIZE;
		unsigned int targetY = rand() % BOARD_SIZE;
		Ship* targetShip = m_playerBoard.getShip(targetX, targetY);
		if (targetShip->getType() != ShipType::Shot && targetShip->getType() != ShipType::Target) {
			targetShip->setHit(true);
			if (targetShip->getType() != ShipType::Ocean) {
				playerCoords.push_back(targetX);
				playerCoords.push_back(targetY);
			}
		}
		else {
			playTurn();
		}
	}
}