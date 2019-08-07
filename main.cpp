#include <iostream>
using namespace std;
#include "Menu.h"
#include "Board.h"
#include <string.h>
#define LIMPIAR cout<<"\E[H\E[2J"; // To clean history on console

int main(){
// We print options to play through the game
cout << "THANOS PUZZLE" << endl;
cout << "1. New Game" << endl;
cout << "2. Load Game" << endl;
cout << "3. Exit" << endl;

int option;
cin >> option; // Insert an option

Menu Start;
Board Table;

switch (option)
  {
    case 1:
    Start.NewGame(Table); //
    cout << "\n Game has been saved" << endl;
    Start.SaveGame("File.txt",Table);
    cin.get();
    break;

    case 2:
    //
    break;

    case 3:
    //
    break;
    default:cout<< "Invalid Option";
    break;
  }

 cin.get();
 return 0;
    /*Prueba de rellenar despues del match
    Board tablero;
    tablero.pruebasTablero();
    tablero.ShowBoard();
    tablero.checkEmpty();
    tablero.fill();
    tablero.ShowBoard();
     */
}