
#include "utils.h"

/*
Write a tic tac toe game in a 3 by 3 grid that is played with two players
one plaer marks a O and the other player places an X.
each player takes turns marking their marker to try and get 3 lined up
a player wins when three of their markers line up horizontally, diagonally
or vertically. if no one lines them up the game is called a "Cat Game"
program should output the winner or if it was a cat game.
user should be propmted if they want to play playAgain
if they play again the user who started 2nd in the first round goes first in the
next round.

+---+---+---+
| X | O | O |
+---+---+---+
| O | X | O |
+---+---+---+
| O | O | X |
+---+---+---+


  cout<<"This is the board, each spot represents a choice \n"
      <<"if you choose (1), your mark will go in the position of 1"<<endl;
      cout<<" -------------"<<endl;
      for(int i = 0; i<3; i++)
      {
        cout<<" | ";
          for(int j = 0; j<3; j++)
          {
            cout<<array[i][j]<< " | ";
          }
          cout<<endl;
        }
        cout<<" -------------"<<endl;

*/

int main()
{

    do {

      playGame();

    } while(playAgain());


  return 0;
}
