#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"
#include "tree.h"
#include <vector>
#include<stack>
#include<QMessageBox>

class wholeBoard
{

public:
    static std::stack <tree::coords> square;
    wholeBoard();
    static int score;
    static bool first;
    static board *B[DIMENSION][DIMENSION];
    static int moveX[DIMENSION];
    static int moveY[DIMENSION];
    static tree *pathTree;
//    static tree::Node *root;
    static tree::Node *temp;
    static std::vector<tree::coords> childInfo;

    void setupBoard(QGraphicsScene *scene);
    static void availSpots();
    static void unavailSpots();
    static void renewAvail();
    static bool isInside(int x,int y);
    static bool updatePreventselect();
    static bool isVisited(int x, int y);
    void resetBoard();
    void resetToRecap();
    static void deleteSq();

    void traverseTree();

};

#endif // WHOLEBOARD_H
