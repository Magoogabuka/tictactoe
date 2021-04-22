#ifndef __UTILS_H__
#define __UTILS_H__


const char xChoice();
const char oChoice();

void playGame();
void updateGame();
void clearMatrix();

int checkWin(int player);

bool playAgain();

const int IGNORING_CHAR = 256;

#endif
