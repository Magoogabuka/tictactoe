#include "utils.h"
#include <iostream>
#include <cctype>
#include <cstdlib> // needed for system("clear"); command.

using namespace std;

char array[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};


const char xChoice()
{
  int markx = 'X';
  char choice;

  cout<<"Choose a position for X: ";
  cin>>choice;

  if(choice == '1' && array[0][0] == '1')
  {
    array[0][0] = markx;
  }
  else if (choice == '2' && array[0][1] == '2')
  {
    array[0][1] = markx;
  }
  else if (choice == '3')
  {
    array[0][2]= markx;
  }
  else if(choice == '4')
  {
    array[1][0] = markx;
  }
  else if(choice == '5')
  {
    array[1][1] = markx;
  }
  else if(choice == '6')
  {
    array[1][2] = markx;
  }
  else if(choice == '7')
  {
    array[2][0] = markx;
  }
  else if(choice == '8')
  {
    array[2][1] = markx;
  }
  else if(choice == '9')
  {
    array[2][2] = markx;
  }

  return markx;
}

const char oChoice()
{
  int marko = 'O';
  char choice;

  cout<<"Choose a position for O: ";
  cin>>choice;

  if(choice == '1' && array[0][0] == '1')
  {
    array[0][0] = marko;
  }
  else if (choice == '2' && array[0][1] == '2')
  {
    array[0][1] = marko;
  }
  else if (choice == '3')
  {
    array[0][2] = marko;
  }
  else if(choice == '4')
  {
    array[1][0] = marko;
  }
  else if(choice == '5')
  {
    array[1][1] = marko;
  }
  else if(choice == '6')
  {
    array[1][2] = marko;
  }
  else if(choice == '7')
  {
    array[2][0] = marko;
  }
  else if(choice == '8')
  {
    array[2][1] = marko;
  }
  else if(choice == '9')
  {
    array[2][2] = marko;
  }

  return marko;
}

void playGame()
{
  int player = 1, playAgain;
  updateGame();
  do
    {

      if(player == 1)
      {
        cout<<"Player "<<player<<" turn"<<endl;
        xChoice();
        updateGame();
      }
      else if (player == 2)
      {
        cout<<"Player "<<!player<<" turn"<<endl;
        oChoice();
        updateGame();
      }

      playAgain = checkWin(player);

    player = player == 1 ? 2 : 1; //if (PlayerTurn == 1){ <- same thing
                                      //PlayerTurn = 2;}

    }while(playAgain == -1);
}

void updateGame()
{
  system("clear");

  cout<<"PLAYER 1 = X  ||   PLAYER 2 = O"<<endl;
  cout <<"          "<<"+---+---+---+"<<endl;
  cout <<"          "<<"| "<<array[0][0]<<" | "<<array[0][1]<<" | "<<array[0][2]<<" | "<<endl;
  cout <<"          "<<"+---+---+---+"<<endl;
  cout <<"          "<<"| "<<array[1][0]<<" | "<<array[1][1]<<" | "<<array[1][2]<<" | "<<endl;
  cout <<"          "<<"+---+---+---+"<<endl;
  cout <<"          "<<"| "<<array[2][0]<<" | "<<array[2][1]<<" | "<<array[2][2]<<" | "<<endl;
  cout <<"          "<<"+---+---+---+"<<endl;
}

int checkWin(int player)
{
  for(int i=0; i<3; i++)
  {
    if((array[i][0] == array[i][1] && array[i][0] == array[i][2]) || (array[0][i] == array[1][i] && array[0][i] == array[2][i]))
    {
      cout<<"Congratulations! Player: "<<player<<" won!"<<endl;;
      return 1;
    }
  }
  if((array[0][0] == array[1][1] && array[0][0] == array[2][2]) || (array[0][2] == array[1][1] && array[0][2] == array[2][0]))
  {
    cout<<"Congratulations! Player: "<<player<<" won!"<<endl;;
    return 1;
  }
  else if (array[0][0] != '1' && array[0][1] != '2' && array[0][2] != '3'
                  && array[1][0] != '4' && array[1][1] != '5' && array[1][2] != '6'
                && array[2][0] != '7' && array[2][1] != '8' && array[2][2] != '9')
                {
                  cout<<"CAT GAME - NO PLAYER WINS"<<endl;;
                  return 0;
                }

  else
  {
      return -1;
  }

}

bool playAgain()
{
  char input;
  bool failure;

  do
  {
    failure = false;

    cout << "Would you like to play again? (y/n) ";
    cin >> input;
    clearMatrix();

    if(cin.fail())
    {
      cin.clear();
      cin.ignore(IGNORING_CHAR, '\n');
      cout << "Input error! Please try again." << endl;
      failure = true;
    }
    else
    {
      cin.ignore(IGNORING_CHAR, '\n');

      input = tolower(input);
    }
  }while(failure);

  return input == 'y';

}

void clearMatrix()
{
  for(int i = 0; i<3; i++)
  {
    for(int j = 0; j<3; j++)
    {
      array[i][j] = i*3+(j+1) + 48;
    }
  }
}
