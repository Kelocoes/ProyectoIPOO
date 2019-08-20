#include <iostream>
#include <string>
#include <fstream>//Files
#include <sstream>
using namespace std;
#include <stdlib.h>
#include "Board.h"
#include <time.h> // We need this library to use rand()
#include "Gem.h"


///////////////////////// BUILDER //////////////////////////////////////
Board::Board(){
  SpaceGem = 0;
  RealityGem = 0;
  PowerGem = 0;
  TimeGem = 0;
  SoulGem = 0;
  MindGem = 0;
  score = 0;
  Movements = 20;
  cicle=0;
}

 ///////////////////////// DESTROYER //////////////////////////////////////
Board::~Board()
{
//
}

///////////////////////// CREATE THE MATRIX //////////////////////////////////////
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


///////////////////////// SHOW THE BOARD //////////////////////////////////////
void Board::ShowBoard()
{
  cout << endl;
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
      cout << Table[x][y]->getType() <<"  ";//Get the Type of each gem and print it on the screen (Number)
    }
    cout << endl;
  }
  cout << "\nMovements left: " <<Movements << endl;
  CountGem(); // When the matrix is printed we are gonna
  // count how much type of gems are.

}


///////////////////////// COUNT THE AMOUNT OF GEMS //////////////////////////////////////
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
  cout << "\nScore: " << score << endl;
  cout << endl;

}

///////////////////////// SAVING THE GAME  //////////////////////////////////////

void Board::SaveGame(string route)
{
  ofstream file;
  file.open(route.c_str(),ios::out);//Open the file

  if(file.fail())//If the code can't open the fail -> Show a message
  {
    cout << "\n Couldn't open the file "<< endl;
  }

  for (int y=0;y<7;y++)//Include the matrix of Gems in the txt file
  {
    for (int x=0;x<7;x++)
    {
      file << Table[x][y]->getType() << " ";
    }
    file << endl;
  }

  file << score;
  file << endl;
  file << Movements;

  file.close();
}

///////////////////////// LOAD THE GAME  //////////////////////////////////////

void Board::LoadGame(string namefile)
{
  ifstream file1;
  file1.open(namefile.c_str(),ios::in);//Open the file

  if(file1.fail())//If the code can't open the fail -> Show a message
  {
    cout << "\n Couldn't open the file "<< endl;
  }

  string text;

  for (int y=0;y<7;y++)
  {
    getline(file1,text);
    int travel=0;
      for (int x=0;x<7;x++)
      {
          if (text[travel]-48==6)
          {
              Table[x][y]=new Gem(6); // Creates a gem
              Table[x][y]->Lock();
          } else
            {
              Table[x][y]=new Gem(text[travel]-48);//Fill the matrix with new objects that differs from each other by a number
            }
            travel+=2;
      }
  }

  double data,data1;
  file1>>text;
  stringstream aux (text);
  aux >> data;
  score=data;


  file1>>text;
  stringstream aux1(text);
  aux1 >> data1;
  Movements=data1;

  file1.close();
}

///////////////////////// MOVE THE GEMS //////////////////////////////////////

