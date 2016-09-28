#include "Cell.h"

Cell::Cell(int r, int c)
{
   dir = DOWN;  //the first direction that will be tried after this location
   row = r;
   col = c;
}

Cell::~Cell()
{}

int Cell::getRow()
{
   return row;
}

int Cell::getCol()
{
   return col;
}

Direction Cell::getDir()
{
   return dir;
}

Cell* Cell::nextCell()
{
   Cell* cell = NULL;

   if (dir == DOWN)  //down was a dead end, move right next
   {
      cell = new Cell(row + 1, col);
      dir = RIGHT;
   }
   else if (dir == RIGHT)  //move up
   {
      cell = new Cell(row, col + 1);
      dir = UP;
   }
   else if (dir == UP) //move left
   {
      cell = new Cell(row - 1, col);
      dir = LEFT;
   }

   //all 4 directions have been tried
   //if we come back here for another direction, this cell is invalid and must be discarded
   else if (dir == LEFT)
   {
      cell = new Cell(row, col - 1);
      dir = DEAD_END;
   }

   return cell; //returns NULL if all options have been attempted
}
