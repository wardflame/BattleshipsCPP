#pragma once
#include "../BoardContent/Board.h"

#include <vector>

class AI {
public:
	AI(Board& aiBoard, Board& playerBoard);
	
	void playTurn();

private:
	void placeShips();
	Board& m_aiBoard, m_playerBoard;
	std::vector<unsigned int> playerCoords;
	std::vector<unsigned int> emptyCoords;
	unsigned int m_noHit;
};