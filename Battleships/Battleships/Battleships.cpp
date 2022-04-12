#include "Utilities.h"
#include "BoardContent/Board.h"
#include "AIContent/AI.h"

#include <iostream>
#include "ShipContent/Ships/PatrolShip.h"
#include "ShipContent/Ships/SubmarineShip.h"
#include "ShipContent/Ships/DestroyerShip.h"
#include "ShipContent/Ships/CarrierShip.h"
#include "ShipContent/Ships/BattleshipShip.h"


int navigateMenu(std::string title, std::vector<std::string> options);

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

            // Set up ships.
            AI adversary(aiBoard, playerBoard);
            
            std::vector<Ship> playerShips;
            playerShips.push_back(PatrolShip());
            playerShips.push_back(SubmarineShip());
            playerShips.push_back(DestroyerShip());
            playerShips.push_back(BattleshipShip());
            playerShips.push_back(CarrierShip());
            bool placing = true;
            unsigned int x = 0;
            unsigned int y = 0;
            std::vector<Ship> previousShips;
            bool horizontal = true;
            for (size_t i = 0; i < playerShips.size(); i++)
            {
                previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                playerBoard.placeShip(x, y, playerShips[i], horizontal);
                bool placePhase = true;
                while (placePhase) {
                    Utilities::setTextColour(DARK_YELLOW);
                    std::cout << "Place: " << playerShips[i].getFullName() << std::endl;
                    Utilities::resetTextColour();
                    playerBoard.printBoard();
                    std::cout << std::endl;

                    std::cout << "Move ship with arrow keys." << std::endl;
                    std::cout << "Rotate with R key." << std::endl;
                    std::cout << "Confirm placement with Enter key." << std::endl;

                    int input = Utilities::getInput();
                
                    switch (input) {
                    case KEY_UP: {
                        if (y > 0) {
                            playerBoard.placeShips(x, y, previousShips, horizontal);
                            y--;
                            previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                            playerBoard.placeShip(x, y, playerShips[i], horizontal);
                        }
                    } break;
                    case KEY_DOWN: {
                        if (y < BOARD_SIZE - (horizontal ? 1 : playerShips[i].getLength())) {
                            playerBoard.placeShips(x, y, previousShips, horizontal);
                            y++;
                            previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                            playerBoard.placeShip(x, y, playerShips[i], horizontal);
                        }
                    } break;
                    case KEY_LEFT: {
                        if (x > 0) {
                            playerBoard.placeShips(x, y, previousShips, horizontal);
                            x--;
                            previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                            playerBoard.placeShip(x, y, playerShips[i], horizontal);
                        }
                    } break;
                    case KEY_RIGHT: {
                        if (x < BOARD_SIZE - (horizontal ? playerShips[i].getLength() : 1)) {
                            playerBoard.placeShips(x, y, previousShips, horizontal);
                            x++;
                            previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                            playerBoard.placeShip(x, y, playerShips[i], horizontal);
                        }
                    } break;
                    case KEY_R: {
                        playerBoard.placeShips(x, y, previousShips, horizontal);
                        horizontal = !horizontal;
                        if (horizontal && x >= BOARD_SIZE - playerShips[i].getLength()) {
                            x = BOARD_SIZE - playerShips[i].getLength();
                        }
                        else if (!horizontal && y >= BOARD_SIZE - playerShips[i].getLength()) {
                            y = BOARD_SIZE - playerShips[i].getLength();
                        }
                        previousShips = playerBoard.getShipTypes(x, y, playerShips[i].getLength(), horizontal);
                        playerBoard.placeShip(x, y, playerShips[i], horizontal);
                    } break;
                    case KEY_ENTER: {
                        if (!playerBoard.isOverlapping()) {
                            playerBoard.placeShip(x, y, playerShips[i], horizontal);
                            placePhase = false;
                            x = 0;
                            y = 0;
                        }
                    } break;
                    }
                    system("cls");
                }
            }

            bool playerVictory = false;
            bool battling = true;
            Ship* previousShip = targetBoard.getShip(x, y);
            targetBoard.updateShipSelection(*previousShip, x, y);
            while (battling) {
                std::cout << "Adversary Board" << std::endl;
                targetBoard.printBoard();
                std::cout << "Player Board" << std::endl;
                aiBoard.printBoard();

                std::cout << "Aim Target: Arrow Keys" << std::endl;
                std::cout << "Fire Shot: Enter Key" << std::endl;

                int input = Utilities::getInput();

                switch (input) {
                case KEY_UP: {
                    if (y > 0) {
                        targetBoard.placeShip(x, y, *previousShip, horizontal);
                        y--;
                        targetBoard.updateShipSelection(*previousShip, x, y);
                    }
                } break;
                case KEY_DOWN: {
                    if (y < BOARD_SIZE - 1) {
                        targetBoard.placeShip(x, y, *previousShip, horizontal);
                        y++;
                        targetBoard.updateShipSelection(*previousShip, x, y);
                    }
                } break;
                case KEY_LEFT: {
                    if (x > 0) {
                        targetBoard.placeShip(x, y, *previousShip, horizontal);
                        x--;
                        targetBoard.updateShipSelection(*previousShip, x, y);
                    }
                } break;
                case KEY_RIGHT: {
                    if (x < BOARD_SIZE - 1) {
                        targetBoard.placeShip(x, y, *previousShip, horizontal);
                        x++;
                        targetBoard.updateShipSelection(*previousShip, x, y);
                    }
                } break;
                case KEY_ENTER: {
                    if (targetBoard.getShip(x, y)->getType() != ShipType::Shot) {
                        aiBoard.hitShip(x, y);
                        targetBoard.getShip(x, y)->setHit(aiBoard.getShip(x, y)->getType() != ShipType::Ocean);
                        targetBoard.getShip(x, y)->setType(ShipType::Shot);
                        targetBoard.getShip(x, y)->setShortName(" X ");
                        targetBoard.updateShipSelection(*previousShip, x, y);
                        adversary.playTurn();
                        if (aiBoard.allShipsDestroyed() || playerBoard.allShipsDestroyed()) {
                            battling = false;
                            playerVictory = aiBoard.allShipsDestroyed();
                        }
                    }
                } break;
                }
                system("cls");
            }
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