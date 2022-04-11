#include "Utilities.h"

#include <conio.h>
#include <iostream>
#include <random>

HANDLE Utilities::hConsole;
Difficulty Utilities::m_difficulty;

void Utilities::initialiseHandle() {
	SetConsoleTitleA("Battleships");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
}

void Utilities::setTextColour(WORD wAttribute) {
	SetConsoleTextAttribute(hConsole, wAttribute);
}

void Utilities::resetTextColour() {
	setTextColour(LIGHT_GREY);
}

int Utilities::getInput() {
	return _getch();
}

Difficulty Utilities::getDifficulty() {
	return m_difficulty;
}

void Utilities::setDifficulty(Difficulty difficulty) {
	m_difficulty = difficulty;
}

std::string Utilities::getLetter(unsigned int index)
{
	if (index >= m_letterNumber.size())
	{
		return "";
	}
	return m_letterNumber[index];
}
