#include "Utilities.h"

#include <conio.h>
#include <iostream>

HANDLE Utilities::hConsole;
Difficulty Utilities::m_difficulty;
std::vector<std::string> Utilities::m_letterNumber;

void Utilities::initialiseHandle() {
	SetConsoleTitleA("Battleships");
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	srand(time(NULL));
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
	m_letterNumber.push_back("A");
	m_letterNumber.push_back("B");
	m_letterNumber.push_back("C");
	m_letterNumber.push_back("D");
	m_letterNumber.push_back("E");
	m_letterNumber.push_back("F");
	m_letterNumber.push_back("G");
	m_letterNumber.push_back("H");
	m_letterNumber.push_back("I");
	m_letterNumber.push_back("J");
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
