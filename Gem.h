#ifndef _GEM_H_
#define _GEM_H_

class Gem
{
Public:
  Gem();
  ~Gem();
  virtual void Break();

Protected:
private:
int coordinatex;
int coordinatey;
bool mindlock;
int Type;

};
#endif
