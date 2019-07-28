#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"

class Board
{
public:
  Board();
  ~Board();
   void SetMatrix();
   void Match(/*Condition*/);//Abstraction and //Need a verifier of where the match is happening
   void fill(/*Condition*/);//Where is a void on the matrix
   void Move(/*Condition*/);//Movement of the gems


protected:
// I'll Use a board with integers
private:
  //
};
#endif
