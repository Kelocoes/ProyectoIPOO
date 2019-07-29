#include <iostream>
using namespace std;
#include <stdlib.h>
#include "Board.h"
#include <time.h> // We need this library to use rand()

Board::Board(){
    MindGem=0;
    SpaceGem=0;
    RealityGem=0;
    TimeGem=0;
    SoulGem=0;
    PowerGem=0;
    
  ifstream archivo("archivo.txt");
  int nivel;
  int tiempo;

  archivo>>nivel>>tiempo;
  cout<<"Nivel: "<<nivel<<endl;
  cout<<"Tiempo del juego: "<<tiempo<<" seg\n";
}

Board::~Board()
{

  //Esto es una prueba
}

void Board::Create()
{

  srand (time(NULL));//New random integer that depends on PC time
for (int y=0;y<7;y++)
{
  for (int x=0;x<7;x++)
  {
    if (rand()%100<5)
      {
        Table[x][y]=new Gem(6);
        Table[x][y]->Lock();
      }else
      Table[x][y]=new Gem((rand()%5)+1);//Fill the matrix with new objects that differs from
      //each other by a number
  }
}


}

void Board::ShowBoard()
{
int fila=0;

  cout <<"           "<<"------------------------"<<endl;
  cout <<"           "<<"|  0  1  2  3  4  5  6 |"<<endl;
  cout <<"           "<<"------------------------"<<endl;


  for (int y=0;y<7;y++)
  {
    cout <<"       | " <<fila <<" |:"<<" ";
    fila++;
    for (int x=0;x<7;x++)
    {
      cout << Table[x][y]->getType()<<"  ";//Get the Type of each gem and print it on the screen
    }
    cout << endl;
  }
  CountGem();
}


void Board::CountGem()
{
  for (int y=0;y<7;y++)
  {
    for (int x=0;x<7;x++)
    {
      switch (Table[x][y]->getType())
      {
        case 1:
        SpaceGem++;
        break;

        case 2:
        RealityGem++;
        break;

        case 3:
        PowerGem++;
        break;

        case 4:
        TimeGem++;
        break;

        case 5:
        SoulGem++;
        break;

        case 6:
        MindGem++;
        break;
      }
    }
  }

  cout << "\n1. SpaceGems: " << SpaceGem << "|| ";
  cout << "2. RealityGems: " << RealityGem << "|| ";
  cout << "3. PowerGems: " << PowerGem << "|| " << endl;
  cout << "4. TimeGems: " << TimeGem << "|| ";
  cout << "5. SoulGems: " << SoulGem << "|| ";
  cout << "6. MindGems: " << MindGem << "|| ";
}
