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

    static board *B[DIMENSION][DIMENSION];

    void placeKnight(int *posX, int *posY);
    static int *test[5][5];

};

#endif // WHOLEBOARD_H
