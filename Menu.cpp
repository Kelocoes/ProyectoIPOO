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

void Menu::NewGame()
{
  srand (time(NULL));//New random integer that depends on PC time
  for (int y=0;y<7;y++)
  {
    for (int x=0;x<7;x++)
    {
      Table[x][y]=new Gem((rand()%6)+1);//Fill the matrix with new objects that differs from
      //each other by a number
    }
  }
  ShowBoard();//Show the matrix
}

void Menu::ShowBoard()
{

  for (int y=0;y<7;y++)
  {
    for (int x=0;x<7;x++)
    {
      cout << Table[x][y]->getType()<<"  ";//Get the Type of each gem and print it on the screen
    }
    cout << endl;
  }
}
