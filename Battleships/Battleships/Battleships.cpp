#include "Utilities.h"
#include "BoardContent/Board.h"
#include "ShipContent/Ship.h"

#include <iostream>

int navigateMenu(std::vector<std::string> options);

int main()
{
    // Init handle.
    Utilities::initialiseHandle();

    // Init main menu content.
    std::vector<std::string> mainMenu;
    mainMenu.push_back("New Game");
    mainMenu.push_back("Exit");

    // Init game menu content.
    std::vector<std::string> difficultyMenu;
    difficultyMenu.push_back("Cadet");
    difficultyMenu.push_back("Commodore");
    difficultyMenu.push_back("Admiral");

    bool playing = true;
    while (playing) {
        // Main Menu
        int option = navigateMenu("Battleships: SID 1543493", mainMenu);

        // Play game.
        if (option == 0) {
            // Choose difficulty.
            int difficulty = navigateMenu("Choose difficulty : ", difficultyMenu);
            Utilities::setDifficulty((Difficulty)difficulty);

            // Init boards.
            Board aiBoard;
            Board targetBoard;
            Board playerBoard;


        }
    }
    return 0;
}

/// <summary>
/// Navigate a menu of options and return the int of that option on ENTER.
/// </summary>
/// <param name="options">List of string options to print.</param>
/// <returns>Returns index of said option.</returns>
int navigateMenu(std::string title, std::vector<std::string> options) {
    int inputKey;
    int index = 0;
    do {
        Utilities::setTextColour(CYAN);
        std::cout << title << std::endl;
        Utilities::resetTextColour();
        for (size_t i = 0; i < options.size(); i++)
        {
            if (index == i) {
                Utilities::setTextColour(YELLOW);
            }
            std::cout << options[i] << std::endl;
            Utilities::resetTextColour();
        }
        inputKey = Utilities::getInput();
        switch (inputKey) {
        case KEY_UP: {
            if (index > 0)
            {
                index--;

            }
        } break;
        case KEY_DOWN: {
            if (index < options.size())
            {
                index++;
            }
        } break;
        }
        system("cls");
    } while (inputKey != KEY_ENTER);
    return index;
}