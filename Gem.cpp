#include <iostream>
#include "Gem.h"

using namespace std;

Gem::Gem(int id)
{
  Type = id;
  mindLock = false;
}

Gem::~Gem()
{

}

int Gem::getType()
{
  return Type;
}

void Gem::Lock()
{
  mindLock = true;
}
