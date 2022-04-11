#pragma once
#include <vector>
#include <string>

#include "../ShipContent/Ship.h"

#define BOARD_SIZE 10

class Board {
public:
	Board();

	Ship* getShips();
	Ship* getShip(unsigned int x, unsigned int y);

	void printBoard();

	bool hitShip(unsigned int x, unsigned int y);

	void placeShip(unsigned int x, unsigned int y, Ship ship, bool horizontal);
	void placeShips(unsigned int x, unsigned int y, std::vector<ShipType> shipTypes, bool horizontal);

	std::vector<ShipType> getShipTypes(unsigned int x, unsigned int y, unsigned int shipLength, bool horizontal);

	void updateShipSelection(ShipType& previousShipType, unsigned int x, unsigned int y);

	/// <summary>
	/// Check to see if ships are present at the same coordinates.
	/// </summary>
	/// <param name="board">Board to check for overlapping ships.</param>
	/// <returns>Returns true if ships are overlapping.</returns>
	bool isOverlapping();
	/// <summary>
	/// Check if all ships are destroyed on a board.
	/// </summary>
	/// <param name="board">Board to check.</param>
	/// <returns>Returns true if all ships are destroyed.</returns>
	bool allShipsDestroyed();	

private:
	Ship* m_ships;
};