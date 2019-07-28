#ifndef _GEM_H_
#define _GEM_H_
#include "Coordinate.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Gem
{
public:
  Gem(int ident);
  ~Gem();
  int getType();
  void setType();
  void Break();  // This function is used when a gem is deleted.

protected:
private:
int coordinatex;
int coordinatey;
bool mindLock; //     MindGem status
int Type; //          Indicates the kind of gem (there are 6 types of gems)

};
#endif
