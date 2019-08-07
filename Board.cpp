#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#include <stdlib.h>
#include "Board.h"
#include <time.h> // We need this library to use rand()

Board::Board(){
  SpaceGem = 0;
  RealityGem = 0;
  PowerGem = 0;
  TimeGem = 0;
  SoulGem = 0;
  MindGem = 0;
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


  for (int x=0;x<7;x++)
  {
    cout <<"       | " <<fila <<" |:"<<" ";
    fila++;
    for (int y=0;y<7;y++)
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
  SpaceGem = 0;
  RealityGem = 0;
  PowerGem = 0;
  TimeGem = 0;
  SoulGem = 0;
  MindGem = 0;

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

}

void Board::Move()
{
  ShowBoard();
  cout << "Exit the game? 1. Yes 2. Not" << endl;
  int option;
  cin >>option;
  switch (option)
  {
    case 1:
    return;
    break;

    case 2:
    break;
  }

  cout << endl;
  cout << "Let's move. You have to type: || " << endl;
  cout << "|| 1st Line Number || 2nd Column Number || 3st Direction " << endl;
  cin >> locX >> locY >> dir;

  switch(dir)
  {
    int aux, aux1;
    case 'U' : { // To move UP -> Status Complete
      string error;
      error = "Movement Failure";
      if (locY-1<0)
      {
        cout << error;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locY-1==0)
        {
          if ( aux == Table[locX+1][locY-1]->getType() ||
               aux == Table[locX-1][locY-1]->getType() )
               {
             Gem* Location = Table[locX][locY];
             Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Move();
               }
          else
          {
            cout << error;
            Move();
          }
        }
        else {
          if (locX == 6 && ((aux == Table[locX][locY-2]->getType())||(aux ==Table[locX-1][locY-1]->getType())))
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Move();
          }
          else
          if (locX == 0 && ((aux == Table[locX][locY-2]->getType())||(aux == Table[locX+1][locY-1]->getType())))
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Move();
          }
          else
          {
          {
          if ( aux == Table[locX+1][locY-1]->getType() ||
               aux == Table[locX-1][locY-1]->getType() ||
               aux == Table[locX][locY-2]->getType() )
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Move();
          }
          else {
            cout << error;
            Move();
          }
          }
          }
        }
      }
    break;
    }

    case 'D' : { // To move DOWN -> Status COMPLETE
      string error;
      error = "Movement Failure";
      if (locY+1>6)
      {
        cout << error;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locY+1==6) // It verifies in case there's in line 5
        {
          if ( aux == Table[locX+1][locY+1]->getType() || // Right side
               aux == Table[locX-1][locY+1]->getType() )  // Left Side
               {
             Gem* Location = Table[locX][locY];
             Table[locX][locY] = Table[locX][locY+1];
            Table[locX][locY+1] = Location;
            Move();
               }
          else
          {
            cout << error;
            Move();
          }
        }
        else {
          if (locX == 6 &&  ((aux == Table[locX][locY+2]->getType())||(aux ==Table[locX-1][locY+1]->getType()))) // Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY+1];
            Table[locX][locY+1] = Location;
            Move();
          }
          else
          if (locX == 0 && ((aux == Table[locX][locY+2]->getType())||(aux == Table[locX+1][locY+1]->getType())))// Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Move();
          }
          else
          {
          { // Other cases to move, around the table
          if ( aux == Table[locX+1][locY+1]->getType() ||
               aux == Table[locX-1][locY+1]->getType() ||
               aux == Table[locX][locY+2]->getType() )
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY+1];
            Table[locX][locY+1] = Location;
            Move();
          }
          else {
            cout << error;
            Move();
          }
          }
          }
        }
      }
    break;
    }

    case 'R' : { // To move RIGHT -> Status Complete
      string error;
      error = "Movement Failure";
      if (locX+1>6) // It verifies if its at column 6
      {
        cout << error; // Prints Failure
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locX+1==6) // It verifies if its at column 5
        {
          if ( aux == Table[locX+1][locY+1]->getType() || // Down Side
               aux == Table[locX+1][locY-1]->getType() )   // Up side
               {
             Gem* Location = Table[locX][locY];
             Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Move();
               }
          else
          {
            cout << error;
            Move();
          }
        }
        else {
          if (locY == 6 && ((aux == Table[locX+1][locY-1]->getType())||(aux ==Table[locX+2][locY]->getType()))) // Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Move();
          }
          else
          if (locY == 0 && ((aux == Table[locX+1][locY+1]->getType())||(aux == Table[locX+2][locY]->getType()))) // Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Move();
          }
          else
          {
          { // Other movements possibilities
          if ( aux == Table[locX+1][locY-1]->getType() ||
               aux == Table[locX+1][locY+1]->getType() ||
               aux == Table[locX+2][locY]->getType() )
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Move();
          }
          else {
            cout << error;
            Move();
          }
          }
          }
        }
      }
    break;
    }

    case 'L' : { // To move Left -> Status Complete
      string error;
      error = "Movement Failure";
      if (locX-1<0) // It verifies if its at column 0
      {
        cout << error; // Prints Failure
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locX-1==0) // It verifies if its at column 1
        {
          if ( aux == Table[locX-1][locY+1]->getType() || // Down Side
               aux == Table[locX-1][locY-1]->getType() )   // Up side
               {
             Gem* Location = Table[locX][locY];
             Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Move();
               }
          else
          {
            cout << error;
            Move();
          }
        }

        else {
          if (locY == 6 && ((aux == Table[locX-1][locY-1]->getType())||(aux ==Table[locX-2][locY]->getType()))) // Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Move();
          }
          else
          if (locY == 0 && ((aux == Table[locX-1][locY+1]->getType())||(aux == Table[locX-2][locY]->getType()))) // Borders
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Move();
          }
          else
          {
          { // Other movements possibilities
          if ( aux == Table[locX-1][locY-1]->getType() ||
               aux == Table[locX-1][locY+1]->getType() ||
               aux == Table[locX-2][locY]->getType() )
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Move();
          }
          else {
            cout << error;
            Move();
          }
          }
          }
        }
      }
    break;
    }

    default : {
      cout << "Direction failure. Try again " << endl;
      Move();
      break;
    }
  }

}
//Metodo para hacer pruebas, cuando terminemos el juego, se elimina 
/*
void Board::pruebasTablero(){
    
    Table[0][0]= new Gem (1);
    Table[0][1]= new Gem (1);
    Table[0][2]= new Gem (1);
    Table[0][3]= new Gem (1);
    Table[0][4]= new Gem (1);
    Table[0][5]= new Gem (1);
    Table[0][6]= new Gem (1);
    Table[1][0]= new Gem (1);
    Table[1][1]= new Gem (1);
    Table[1][2]= new Gem (1);
    Table[1][3]= new Gem (0);
    Table[1][4]= new Gem (0);
    Table[1][5]= new Gem (0);
    Table[1][6]= new Gem (1);
    Table[2][0]= new Gem (1);
    Table[2][1]= new Gem (1);
    Table[2][2]= new Gem (1);
    Table[2][3]= new Gem (1);
    Table[2][4]= new Gem (0);
    Table[2][5]= new Gem (0);
    Table[2][6]= new Gem (1);
    Table[3][0]= new Gem (1);
    Table[3][1]= new Gem (1);
    Table[3][2]= new Gem (1);
    Table[3][3]= new Gem (1);
    Table[3][4]= new Gem (0);
    Table[3][5]= new Gem (0);
    Table[3][6]= new Gem (1);
    Table[4][0]= new Gem (1);
    Table[4][1]= new Gem (1);
    Table[4][2]= new Gem (1);
    Table[4][3]= new Gem (0);
    Table[4][4]= new Gem (0);
    Table[4][5]= new Gem (1);
    Table[4][6]= new Gem (1);
    Table[5][0]= new Gem (1);
    Table[5][1]= new Gem (1);
    Table[5][2]= new Gem (0);
    Table[5][3]= new Gem (0);
    Table[5][4]= new Gem (0);
    Table[5][5]= new Gem (0);
    Table[5][6]= new Gem (1);
    Table[6][0]= new Gem (1);
    Table[6][1]= new Gem (1);
    Table[6][2]= new Gem (1);
    Table[6][3]= new Gem (1);
    Table[6][4]= new Gem (1);
    Table[6][5]= new Gem (1);
    Table[6][6]= new Gem (1);  
}
*/ 

