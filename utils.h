#ifndef __UTILS_H__
#define __UTILS_H__



#include <stdio.h>
#include <iostream>


void initGameBoard();
void drawBoard();
void clearMatrix();
void playGame();
bool playAgain();
const char xChoice();
const char oChoice();
const char AiGuess();
int checkWin(int player);
void waitForKeyPress();
int getPlayerType();

using namespace std;

const int IGNORING_CHAR = 256;


#endif
