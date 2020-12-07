#ifndef SOLVEPATH_H
#define SOLVEPATH_H
#include<stdlib.h>
#include<time.h>
#include<QTimer>
#include "wholeboard.h"

#define N 8
class solvePath: public QObject
{
    Q_OBJECT
private:
    int startX, startY;  //starting coordinate of the knight
    int currentX,currentY;  //current coordinate of the kngith
    int nextX, nextY;    //next coordinate of the knight
    int moveX[8];
    int moveY[8];
    int moves;
    QTimer *timer;
private:

    int getDegree(int x, int y);
    bool isEmpty(int x, int y);
    bool isInsideBoard(int x,int y);


public:
    solvePath();
    void findKnightPath();   //warnsdeff's algorithm
    void resetPath();

public slots:
    bool findNextMove();

};

#endif // SOLVEPATH_H
