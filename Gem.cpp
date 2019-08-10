#include <iostream>
#include "Gem.h"

using namespace std;

Gem::Gem(int id)
{
  Type = id; // Number that let you use the gem. 
  mindLock = false; // It starts at false. It starts unlocked. 
}

Gem::~Gem()
{
  //
}


void Gem::setType(int num)
{
  Type = num; 
}
int Gem::getType()
{
  return Type; // Returns the number of gem, in this case: 

  /*
  1 = SpaceGem
  2 = RealityGem
  3 = PowerGem
  4 = TimeGem
  5 = SoulGem
  6 = MindGem 
  */

}

void Gem::Lock()
{
  mindLock = true; // This lock Gem Status
}
