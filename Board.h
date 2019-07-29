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
   void Create();
   void ShowBoard();
   void CountGem();

protected:
// I'll Use a board with integers
private:
  Gem* Table[7][7];//Pointers Pointing to gem objets
  //
  int SpaceGem;//1
  int RealityGem;//2
  int PowerGem;//3
  int TimeGem;//4
  int SoulGem;//5
  int MindGem;//6
};
#endif
