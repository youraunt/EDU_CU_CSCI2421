//
// Created by BK Allen on 2/2/20.
//

#ifndef INC_2188HW1_FUNCTIONS_H
#define INC_2188HW1_FUNCTIONS_H



#include <iostream>
#include <zconf.h>


int playAgain();

void unknownInput();

int maxRange();

unsigned int numIntToGuess();

std::string exitProgram();

static const char MENU_TITLE[] =
        "\n\x1b[36m"
        "\t-----------------------------------\n"
        "\t|         Guessing Game           |\n"
        "\t-----------------------------------\n"
        "\n\x1b[0m";
static const char GAME_EXPLANATION[] =

        "In this game you will be guessing n random integers from 1 to m. \n"
        "The same integer may appear more than once. \n"
        "For example, the game might choose the following four integers \n"
        "in the range of 1 to 10: 4,6,1,6. "

        "\nYou have up to three rounds to win!";





#endif //INC_2188HW1_FUNCTIONS_H
