#pragma once
#include <vector>
#include <Windows.h>

#include "BoardContent/Board.h"
#include "Difficulty.h"

#pragma region INPUT_DEFINES

#define KEY_ESCAPE 27
#define KEY_ENTER 13
#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_R 114

#pragma endregion

#pragma region COLOUR_DEFINES

#define BLACK 0
#define DARK_BLUE 1
#define DARK_GREEN 2
#define DARK_CYAN 3
#define DARK_RED 4
#define DARK_MAGENTA 5
#define DARK_YELLOW 6
#define LIGHT_GREY 7
#define DARK_GREY 8
#define BLUE 9
#define GREEN 10
#define CYAN 11
#define RED 12
#define MAGENTA 13
#define YELLOW 14
#define WHITE 15

#pragma endregion

class Utilities {
public:
	// Assign handle.
	static void init();

	// Set foreground colour.
	static void setForeground(int foreground);
	// Reset foreground colour.
	static void resetColour();

	// Get player input.
	static int getInput();

	// Difficulty
	static Difficulty getDifficulty();
	static void setDifficulty(Difficulty difficulty);

	/*
	static void setShipType(Board& board, unsigned int x, unsigned int y, ShipType shipType, unsigned int shipSize, bool horizontal);
	static void setShipType(Board& board, unsigned int x, unsigned int y, std::vector<ShipType> shipTypes, bool horizontal);

	static std::vector<ShipType> getShipTypes(Board& board, unsigned int x, unsigned int y, unsigned int shipSize, bool horizontal);

	static void updateShipSelection(Board& board, ShipType& previousShipType, unsigned int x, unsigned int y);

	// Check if any ships are overlaying
	static bool anyOverlay(Board& board);

	// Check if all ships on a board have been destroyed
	static bool allDestroyed(Board& board);

	static int randomInt(int minValue, int maxValue);*/
private:
	static HANDLE hConsole;
	static Difficulty m_difficulty;
};