void Board::positionGems(int i, int j){
    
    Table[i+1][j]=Table[i][j];
    
    Table[i][j]= new Gem (0);
    
}
    


void Board::checkEmpty(){
    
    for(int i=6;i>=0;i--){
        for(int j=6;j>=0;j--){
            if( i >= 0 && i < 6 && j >= 0 && j < 7 && (Table[i][j]->getType()!= 0) ){
                
                do{
                if(Table[i+1][j]->getType()== 0){
                    
                    positionGems(i, j);
                    i+=1;
                }
                
            }while((i >= 0 && i < 7 && j >= 0 && j < 7) && Table[i+1][j]->getType()== 0 );
         }
       }
    }
    
}

void Board::fill(){
    
    srand (time(NULL));
    
    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if( i >= 0 && i < 7 && j >= 0 && j < 7 && (Table[i][j]->getType()== 0) ){
                
                Table[i][j]=new Gem((rand()%5)+1);
         }
       }
    }
    
}

//GETTERS
int Board::getSpaceGem()
{
    
  return SpaceGem;
}

int Board::getMindGem()
{
  return MindGem;
}

int Board::getRealityGem()
{
  return PowerGem;
}

int Board::getPowerGem()
{
  return TimeGem;
}

int Board::getTimeGem()
{
  return SoulGem;
}

int Board::getSoulGem()
{
  return MindGem;
}
