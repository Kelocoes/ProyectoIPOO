#include <iostream>
#include <string>
#include <fstream>
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
  cout<<"Level:  "<<nivel<<endl;
  cout<<"Time:  "<<tiempo<<" seg\n";
}

Board::~Board()
{

}

void Board::Create(){

  srand (time(NULL));//New random integer that depends on PC time
  for (int y=0;y<7;y++){
      for (int x=0;x<7;x++){
          if (rand()%100<5){
              Table[x][y]=new Gem(6); // Creates a gem
              Table[x][y]->Lock();
          } else
            Table[x][y]=new Gem((rand()%5)+1);//Fill the matrix with new objects that differs from
      //each other by a number
      }
  }
}

void Board::ShowBoard()
{
int fila=0; // This variable helps to print each line

  cout <<"           "<<"------------------------"<<endl;
  cout <<"           "<<"|  0  1  2  3  4  5  6 |"<<endl;
  cout <<"           "<<"------------------------"<<endl;


  for (int y=0;y<7;y++)
  {
    cout <<"       | " <<fila <<" |:"<<" ";
    fila++;
    for (int x=0;x<7;x++)
    {
      cout << Table[x][y]->getType()<<"  ";//Get the Type of each gem and print it on the screen (Number)
    }
    cout << endl;
  }
  CountGem(); // When the matrix is printed we are gonna 
  // count how much type of gems are. 
}


void Board::CountGem() // Here we define the Gem Counter
{
  for (int y=0;y<7;y++) // It cross through all the line to see
  // what king of gems are here. 
  {
    for (int x=0;x<7;x++)
    {
      switch (Table[x][y]->getType()) // It finds the Gem type and 
                              // for each position. 
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

// Here we are printing the number of gems per type. 
  cout << "\n1. SpaceGems: " << SpaceGem << "|| ";
  cout << "2. RealityGems: " << RealityGem << "|| ";
  cout << "3. PowerGems: " << PowerGem << "|| " << endl;
  cout << "4. TimeGems: " << TimeGem << "|| ";
  cout << "5. SoulGems: " << SoulGem << "|| ";
  cout << "6. MindGems: " << MindGem << "|| ";
  cout << endl; 
  
  cout << "Just to see if u can move a gem" << endl; 
  canThey(); 
  
}

/* 
Cree cases para cada caso de la gema
case1 = para moverse arriba
case2 = para moverse abajo
case3 = moverse izq 
case4 = moverse der

---
*/

void Board::canThey()
{
  cout << "Insert location: " << endl;
  
  cout << " || 1st space line || 2nd space column ||" << endl; 
  cin >> locX >> locY; 
  int cases; 
  
for(cases = 0; cases<4; cases++)
{
  switch(cases)
  {
    case 0 : { // Possible Matchs up the gem 
    
      if (locY-2<0)
      {
        case1 = false; 
      }
      else
      {
      
        int aux = Table[locX][locY-1]->getType();
        if (
          (aux == Table[locX][locY-2]->getType()) || // Is it up?
          (aux == Table[locX+1][locY-1]->getType()) || // Is it left?
          (aux == Table[locX-1][locY-1]->getType()) )// Is it right?
          {
          case1 = true; 
          }
        else 
        {
          case1 = false;
        }
        }
        break;
    }
        
       

    case 1 : { // Possible Matchs down the gem
    
      if (locY+2>7)
      {
        case2 = false; 
      }
      else
      {
        
        int aux = Table[locX][locY+1]->getType(); 
        if (
          (aux == Table[locX][locY+2]->getType()) || // Is it down?
          (aux == Table[locX+1][locY+1]->getType()) || // Is it left?
          (aux == Table[locX-1][locY+1]->getType()) )// Is it right?
          {
            case2 = true; 
          }
        else 
        {
          case2 = false; 
        } 
      }
    break; 
    }

    case 2 : { // Possible Matchs left the gem
    
    if (locX+2>7)
    {
      case3 = false; 
    }
    else 
    {
      
      int aux = Table[locX+1][locY]->getType(); 
      if(
        (aux == Table[locX+1][locY+1]->getType()) || // Is it down?
        (aux == Table[locX+2][locY]->getType()) || // Is it left?
        (aux == Table[locX+1][locY-1]->getType()) ) // Is it up?
        {
        case3 = true; 
        }
      else {
        case3 = false; 
      }
    }
    break; 
    }

    case 3 : { // Possible Matchs right to the Gem
    
      if (locX-2<0)
      {
        case4 = false;
      }
      else 
      {
      
        int aux = Table[locX-1][locY]->getType();
        if (
        (aux == Table[locX-1][locY+1]->getType()) || // Is it down?
        (aux == Table[locX-2][locY]->getType()) || // Is it right?
        (aux == Table[locX-1][locY-1]->getType()) ) // Is it up?
        {
          case4 = true; 
        }
        else 
        {
          case4 = false;
        }
      }
    break; 
    }
  }
}

cout << "You can do these movements" << endl; 
if (case1 == true)
{
  cout << "Move it up" << endl; 
}
if (case2 == true)
{
  cout << "Move it down" << endl; 
}
if (case3 == true)
{
  cout << "Move it left" << endl;
}
if (case4 == true)
{
  cout << "Move it right" << endl; 
}

}