void Board::Move()
{
if (score<500 &&Movements!=0)
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

    default:cout<< "\nInvalid Option, try again next time" << endl;
    break;
  }

  cout << endl;
  cout << "Let's move. You have to type:" << endl;
  cout << "|| 1st Column Number || 2nd Line Number || 3st Direction ||" << endl;
  cin >> locX >> locY >> dir;

  if (Table[locX][locY]->getType() == 6) // Is Mindgem touched?
  {
    string advertisement; 
    advertisement = "\n Hey Listen! Gem can't be moved. Try again";
    cout << "----------------------------------------" << endl; 
    cout << advertisement << endl; 
    cout << "----------------------------------------" << endl; 
    Movements--; 
    Move();  
  }
  {
  switch(dir)
  {
    int aux;
    case 'U' : { // To move UP -> Status Complete
      string error;
      error = "\n Movement Failure ";
      if (locY == 0)
      {
        cout << error;
        Movements--;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType(); // We define position number as an aux

      if (locX == 0) // In the case if its at column 0
      {
        if (locY == 1) // In the case if its at line 1
        {
          if (aux == Table[locX+1][locY-1]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
        else
        {
          if (aux == Table[locX+1][locY-1]->getType() || aux == Table[locX][locY-2]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
      } // Here finishes column 0 Possibilities (Borders)
      else
      {
      if (locX == 6) // Here it starst column 6 possibilities (Borders)
      {
        if (locY == 1) // In the case if its at line 1
        {
          if(aux == Table[locX-1][locY-1]->getType()) // Is it at left up?
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
        else // other cases of being at column 6 (borders) but no at 1
        {
          if (aux == Table[locX-1][locY-1]->getType() || aux == Table[locX][locY-2]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX][locY-1];
            Table[locX][locY-1] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
      } // Here finishes column 6 possibilities

      if (locY ==  1) // Cases line 1 except (column 6 and 0)
      {
        if (aux == Table[locX-1][locY-1]->getType() || aux == Table[locX+1][locY-1]->getType())
        {
          Gem* Location = Table[locX][locY];
          Table[locX][locY] = Table[locX][locY-1];
          Table[locX][locY-1] = Location;
          Movements--;
          Match();
        }
        else
        {
          cout << error;
          Movements--;
          Move();
        }
      } // Here finisihes cases for line 1 excepting col 6 and col 0

      else  // CASES FOR ALL THE BOARD EXCEPT BORDERS
      {
        if (aux == Table[locX-1][locY-1]->getType() || aux == Table[locX+1][locY-1]->getType() || aux == Table[locX][locY-2]->getType())
        {
          Gem* Location = Table[locX][locY];
          Table[locX][locY] = Table[locX][locY-1];
          Table[locX][locY-1] = Location;
          Movements--;
          Match();
        }
        else
        {
          cout << error;
          Movements--;
          Move();
        }
      }
      }
      }
      break;
    }

    case 'D' : { // To move DOWN -> Status COMPLETE // ERRORES
      string error;
      error = "\n You cannot do that! ";

      if (locY == 6)
      {
        cout << error;
        Movements--;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locX == 0) // POSSIBILITIES COLUMN 0 BORDER
        {
          if (locY == 5) // It asks for pos 0 5 ->
          {
            if (aux == Table[locX+1][locY+1]->getType())
            {
              Gem* Location = Table[locX][locY];
              Table[locX][locY] = Table[locX][locY+1];
              Table[locX][locY+1] = Location;
              Movements--;
              Match();
            }
            else // Dont do the movement
            {
              cout << error;
              Movements--;
              Move();
            }
          }
          else
          {
            if (aux == Table[locX+1][locY+1]->getType() || aux == Table[locX][locY+2]->getType())
            {
              Gem* Location = Table[locX][locY];
              Table[locX][locY] = Table[locX][locY+1];
              Table[locX][locY+1] = Location;
              Movements--;
              Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
        }

        else
        {
          if(locX == 6) // Column 6 POSSIBILITIES (BORDER)
          {
            if (locY == 5)
            {
              if (aux == Table[locX-1][locY+1]->getType())
              {
                Gem* Location = Table[locX][locY];
                Table[locX][locY] = Table[locX][locY+1];
                Table[locX][locY+1] = Location;
                Movements--;
                Match();
              }
              else
              {
                cout << error;
                Movements--;
                Move();
              }
            }
            else
            {
              if (aux == Table[locX][locY+2]->getType() || aux == Table[locX-1][locY+1]->getType())
              {
                Gem* Location = Table[locX][locY];
                Table[locX][locY] = Table[locX][locY+1];
                Table[locX][locY+1] = Location;
                Movements--;
                Match();
              }
              else
              {
                cout << error;
                Movements--;
                Move();
              }
            }
          }
          else
          {
            if (locY == 5 && locX != 0 && locX !=6) // Case to move when its at line 5
            {
              if (aux == Table[locX-1][locY+1]->getType() || aux == Table[locX+1][locY+1]->getType())
              {
                Gem* Location = Table[locX][locY];
                Table[locX][locY] = Table[locX][locY+1];
                Table[locX][locY+1] = Location;
                Movements--;
                Match();
              }
              else
              {
                cout << error;
                Movements--;
                Move();
              }
            }
            else
            {
              if (aux == Table[locX-1][locY+1]->getType() || aux == Table[locX+1][locY+1]->getType() || aux == Table[locX][locY+2]->getType() )
              {
                Gem* Location = Table[locX][locY];
                Table[locX][locY] = Table[locX][locY+1];
                Table[locX][locY+1] = Location;
                Movements--;
                Match();
              }
              else
              {
                cout << error;
                Movements--;
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
      error = " \n Movement Failure ";
      if (locX == 6)
      {
        cout << error;
        Movements--;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locY == 0)
        {
          if (locX == 5)
          {
            if (aux == Table[locX+1][locY+1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
          else
          {
            if (aux == Table[locX+2][locY]->getType() || aux == Table[locX+1][locY+1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
        } // Finishes of look when its at the border up (upside)
        if (locY == 6)
        {
          if (locX == 5) // Pos 5 6
          {
            if (aux == Table[locX+1][locY-1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
          else
          {
            if (aux == Table[locX+1][locY-1]->getType() || aux == Table[locX+2][locY]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
        }
        if (locX == 5) // In the case for COl 1 except line 0 and 6
        {
          if (aux == Table[locX+1][locY-1]->getType() || aux == Table[locX+1][locY+1]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
        else
        {
          if (aux == Table[locX+1][locY+1]->getType() || aux == Table[locX+1][locY-1]->getType() || aux == Table[locX+2][locY]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX+1][locY];
            Table[locX+1][locY] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
      }
      break;
    }

    case 'L' : { // To move Left -> Status Complete // ERRORES
      string error;
      error = " \n Movement Failure ";
      if (locX == 0)
      {
        cout << error;
        Move();
      }
      else
      {
        aux = Table[locX][locY]->getType();
        if (locY == 0)
        {
          if (locX == 1)
          {
            if (aux == Table[locX-1][locY+1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
          else
          {
            if (aux == Table[locX-2][locY]->getType() || aux == Table[locX-1][locY+1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
        } // Finishes of look when its at the border up (upside)
        if (locY == 6)
        {
          if (locX == 1)
          {
            if (aux == Table[locX-1][locY-1]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
          else
          {
            if (aux == Table[locX-1][locY-1]->getType() || aux == Table[locX-2][locY]->getType())
            {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
            }
            else
            {
              cout << error;
              Movements--;
              Move();
            }
          }
        }
        if (locX == 1) // In the case for COl 1 except line 0 and 6
        {
          if (aux == Table[locX-1][locY-1]->getType() || aux == Table[locX-1][locY+1]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
        else
        {
          if (aux == Table[locX-1][locY+1]->getType() || aux == Table[locX-1][locY-1]->getType() || aux == Table[locX-2][locY]->getType())
          {
            Gem* Location = Table[locX][locY];
            Table[locX][locY] = Table[locX-1][locY];
            Table[locX-1][locY] = Location;
            Movements--;
            Match();
          }
          else
          {
            cout << error;
            Movements--;
            Move();
          }
        }
      }
      break;
  } // Finishes case D

} // Finishes Switch
  }

}else if (Movements==0)
  {
    cout << "\nYOU LOSE, RESTART THE GAME TO PLAY AGAIN \n" << endl;
  }else if (score>=500)
    {
      cout <<"\nYOU WIN. ¡CONGRATULATIONS!, RESTART THE GAME TO PLAY AGAIN \n" << endl;
    }


} // Finishes Move()

void Board::MatchLine()
{
  x = 0;
  y = 0;
  while(y<7)
  {
    if (y == 6)
    {
      if (x == 6)
      {
        y++;
        continue;
      }
      if (Table[x][y]->getType() == Table[x+1][y]->getType() && Table[x][y]->getType() != 6)
      {
        possibleMatchs.push_back(Table[x][y]);
        possibleMatchs.push_back(Table[x+1][y]);
        x++;
        continue;
      }
      else
      {
        x++;
        continue;
      }
    }
    else
    {
      if (x == 6)
      {
        y++;
        x = 0;
        continue;
      }
      else
      {
        if(Table[x][y]->getType() == Table[x+1][y]->getType() && Table[x][y]->getType() != 6)
        {
          possibleMatchs.push_back(Table[x][y]);
          possibleMatchs.push_back(Table[x+1][y]);
          x++;
          continue;
        }
        else
        {
          x++;
          continue;
        }
      }
    }
  }
}

void Board::MatchColumn()
{
  x = 0;
  y = 0;
  while(x < 7)
  {
    if (x == 6)
    {
      if (y == 6)
      {
        x++;
        continue;
      }
      if (Table[x][y]->getType() == Table[x][y+1]->getType() && Table[x][y]->getType() != 6)
      {
        possibleMatchs.push_back(Table[x][y]);
        possibleMatchs.push_back(Table[x][y+1]);
        y++;
        continue;
      }
      else
      {
        y++;
        continue;
      }
    }
    else
    {
      if (y == 6)
      {
        x++;
        y = 0;
        continue;
      }
      else
      {
        if(Table[x][y]->getType() == Table[x][y+1]->getType() && Table[x][y]->getType() != 6)
        {
          possibleMatchs.push_back(Table[x][y]);
          possibleMatchs.push_back(Table[x][y+1]);
          y++;
          continue;
        }
        else
        {
          y++;
          continue;
        }
      }
    }
  }
}

void Board::MatchMind(int x, int y)
{
  // first Line
  if (y == 0)
  {
    if (x == 0)
    {
      if (Table[x+1][y]->getType() == 0 || Table[x+1][y+1]->getType() == 0 || Table[x][y+1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else{
      {
        //
      }}
    }
    else
    {
    if (x == 6)
    {
      if (Table[x-1][y]->getType() == 0 || Table[x-1][y+1]->getType() == 0 || Table[x][y+1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else
      {
        //
      }
    }
    else
    {
      if (Table[x+1][y]->getType() == 0 || Table[x-1][y]->getType() == 0 || Table[x][y+1]->getType() == 0 || Table[x+1][y+1]->getType() == 0 || Table[x-1][y+1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else{}
    }
    } 
  }
  else
  {
  if (y == 6) // Line 6 
  {
    if (x == 0)
    {
      if (Table[x+1][y-1]->getType() == 0 || Table[x+1][y]->getType() == 0 || Table[x][y-1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else {}
    }
    else
    {
      if (x == 6)
      {
        if (Table[x-1][y]->getType() == 0 || Table[x][y-1]->getType() == 0 || Table[x-1][y-1]->getType() == 0)
        {
          Table[x][y]->Lock(); 
        }
        else{}
      }
      else
      {
        if (Table[x][y-1]->getType() == 0 || Table[x-1][y]->getType() == 0 || Table[x+1][y]->getType() == 0 || Table[x+1][y-1]->getType() == 0 || Table[x-1][y-1]->getType() == 0)
        {
          Table[x][y]->Lock(); 
        }
        else {}
      }
    } 
  }
  else
  {
    if (x == 0) // Column 0?
    {
      if (Table[x][y-1]->getType() == 0 || Table[x][y+1]->getType() == 0 || Table[x+1][y]->getType() == 0 || Table[x+1][y-1]->getType() == 0 || Table[x+1][y+1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else {}
    }
    else 
    {
    if (x == 6) // Column 6?
    {
      if (Table[x][y-1]->getType() == 0 || Table[x][y+1]->getType() == 0 || Table[x-1][y]->getType() == 0 || Table[x-1][y-1]->getType() == 0 || Table[x-1][y+1]->getType() == 0)
      {
        Table[x][y]->Lock(); 
      }
      else {}
    }
    else
    {
      if (Table[x][y-1]->getType() == 0 || Table[x][y+1]->getType() == 0 || Table[x-1][y]->getType() == 0 || Table[x-1][y-1]->getType() == 0 || Table[x-1][y+1]->getType() == 0 || Table[x+1][y]->getType() == 0 || Table[x+1][y-1]->getType() == 0 || Table[x+1][y+1]->getType() == 0) // Rest of cases 
      {
        Table[x][y]->Lock(); 
      }
      else{}
    }
    }
    }
  }
}


void Board::Match()
{

  MatchLine(); // This helps to see horizontal matchs
  MatchColumn();  // This helps to search for vertical matchs

  int tamano = possibleMatchs.size();

  for (int x = 0; x<tamano; x++)
  {
    score += possibleMatchs[x]->getType();
    possibleMatchs[x]->setType(0);
  }
  for(int y = 0; y<7; y++)
  {
    for(int x = 0; x<7; x++)
    {
      if (Table[x][y]->getMind() == 1)
      {
        MatchMind(x , y); 
      }
      else 
      {
        if (Table[x][y]->getMind() == 2)
        {
          score+=6;
          Table[x][y]->setType(0);
        }
      }
    }
  }


  ShowBoard();
  checkEmpty();
  ShowBoard();
  fill();
}

void Board::positionGems(int i, int j){

    Table[i][j+1]=Table[i][j];

    Table[i][j]= new Gem (0);
}

void Board::checkEmpty(){

    for(int j=6;j>=0;j--){
        for(int i=6;i>=0;i--){
            if( j >= 0 && j < 6 && i >= 0 && i < 7 && (Table[i][j]->getType()!= 0) ){

                do{
                if(Table[i][j+1]->getType()== 0){

                    positionGems(i, j);
                    j+=1;
                }

            }while((i >= 0 && i < 7 && j >= 0 && j < 6) && Table[i][j+1]->getType()== 0 );
         }
       }
    }
}

void Board::fill(){

    srand (time(NULL));

    for(int i=0; i<7; i++){
        for(int j=0; j<7; j++){
            if( i >= 0 && i < 7 && j >= 0 && j < 7 && (Table[i][j]->getType()== 0) ){
                if (rand()%100<5){
                    delete Table[i][j];
                    Table[i][j]= new Gem(6);
                    Table[i][j]->Lock(); 
                } else{
                    delete Table[i][j];
                    Table[i][j]=new Gem((rand()%5)+1);
                }
            }
        }
    }
    // Clean the vector called possibleMatchs
    //

    possibleMatchs.clear();
    // When it does:
    Move();
}