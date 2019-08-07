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


void Board::SaveGame(string route)
{
  ofstream file;
  file.open(route.c_str(),ios::out);

  if(file.fail())
  {
    cout << "Couldn't open the file "<< endl;
  }

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

  file << SpaceGem << " ";
  file << RealityGem << " ";
  file << PowerGem << " ";
  file << TimeGem << " ";
  file << SoulGem << " ";
  file << MindGem << " ";
  file << endl;

  for (int y=0;y<7;y++)
  {
    for (int x=0;x<7;x++)
    {
      file << Table[x][y]->getType() << " ";
    }
    file << endl;
  }


  file.close();

}



void Board::Move()
{
  ShowBoard();
  cout << " \n Exit the game? 1. Yes 2. Not" << endl;
  int option;
  cin >>option;
  switch (option)
  {
    case 1:
    return;
    break;

    case 2:
    break;

    default:cout<< "Invalid Option " << endl;
    Move();
    break;
  }

  cout << endl;
  cout << "Let's move. You have to type: || " << endl;
  cout << "|| 1st Column Number || 2nd Line Number || 3st Direction " << endl;
  cin >> locX >> locY >> dir;

  switch(dir)
  {
    int aux, aux1;
    case 'U' : { // To move UP -> Status Complete
      string error;
      error = " \n Movement Failure " << endl;
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
      error = " \n Movement Failure " << endl;
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
      error = " \n Movement Failure " << endl;
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
      error = " \n Movement Failure " << endl;
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
      cout << "\n Direction failure. Try again " << endl;
      Move();
      break;
    }
  }

}
