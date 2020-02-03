//
// Created by BK Allen on 2/2/20.
//

#ifndef INC_2188HW1_GUESS_H
#define INC_2188HW1_GUESS_H


//
// Created by BK Allen on 1/31/20.
//


#include <vector>
#include <random>
#include <iostream>

using namespace std;

class GuessingGame {

private:
    vector<int> randomIntegers;
    const static unsigned int min = 1;
    int max;
    unsigned int size;


public:
    GuessingGame(unsigned int min, int max, unsigned int size);
    void startGuess();
    unsigned int correctAnswers(vector<int> *guesses);
};




#endif //INC_2188HW1_GUESS_H
