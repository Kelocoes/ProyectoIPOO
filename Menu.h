#ifndef _MENU_H_
#define _MENU_H_

class Menu
{
public:
  Menu();
  ~Menu();
  // Here we are defining functions from class called Menu
  // We gotta use virtual to work with polymorphism 
  virtual void ShowBoard(); 
  virtual void LoadGame(file); //   Upload a txt file to load a level
  virtual void SaveGame(); //       Save the current progress from the user 
  virtual void Help(); //           Let you know how to play the game (controls)

protected:
//
private:
//
};
#endif
