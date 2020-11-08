#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"

class wholeBoard:public board
{

public:
    wholeBoard();
    void setupBoard(QGraphicsScene *scene);
    static void availSpots();
    static void unavailSpots();

    static board *B[DIMENSION][DIMENSION];

    void placeKnight(int *posX, int *posY);

    void resetBoard();

};

#endif // WHOLEBOARD_H
