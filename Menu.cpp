#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Menu.h"
#include <time.h>


using namespace std;

Menu::Menu()
{
  //
}

Menu::~Menu()
{

}

void Menu::NewGame(Board Table)
{

Table.Create();
Table.ShowBoard();


}
