#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Board.h"
#include <time.h> // We need this library to use rand()

Board::Board()
{
srand(time(NULL)); 

  for (int x = 0; x<=6 ; x++)
  {
    for (int y = 0; y<=6; y++)
    {
      board[x][y] = new int (rand()%9); 
    }
  }


  // Pd: Here i'm just thinking about an array of numbers or of Gems, dk
  // yet if we are gonna use an int array or a gem array. 
  // Just seeing if its worthy work without * and new delete functions

}

Board::~Board()
{
  //
}

void Board::SetMatrix(Board)
{
  //
}

void Board::ShowMe(/* Condition */)
{
  for (int x = 0; x<=6; x++)
  {
    cout << endl; 
    for (int y = 0; y<=6; y++)
    {
      cout << *board[x][y] << " "; 
    }
  }
} // Simply to see Matrix Status (use it for testing)

void Board::Match(/*Condition*/)
{

}

void Board::fill(/*Condition*/)
{

}

void Board::Move(/*Condition*/)
{

}
