#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"
#include "tree.h"

class wholeBoard
{

public:
    wholeBoard();
    static int score;
    static board *B[DIMENSION][DIMENSION];
    static tree *pathTree;

    void setupBoard(QGraphicsScene *scene);
    static void availSpots();
    static void unavailSpots();
    static void renewAvail();

    void placeKnight(int *posX, int *posY);
    void resetBoard();

};

#endif // WHOLEBOARD_H
