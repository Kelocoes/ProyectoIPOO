#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"

class Board
{
public:
  Board();
  ~Board();
  virtual void ShowMe(); // Just added to see the Matrix Status
  virtual void SetMatrix(board);
  virtual void Match(/*Condition*/);//Abstraction and //Need a verifier of where the match is happening
  virtual void fill(/*Condition*/);//Where is a void on the matrix
  virtual void Move(/*Condition*/);//Movement of the gems

protected:
// I'll Use a board with integers
gem* board[6][6];
private:

};
#endif
