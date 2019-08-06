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
Table.Move();

}

void Menu::SaveGame(string namefile,Board table)
{
  ofstream file;
  file.open(namefile.c_str(),ios::out);

  if(file.fail())
  {
    cout << "Couldn't open the file "<< endl;
  }

  file << table.getSpaceGem()<< endl;
  file << table.getRealityGem()<< endl;
  file << table.getPowerGem()<< endl;
  file << table.getTimeGem()<< endl;
  file << table.getSoulGem()<< endl;
  file << table.getMindGem()<< endl;
  /*
  for (int y=0;y<7;y++)
  {
    for (int x=0;x<7;x++)
    {
      file << "Hola" << " ";
    }
    file<< endl;
  }*/

  file.close();
}
