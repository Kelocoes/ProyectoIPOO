#ifndef _BOARD_H_
#define _BOARD_H_

class Board
{
Public:
  Board();
  ~Board();
  virtual void Matrix();
  virtual void Match();//Abstraction
  virtual void fill();//Need a verifier of where the match is happening
  virtual void Move();

Protected:
Private:

};
#endif
