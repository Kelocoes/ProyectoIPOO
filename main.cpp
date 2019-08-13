#include <iostream>
using namespace std;
#include "Board.h"
#include <string.h>
#define LIMPIAR cout<<"\E[H\E[2J"; // To clean history on console

int main(){
// We print options to play through the game
cout << "████████╗██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ███████╗ ██████╗  █████╗ ███╗   ███╗███████╗" << endl; 
cout << "╚══██╔══╝██║  ██║██╔══██╗████╗  ██║██╔═══██╗██╔════╝██╔════╝ ██╔══██╗████╗ ████║██╔════╝" << endl; 
cout << "   ██║   ███████║███████║██╔██╗ ██║██║   ██║███████╗██║  ███╗███████║██╔████╔██║█████╗" << endl; 
cout << "   ██║   ██╔══██║██╔══██║██║╚██╗██║██║   ██║╚════██║██║   ██║██╔══██║██║╚██╔╝██║██╔══╝  " << endl;
cout << "   ██║   ██║  ██║██║  ██║██║ ╚████║╚██████╔╝███████║╚██████╔╝██║  ██║██║ ╚═╝ ██║███████╗" << endl; 
cout << "   ╚═╝   ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚══════╝ ╚═════╝ ╚═╝  ╚═╝╚═╝     ╚═╝╚══════╝" << endl; 
cout << endl; 
cout << "1. New Game" << endl;
cout << "2. Load Game" << endl;
cout << "3. Exit" << endl;

int option;
cin >> option; // Insert an option

Board Table;

switch (option)
  {
    case 1:
    Table.score=0;
    Table.Create();
    Table.Move();
    Table.SaveGame("File.txt");
    cout << "The game has been saved" << endl;
    cin.get();
    break;

    case 2:
    cout << "\n THE GAME HAS BEEN LOADED " << endl;
    Table.LoadGame("File.txt");
    Table.Move();
    Table.SaveGame("File.txt");
    cout << "The game has been saved" << endl;
    cin.get();
    break;

    case 3:
    exit(0);
    break;
    default:cout<< "Invalid Option, restart the game";
    cin.get();
    break;
  }
    cin.get();
    return 0;
  /*
    Board tablero;
    tablero.pruebasTablero();
    tablero.Move();
    tablero.Match();
    tablero.checkEmpty();
    tablero.fill();
    tablero.ShowBoard();
   */
}