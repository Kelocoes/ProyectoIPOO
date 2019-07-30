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
   void fill(/*Condition*/);//When there is a void on the matrix
   void Move(/*Condition*/);//Movement of the gems
   void canThey(); 
   void Create();
   void ShowBoard();
   void CountGem();

protected:
// I'll Use a board with integers
private:
// Locations to move around the board: 
  int locX; 
  int locY; 
  // ---
  
  bool case1, case2, case3, case4; 
  /* Helps to see the cases to move
  case1 = up
  case2 = down
  case3 = left 
  case4 = right

  */
  Gem* Table[7][7];//Pointers Pointing to gem objets
  //
  // Each gem is clasified by a number. We can recognise the gems by: 
  int SpaceGem;//1
  int RealityGem;//2
  int PowerGem;//3
  int TimeGem;//4
  int SoulGem;//5
  int MindGem;//6
};
#endif
