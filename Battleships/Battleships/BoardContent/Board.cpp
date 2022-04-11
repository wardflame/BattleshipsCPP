#include "Board.h"
#include "../Utilities.h"
#include <iostream>

Board::Board()
{
	m_ships = new Ship[BOARD_SIZE * BOARD_SIZE];
	for (unsigned int y = 0; y < BOARD_SIZE; y++)
	{
		for (unsigned int x = 0; x < BOARD_SIZE; x++)
		{
			m_ships[y * BOARD_SIZE + x] = Ship();
		}
	}
}

Ship* Board::getShips()
{
	return m_ships;
}

Ship* Board::getShip(unsigned int x, unsigned int y)
{
	if (x >= BOARD_SIZE || y >= BOARD_SIZE)
	{
		return nullptr;
	}
	return &m_ships[y * BOARD_SIZE + x];
}

void Board::printBoard()
{
	for (int y = -1; y < (int)BOARD_SIZE; y++)
	{
		for (int x = -1; x < (int)BOARD_SIZE; x++)
		{
			/*if (x == -1 && y == -1) {
				std::cout << "  |"
			}
			else if (y == -1 && x >= 0) {
				Utilities::setTextColour()
			}*/
		}
		std::cout << std::endl;
	}
}

bool Board::hitShip(unsigned int x, unsigned int y)
{
	return false;
}

void Board::placeShip(unsigned int x, unsigned int y, Ship ship, bool horizontal)
{
	for (size_t i = 0; i < ship.getLength(); i++)
	{
		Ship* targetShip = getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i));
		if (targetShip->getType() != ship.getType() && targetShip->getType() != ShipType::Ocean) {
			targetShip->setHit(true);
		}
		else {
			targetShip->setHit(false);
		}
		targetShip->setType(ship.getType());
	}
}

void Board::placeShips(unsigned int x, unsigned int y, std::vector<ShipType> shipTypes, bool horizontal)
{
	for (size_t i = 0; i < shipTypes.size(); i++)
	{
		Ship* ship = getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i));
		ship->setHit(false);
		ship->setType(shipTypes.at(i));
	}
}

std::vector<ShipType> Board::getShipTypes(unsigned int x, unsigned int y, unsigned int shipLength, bool horizontal)
{
	std::vector<ShipType> shipTypes;
	for (size_t i = 0; i < shipLength; i++)
	{
		shipTypes.push_back(getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i))->getType());
	}
	return shipTypes;
}

bool Utilities::isOverlapping() {
	for (size_t y = 0; y < BOARD_SIZE; y++)
	{
		/*for (size_t x = 0; x < BOARD_SIZE; x++)
		{
			if (board.getShip(x, y)->isHit())
				return true;
		}*/
	}
}
