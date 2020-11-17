#ifndef SOLVEPATH_H
#define SOLVEPATH_H
#include<stdlib.h>
#include<time.h>
#include "wholeboard.h"
#define N 8
class solvePath
{
private:
    int startX, startY;  //starting coordinate of the knight
    int currentX,currentY;  //current coordinate of the kngith
    int nextX, nextY;    //next coordinate of the knight
    int moveX[8];
    int moveY[8];

private:

    bool findNextMove();           //warnsdeff's algorithm
    int getDegree(int x, int y);
    bool isEmpty(int x, int y);
    bool isInsideBoard(int x,int y);

public:
    solvePath();
    bool findKnightPath();
    void showSolution();

};

#endif // SOLVEPATH_H
