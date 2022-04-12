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
	for (int y = -1; y < BOARD_SIZE; y++)
	{
		for (int x = -1; x < BOARD_SIZE; x++)
		{
			if (x == -1 && y == -1) {
				std::cout << "  |";
			}
			else if (y == -1 && x >= 0) {
				Utilities::setTextColour(BLUE);
				std::cout << " " << Utilities::getLetter(x);
				Utilities::resetTextColour();
				std::cout << " |";
			}
			else if (x == -1 && y >= 0) {
				int line = y + 1;
				Utilities::setTextColour(BLUE);
				std::cout << line;
				if (line < 10) {
					std::cout << " ";
				}
				Utilities::resetTextColour();
				std::cout << "|";
			}
			else {
				Ship* ship = getShip(x, y);
				std::string shortName = ship->getShortName();
				if (ship->isHit()) {
					if (ship->getType() == ShipType::Target) {
						Utilities::setTextColour(DARK_YELLOW);
					}
					else {
						Utilities::setTextColour(DARK_RED);
					}
				}
				else {
					if (ship->getType() != ShipType::Ocean) {
						Utilities::resetTextColour();
					}
					else {
						Utilities::setTextColour(CYAN);
					}
				}
				std::cout << shortName;
				if (shortName.size() < 3) {
					for (size_t i = 0; i < 3 - shortName.size(); i++)
					{
						std::cout << " ";
					}
				}
				if (x < BOARD_SIZE - 1) {
					Utilities::setTextColour(CYAN);
				}
				else {
					Utilities::resetTextColour();
				}
				std::cout << "|";
				Utilities::resetTextColour();
			}
		}
		std::cout << std::endl;
	}
}

bool Board::hitShip(unsigned int x, unsigned int y)
{
	Ship* ship = getShip(x, y);
	if (ship->getType() == ShipType::Ocean) {
		return false;
	}
	if (ship->isHit()) {
		return false;
	}
	ship->setHit(true);
	return true;
}

void Board::placeShip(unsigned int x, unsigned int y, Ship ship, bool horizontal)
{
	for (size_t i = 0; i < ship.getLength(); i++)
	{
		Ship* targetShip = getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i));
		if ((targetShip->getType() != ship.getType() && targetShip->getType() != ShipType::Ocean && targetShip->getType() != ShipType::Target) || ((targetShip->getType() == ShipType::Shot || targetShip->getType() == ShipType::Target) && targetShip->isHit())) {
			targetShip->setHit(true);
		}
		else {
			targetShip->setHit(false);
		}
		targetShip->setType(ship.getType());
		targetShip->setShortName(ship.getShortName());
	}
}

void Board::placeShips(unsigned int x, unsigned int y, std::vector<Ship> shipTypes, bool horizontal)
{
	for (size_t i = 0; i < shipTypes.size(); i++)
	{
		Ship* ship = getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i));
		ship->setHit(false);
		ship->setType(shipTypes.at(i).getType());
		ship->setShortName(shipTypes[i].getShortName());
	}
}

std::vector<Ship> Board::getShipTypes(unsigned int x, unsigned int y, unsigned int shipLength, bool horizontal)
{
	std::vector<Ship> shipTypes;
	for (size_t i = 0; i < shipLength; i++)
	{
		shipTypes.push_back(*getShip(x + (horizontal ? i : 0), y + (horizontal ? 0 : i)));
	}
	return shipTypes;
}

void Board::updateShipSelection(Ship& previousShipType, unsigned int x, unsigned int y)
{
	previousShipType = Ship(*getShip(x, y));
	getShip(x, y)->setType(ShipType::Target);
	getShip(x, y)->setShortName(" + ");
}

bool Board::isOverlapping() {
	for (size_t y = 0; y < BOARD_SIZE; y++)
	{
		for (size_t x = 0; x < BOARD_SIZE; x++)
		{
			if (getShip(x, y)->isHit()) {
				return true;
			}
		}
	}
	return false;
}

bool Board::allShipsDestroyed()
{
	for (size_t y = 0; y < BOARD_SIZE; y++)
	{
		for (size_t x = 0; x < BOARD_SIZE; x++)
		{
			Ship* ship = getShip(x, y);
			if (ship->getType() == ShipType::Ocean || ship->getType() == ShipType::Target) {
				continue;
			}
			if (!getShip(x, y)->isHit()) {
				return false;
			}
		}
	}
	return true;
}
