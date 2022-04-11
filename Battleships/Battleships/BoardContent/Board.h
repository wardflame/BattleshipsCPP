#pragma once
#include "../ShipContent/Ship.h"

class Board {
public:
	Board();

	Ship* getShips();
	Ship* getShip(unsigned int x, unsigned int y);

	void printBoard();

	bool hitShip(unsigned int x, unsigned int y);

private:
	Ship* m_ships;
};