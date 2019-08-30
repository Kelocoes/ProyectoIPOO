#ifndef _GEM_H_
#define _GEM_H_
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

class Gem
{
public:
  Gem(int ident); // Builder 
  // it receives and identifier to recognize what gem is it 
  /*
  1 - SpaceGem
  2 - RealityGem
  3 - PowerGem 
  4 - TimeGem
  5 - SoulGem
  6 - MindGem
  */
  ~Gem(); // Destructor 
  int getType(); // Returns the number what identifies the type
  void setType(int num);
  void Break();  // This function is used when a gem is deleted.
  void Lock(); // Changes mindLock attribute

  // New functions 
  int getMind(); // Helps to see if a gem its blocked 

protected:
private:

int mindLock; //     MindGem status (if its available to use)
int Type; //          Indicates the kind of gem (there are 6 types of gems)

};
#endif
