#include "wholeboard.h"

board *wholeBoard::B[DIMENSION][DIMENSION]={};

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
    {
        //
    }

    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            //board piece's available spots are to be shown

            if(B[i][j]->selected == true)
            {
                //use boundry and set available to true
                //boundry:  - > 0, + < dimension
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

                //1
                if( i-2 >= 0 && j+1 < DIMENSION)
                {
                    B[i-2][j+1]->available = true;
                }

                //2
                if( i-2 >= 0 && j-1 >= 0)
                {
                    B[i-2][j-1]->available = true;
                }

                //3
                if( i-1 >= 0 && j-2 >= 0)
                {
                    B[i-1][j-2]->available = true;
                }

                //4
                if( i+1 < DIMENSION && j-2 >= 0)
                {
                    B[i+1][j-2]->available = true;
                }

                //5
                if( i+2 < DIMENSION && j+1 < DIMENSION)
                {
                    B[i+2][j+1]->available = true;
                }

                //6
                if( i+2 < DIMENSION && j-1 >= 0)
                {
                    B[i+2][j-1]->available = true;
                }

                //7
                if( i-1 >= 0 && j+2 < DIMENSION)
                {
                    B[i-1][j+2]->available = true;
                }

                //8
                if( i+1 < DIMENSION && j+2 < DIMENSION)
                {
                    B[i+1][j+2]->available = true;
                }

            }

            //when spot is deselected, reset the board to have no available spots as well;
//            else
//            {

//                //B[i][j]->available = false;
//            }

            B[i][j]->update();

        }
    }
}

void wholeBoard::unavailSpots()
{
    for(int i = 0; i<DIMENSION; i++)
    {
        for(int j = 0; j<DIMENSION; j++)
        {
            B[i][j]->available = false;
            B[i][j]->update();
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

void wholeBoard::resetBoard()
{
    for(int i = 0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            B[i][j]->selected = false;
            B[i][j]->available = false;
            B[i][j]->update();
            board::count = 1;
        }
    }
}



