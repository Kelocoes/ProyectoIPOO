#ifndef _GEM_H_
#define _GEM_H_

class Gem
{
public:
  Gem();
  ~Gem();
  virtual void Break();  // This function is used when a gem is deleted. 

protected:
private:
int coordinatex;
int coordinatey;
bool mindLock; //     MindGem status
int Type; //          Indicates the kind of gem (there are 6 gems)

};
#endif
