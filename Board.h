#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"
#include <string>
#include <string.h>
#include <vector>

class Board
{
public:
  Board();
  ~Board();
   void SetMatrix();
   void pruebasTablero();
   void Match();
   void MatchColumn();
   void MatchLine();

   void Move();//Movement of the gems

//
  void checkEmpty();//Read matrix and check when there is a void on the matrix
  void positionGems(int i, int j);
  void fill();//When there is a void on the matrix
//
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
   void LoadGame(string namefile);

   vector <string>  possibleMatchs;

   int x; // Definition of positions of Matrix Recursion -> Match
   int y; // Definition of positions of Matrix Recursion -> Match

   int score; // The points per gem.


protected:
// I'll Use a board with integers
private:

 // ---

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
