#include "Utils.hpp"


char gameBoard[3][3] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

void drawBoard()
{
    system("clear");
    std::cout<<"+---+---+---+\n";
    for(int d = 0; d<3; d++)
    {
        std::cout<<"| "<<gameBoard[d][0]<<" | "<<gameBoard[d][1]<<" | "<<gameBoard[d][2]<<" |";
        if(d != 2)
        {
            std::cout<<"\n+---+---+---+\n";
        }
    }
    std::cout<<"\n+---+---+---+\n";
}

void updateGame()
{
    system("clear");
    drawBoard();
}


bool playAgain()
{
  char input;
  bool failure;

  do
  {
    failure = false;

    std::cout << "Would you like to play again? (y/n) ";
    std::cin >> input;
    clearMatrix();

    if(std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(IGNORING_CHAR, '\n');
      std::cout << "Input error! Please try again." << std::endl;
      failure = true;
    }
    else
    {
      std::cin.ignore(IGNORING_CHAR, '\n');

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
      gameBoard[i][j] = i*3+(j+1) + 48;
    }
  }
}


int checkWin(int player)
{
    
      for(int i=0; i<3; i++)//CHECKS ROWS FOR WIN
      {
        if((gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][0] == gameBoard[i][2]) || (gameBoard[0][i] == gameBoard[1][i] && gameBoard[0][i] == gameBoard[2][i]))
        {
          std::cout<<"Congratulations! Player: "<<player<<" won!"<<std::endl;;
          return 1;
        }
      }
      if((gameBoard[0][0] == gameBoard[1][1] && gameBoard[0][0] == gameBoard[2][2]) || (gameBoard[0][2] == gameBoard[1][1] && gameBoard[0][2] == gameBoard[2][0])) //CHECKS VERTICALS FOR WIN
      {
        std::cout<<"Congratulations! Player: "<<player<<" won!"<<std::endl;;
        return 1;
      }
      else if (gameBoard[0][0] != '1' && gameBoard[0][1] != '2' && gameBoard[0][2] != '3'
               && gameBoard[1][0] != '4' && gameBoard[1][1] != '5' && gameBoard[1][2] != '6'
             && gameBoard[2][0] != '7' && gameBoard[2][1] != '8' && gameBoard[2][2] != '9')
                    {
                      std::cout<<"CAT GAME - NO PLAYER WINS"<<std::endl;;
                      return 0;
                    }

      else
      {
          return -1;
      }

}


const char xChoice()
{
    
  int markx = 'X';
  char choice;
  bool tryAgain = true;
  
    do
    {
        cout<<"Choose a position for X: ";
        cin>>choice;
                
            if(choice > '0' && choice <= '9')
            {
                if(gameBoard[(choice - '1')/3][(choice - '1')%3] == choice) // array start from 0,1,2... so if choice = 7, it will be 7-1 = 6th place in the array. divided by three puts it in the third row, in the first spot. with the modulus of 6/3 being 0, so it places the x in the spot: gameBoard[2][0] row 2, column 0; have it inside the if parameters to make sure that the space hasnt been filled yet as well. could probably do this as a switch as well.
                {
                    gameBoard[(choice - '1')/3][(choice - '1')%3] = markx;
                    tryAgain = false;
                }
                else
                {
                    std::cout<<"Space already taken! ";
                    tryAgain = true;
                }

            }
                
    }while(tryAgain == true);

  return markx;
}

const char oChoice()
{
    int marko = 'O';
    char choice;
    bool tryAgain = true;
    
    do
    {
        cout<<"Choose a position for O: ";
        cin>>choice;
            
            if(choice > '0' && choice <= '9') //makes sure that the value entered was in the correct parameters.
            {
                if(gameBoard[(choice - '1')/3][(choice - '1')%3] == choice) // array start from 0,1,2... so if choice = 7, it will be 7-1 = 6th place in the array. divided by three puts it in the third row, in the first spot. with the modulus of 6/3 being 0, so it places the x in the spot: gameBoard[2][0] row 2, column 0; have it inside the if parameters to make sure that the space hasnt been filled yet as well. could probably do this as a switch as well.
                {
                    gameBoard[(choice - '1')/3][(choice - '1')%3] = marko;
                    tryAgain = false;
                }
                else
                {
                    std::cout<<"Space already taken! ";
                    tryAgain = true;
                }

            }
 
    }while(tryAgain == true);


  return marko;
}


void playGame()
{
    int player = 1;
    int playAgain;
    
      if(getPlayerType() == 1)
      {
          cout<<"Which player will go first?: ";
          cin>>player;
          updateGame();
        do
        {
            if(player == 1)
            {
                cout<<"Player "<<player<<" turn"<<endl;
                xChoice();
                updateGame();
            }
            else if(player == 2)
            {
                cout<<"Player "<<!player<<" turn"<<endl;
                oChoice();
                updateGame();
                
            }
            
            playAgain = checkWin(player);
            player = player == 1 ? 2 : 1;
            
        }while(playAgain == -1);
      }
      else
      {
          cout<<"Which player will go first?: ";
          cin>>player;
          updateGame();
          
          do
          {
              if(player == 1)
              {
                  cout<<"Player "<<player<<" turn"<<endl;
                  xChoice();
                  updateGame();
              }
              else if(player == 2)
              {
                  cout<<"Player "<<!player<<" turn"<<endl;
                  AiGuess();
                  updateGame();
              }
              playAgain = checkWin(player);
              player = player == 1 ? 2 : 1;
              
          }while(playAgain == -1);
      }
}


const char AiGuess()
{
    srand((unsigned)time(NULL));
    char marko = 'O';
    bool tryAgain = true;
    /*Ai will always be 'O'
     will need to check what spots have been taken already.
     make it choose a random spot for the O.
    */
    do
    {
        char randomSpot = gameBoard[rand()%3][rand()%3];
        
        if(randomSpot != 'X' || randomSpot != 'O')
        {
            switch(randomSpot)
            {
                case '1':
                    gameBoard[0][0] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '2':
                    gameBoard[0][1] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '3':
                    gameBoard[0][2] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '4':
                    gameBoard[1][0] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '5':
                    gameBoard[1][1] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '6':
                    gameBoard[1][2] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '7':
                    gameBoard[2][0] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '8':
                    gameBoard[2][1] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                case '9':
                    gameBoard[2][2] = marko;
                    waitForKeyPress();
                    tryAgain = false;
                    break;
                    
            }
        }
        else if(randomSpot == 'O' || randomSpot == 'X')
        {
            std::cout<<"AI is thinking....\n";
            //waitForKeyPress();
            tryAgain = true;
            
        }
       
    }while(tryAgain == true);
    
    return marko;
}

void waitForKeyPress()
{
  system("read -n 1 -s -p \"Press any key to continue...\";echo");
}

int getPlayerType()
{
    int choice;
    std::cout<<"Who would you like to play against?\n1. HUMAN vs HUMAN\n2. HUMAN vs AI\n\nWhat is your choice?: ";
    std::cin>>choice;
    
    if(choice == 1)
    {
        return 1;
    }
    else
    {
        return 2;
    }
    
}

