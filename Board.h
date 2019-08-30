#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"
#include <string>
#include <string.h>
#include <vector>

class Board
{
public:
  Board(); // Builder 
  ~Board();
   void SetMatrix();
   void Match(); // Helps to erase gems and update score 
   void MatchColumn(); // Auxiliar function of Match()
   void MatchLine(); // Auxiliar function of Match()

   void Move();//Movement of the gems

//
  void checkEmpty();//Read matrix and check when there is a void on the matrix
  void positionGems(int i, int j);
  void fill();//When there is a void on the matrix
//
   int locX, locY; // Auxiliars to move around the Matrix
   char dir; // IDENTIFIER -> 
  // locX -> X location locY -> Y location dir -> direction
   // UP -> U
   // DOWN -> D
   // RIGHT -> R
   // LEFT -> L
   void Create(); // Generate a random Matrix of gems
   void ShowBoard(); // This function show the generated matrix
   void CountGem(); // Auxiliar function of ShowBoard, counts 
   // Each type of gem 
   void SaveGame(string Route); // Save the current matrix in a .txt file called "File"
   void LoadGame(string namefile);
   int Movements;
   vector <Gem*>  possibleMatchs; // Auxiliar vector of Match()


   int x; // Definition of positions of Matrix Recursive -> Match
   int y; // Definition of positions of Matrix Recursive -> Match

   int score; // The points per gem.

   // New Functions
   void MatchMind(int x, int y);  


protected:

private:

 // ---

  Gem* Table[7][7];//Pointers Pointing to gem objets
  
  // Each gem is clasified by a number. We can recognise the gems by:
  int SpaceGem;//1
  int RealityGem;//2
  int PowerGem;//3
  int TimeGem;//4
  int SoulGem;//5
  int MindGem;//6
  int cicle;
};
#endif
