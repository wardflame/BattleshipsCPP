#pragma once
#include <Windows.h>
#include <vector>

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
	/// <summary>
	/// Init handle for changeing text colours.
	/// </summary>
	static void initialiseHandle();

	/// <summary>
	/// Set the console's foreground colour.
	/// </summary>
	/// <param name="foreground">int correlating to foreground number definition.</param>
	static void setTextColour(WORD wAttribute);

	/// <summary>
	/// Reset console's foreground colour.
	/// </summary>
	static void resetTextColour();

	/// <summary>
	/// Get the player's input and return the character int.
	/// </summary>
	/// <returns>int relating to character key.</returns>
	static int getInput();

	/// <summary>
	/// Access game's difficulty setting.
	/// </summary>
	/// <returns>Returns current difficulty.</returns>
	static Difficulty getDifficulty();

	/// <summary>
	/// Set the game's difficulty.
	/// </summary>
	/// <param name="difficulty">Difficulty to be set.</param>
	static void setDifficulty(Difficulty difficulty);

	/// <summary>
	/// Get a letter by an index value from a vector.
	/// </summary>
	/// <param name="letter">Letter index in vector.</param>
	/// <returns>Returns string letter from vector at index.</returns>
	static std::string getLetter(unsigned int index);

private:
	static HANDLE hConsole;
	static Difficulty m_difficulty;
	static std::vector<std::string> m_letterNumber;
};