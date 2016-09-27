#if !defined (NULL)
   #define NULL 0
#endif

#if !defined (DIRECTION)
#define DIRECTION
   enum Direction {DOWN = 1, RIGHT, UP, LEFT, DEAD_END};
#endif

#if !defined (CELL_H)
#define CELL_H

class Cell
{

   private:
      int row;
      int col;
      Direction dir;

   public:
      Cell(int row, int col);
      virtual ~Cell();
      int getRow();
      int getCol();
      Direction getDir();
      Cell* nextCell();

};

#endif
