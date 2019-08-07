#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"
#include <string>
#include <string.h>

class Board
{
public:
  Board();
  ~Board();
   void SetMatrix();
   void Match();//Abstraction and //Need a verifier of where the match is happening
   void checkEmpty();//Read matrix and check when there is a void on the matrix
   void positionGems(int i, int j);
   void fill();//When there is a void on the matrix
   void Move();//Movement of the gems
   void pruebasTablero();
   int locX, locY;
   char dir;
  // locX -> X location locY -> Y location dir -> direction
   // UP -> U
   // DOWN -> D
   // RIGHT -> R
   // LEFT -> L
   void Create();
   void ShowBoard();
   void CountGem();
   void SaveGame(string Route);
   //void LoadGame(string namefile);

protected:
// I'll Use a board with integers
private:

 // ---

  char case1, case2, case3, case4;
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
