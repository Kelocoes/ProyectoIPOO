#ifndef _MENU_H_
#define _MENU_H_
#include "Board.h"
#include "Gem.h"
#include <string>
using namespace std;

class Menu
{
public:
  Menu();
  ~Menu();
  // Here we are defining functions from class called Menu
  // We gotta use virtual to work with polymorphism
  void ShowBoard();
  void NewGame();//Create a new matrix with different gem types
  void LoadGame(); //Upload a txt file to load a level
  void SaveGame(); //Save the current progress from the user
  void Stats(); // Let you know the score and movements left

protected:
//
private:
  Gem* Table[7][7];//Pointers Pointing to gem objets
//
};
#endif
