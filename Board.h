/**
* @file Board.h
* @version 1.0
* @date 08/09/2019
* @author Grupo04
* @title Tablero
* @brief Functions who helps playing and moving around the Matrix 
*/
#ifndef _BOARD_H_
#define _BOARD_H_
#include "Gem.h"
#include <string>
#include <string.h>
#include <vector>

class Board
{
public:
  /**
  * @brief  Board() Builder method. Starts Gems and all the movements
  * @param void
  * @return void
  */
  Board(); // Builder 

  /**
  * @brief  ~Board() breaker
  * @param void
  * @return void
  */
  ~Board();
  /**
  * @brief  SetMatrix()
  * @param void
  * @return void
  */
   void SetMatrix();
   /**
  * @brief  Match() Erases gems and update the score 
  * @param void
  * @return void
  */
   void Match(); // Helps to erase gems and update score 

/**
  * @brief  MatchColumn() Auxiliar function of Match. Works with possibleMatchs
  * @param void
  * @return void
  */

   void MatchColumn(); // Auxiliar function of Match()

   /**
  * @brief  MatchLine() Auxiliar function of Match. Works with possibleMatchs
  * @param void
  * @return void
  */

   void MatchLine(); // Auxiliar function of Match()

/**
  * @brief  Move() Important function. It lets you move the gems

  * @param void
  * @return void
  */

   void Move();//Movement of the gems

//

/**
  * @brief  checkEmpty() Read matrix and check when there is a void on the matrix. Add gravity to board.
  * @param void
  * @return void
  */

  void checkEmpty();//Read matrix and check when there is a void on the matrix

  /**
  * @brief  positionGems(int i, int j) Auxiliar funcion of checkEmpty
  * @param i, j (Numbers)
  * @return void
  */

  void positionGems(int i, int j);

  /**
  * @brief  fill() Function who add new gems on void spaces. 
  * @param void
  * @return void
  */

  void fill();//When there is a void on the matrix

//
   int locX, locY; // Auxiliars to move around the Matrix
   char dir; // IDENTIFIER -> 
  // locX -> X location locY -> Y location dir -> direction
   // UP -> U
   // DOWN -> D
   // RIGHT -> R
   // LEFT -> L

   /**
  * @brief  Create() Starter function. Generate a random Matrix of gems. 
  * @param void
  * @return void
  */

   void Create(); // Generate a random Matrix of gems
 
   /**
  * @brief  ShowBoard() Function who shows the generated Matrix and number per gem.  
  * @param void
  * @return void
  */

   void ShowBoard(); // This function show the generated matrix

   /**
  * @brief  CountGem() Auxiliar function of ShowBoard, cound each type of gem.   
  * @param void
  * @return void
  */

   void CountGem(); // Auxiliar function of ShowBoard, counts 
   // Each type of gem 

   /**
  * @brief  SaveGame() Save the current Matrix in a .txt file called "File"  
  * @param void
  * @return void
  */

   void SaveGame(string Route); // Save the current matrix in a .txt file called "File"

   /**
  * @brief  LoadGame() Load a Matrix saved in a .txt file called "File" and all the movements and score done.
  * @param void
  * @return void
  */

   void LoadGame(string namefile);
   int Movements;

   /**
  * @brief  possibleMatchs vector who saves all the positions where match is happening. 
  
  */

   vector <Gem*>  possibleMatchs; // Auxiliar vector of Match()


   int x; // Definition of positions of Matrix Recursive -> Match
   int y; // Definition of positions of Matrix Recursive -> Match

   int score; // The points per gem.

  /**
  * @brief  MatchMind(int x, int y) Exclusive match for only gems type 6 (Mindgem)
  * @param x, y Numbers who made together a location on the matrix. 
  * @return void
  */

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
