/**
* @file Gem.h
* @version 1.0
* @date 08/09/2019
* @author Grupo04
* @title Gema
* @brief Functions who define and explain how gems works 
*/
#ifndef _GEM_H_
#define _GEM_H_
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Gem
{
public:

/**
  * @brief  Gem(int ident) Builder method. It receives an identifier to recognize what gem is it
  * @param ident (number who classify the gem)
  * @return void
  */

  Gem(int ident); // Builder 
  // it receives and identifier to recognize what gem is it 
  /*
  1 - SpaceGem
  2 - RealityGem
  3 - PowerGem 
  4 - TimeGem
  5 - SoulGem
  6 - MindGem
  */

  /**
  * @brief  ~Gem() Destructor
  * @param void
  * @return void
  */

  ~Gem(); // Destructor 

  /**
  * @brief getType() returns the number what identifies the type
  * @param void
  * @return number (Type of gem)
  */

  int getType(); // Returns the number what identifies the type

  /**
  * @brief  setType(int num)  establishes the type of gem with the num added to function
  * @param num (identifier)
  * @return void
  */

  void setType(int num);

  /**
  * @brief  Break() Function is used when a gem is deleted.
  * @param void
  * @return void
  */

  void Break();  // This function is used when a gem is deleted.

   /**
  * @brief Lock() changes mindlock attribute  
  * @param void
  * @return void
  */

  void Lock(); // Changes mindLock attribute

  // New functions

   /**
  * @brief  int getMind() Helps to see if a gem its blocked
  * @param void
  * @return number (betweem 0 - 2)
  */

  int getMind(); // Helps to see if a gem its blocked 

protected:
private:

int mindLock; //     MindGem status (if its available to use)
int Type; //          Indicates the kind of gem (there are 6 types of gems)

};
#endif
