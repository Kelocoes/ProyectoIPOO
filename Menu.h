#ifndef _MENU_H_
#define _MENU_H_
#include "Board.h"

class Menu
{
public:
  Menu();
  ~Menu();
  virtual void ShowBoard();
  virtual void LoadGame(archivo);
  virtual void SaveGame();
  virtual void Info();

protected:
private:

};
#endif
