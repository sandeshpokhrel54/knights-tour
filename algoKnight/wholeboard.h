#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"

class wholeBoard:public board
{

public:
    wholeBoard();
    void setupBoard(QGraphicsScene *scene);
    void availSpots();

    board *B[DIMENSION][DIMENSION];

    void placeKnight(int *posX, int *posY);


};

#endif // WHOLEBOARD_H
