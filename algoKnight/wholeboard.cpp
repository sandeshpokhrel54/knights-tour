#include "wholeboard.h"

//empty constructor
wholeBoard::wholeBoard()
{

}


void wholeBoard::setupBoard(QGraphicsScene *scene)
{
        for(int i = 0; i<DIMENSION; i++)
        {
            for(int j = 0; j<DIMENSION; j++)
            {
                B[i][j] = new board;
                B[i][j]->positionX = i;
                B[i][j]->positionY = j;

                if((i+j)%2 == 0)
                    B[i][j]->pieceColor = true;
                else
                    B[i][j]->pieceColor = false;

                scene->addItem(B[i][j]);
            }
        }
}


void wholeBoard::availSpots()
{
    if(board::count == 1)

    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            //board piece's available spots are to be shown
            if(B[i][j]->selected == true )
            {
                //use boundry and set available to true
                //boundry j-2>0, i-2>0, j+2<dimension, i+2<dimension
                //for all board objects if boundry doesn't exceed limit then available = true for
                 /* i-2, j+1
                 * i-2, j-1
                 * i-1, j-2
                 * i+1, j-2
                 * i+2, j+1
                 * i+2, j-1
                 * i-1, j+2
                 * i+1, j+2
                 */


            }

        }
    }
}


void wholeBoard::placeKnight(int *posX, int *posY)
{
    int x, y;
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            if(B[i][j]->selected == true)
            {
               x = i * B[i][j]->eleSize;
               y = j * B[i][j]->eleSize;
            }
        }
    }
    *posX = x;
    *posY = y;

}


