#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"
#include "tree.h"
#include <vector>
#include<stack>

class wholeBoard
{

public:
    static std::stack <tree::coords> square;
    wholeBoard();
    static int score;
    static board *B[DIMENSION][DIMENSION];
    static int moveX[DIMENSION];
    static int moveY[DIMENSION];
    static tree pathTree;
    static std::vector<tree::coords> childInfo;

    void setupBoard(QGraphicsScene *scene);
    static void availSpots();
    static void unavailSpots();
    static void renewAvail();
    static bool isInside(int x,int y);
    static bool updatePreventselect();
    void placeKnight(int *posX, int *posY);
    void resetBoard();
    static void deleteSq();

};

#endif // WHOLEBOARD_H
