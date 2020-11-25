#ifndef WHOLEBOARD_H
#define WHOLEBOARD_H

#define DIMENSION 8
#include "board.h"

class wholeBoard
{

public:
    wholeBoard();
    static int score;
    static board *B[DIMENSION][DIMENSION];

    void setupBoard(QGraphicsScene *scene);
    static void availSpots();
    static void unavailSpots();
    static void renewAvail();

    void placeKnight(int *posX, int *posY);
    void resetBoard();

    //for tree structure
    struct coords;
    struct Node;
    void sibblings(Node *sibbling, coords data, int noOfChild);
    void traverseTilldata(Node *root, coords data);
    void deallocate(Node *root, coords popedData);
    void deallocateSibs(Node *root);
    void traverse(Node *root);



};

#endif // WHOLEBOARD_H
