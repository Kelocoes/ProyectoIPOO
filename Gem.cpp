#include <iostream>
#include "Gem.h"

using namespace std;

Gem::Gem(int id)
{
  Type = id;
}

Gem::~Gem()
{

}

int Gem::getType()
{
  return Type;
}
