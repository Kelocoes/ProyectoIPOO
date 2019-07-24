#ifndef _BOARD_H_
#define _BOARD_H_

class Board
{
public:
  Board();
  ~Board();
  virtual void Matrix();  // It includes a Matrix where gems are gonna be located
  virtual void Match();   // Abstraction where all matches movements are included
  virtual void fill();    // Need a verifier of where the match is happening, then fill the void boxes
  virtual void Move();    // Indicates to gems how to move around the board 

protected:
  //
private:
  //

};
#endif
