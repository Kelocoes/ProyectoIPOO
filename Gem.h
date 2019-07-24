#ifndef _GEM_H_
#define _GEM_H_

class Gem
{
public:
  Gem();
  ~Gem();
  virtual void Break(); 

protected:
private:
int coordinatex;
int coordinatey;
bool mindLock; //     MindGem status
int Type;

};
#endif
