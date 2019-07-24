#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"

class Board
{
Public:
  Board();
  ~Board();
  virtual void SetMatrix(board);
  virtual void Match(/*Condition*/);//Abstraction and //Need a verifier of where the match is happening
  virtual void fill(/*Condition*/);//Where is a void on the matrix
  virtual void Move(/*Condition*/);//Movement of the gems

Protected:
Gem board [6][6];
Private:

};
#endif
