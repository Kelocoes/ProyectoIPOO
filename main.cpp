#include <iostream>
using namespace std;
#include "Menu.h"
#include "Board.h"
#include <string.h>
#define LIMPIAR cout<<"\E[H\E[2J";

int main(){

cout << "THANOS PUZZLE" << endl;
cout << "1. New Game" << endl;
cout << "2. Load Game" << endl;
cout << "3. Exit" << endl;

int option;
cin >> option;

Menu Start;

switch (option)
  {
    case 1:
    Start.NewGame();
    cin.get();
    break;

    case 2:
    //
    break;

    case 3:
    //
    break;
    default:cout<< "Opción no válida";
    break;
  }

cin.get();
  return 0;
}
