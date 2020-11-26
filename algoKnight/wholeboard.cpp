#include "wholeboard.h"
#include "tree.cpp"

board *wholeBoard::B[DIMENSION][DIMENSION]={};
int wholeBoard::score = 0;
tree wholeBoard::pathTree;
std::vector<tree::coords> wholeBoard::childInfo = {};

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
    int childCount = 0;
    for(int i=0; i<DIMENSION; i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            //board piece's available spots are to be shown

            if(B[i][j]->selected)
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
                if(score == 1){
                    pathTree.root = new tree::Node(B[i][j]->positionX, B[i][j]->positionY);
                }

                //1                                  
                if( i-2 >= 0 && j+1 < DIMENSION)
                {
                    B[i-2][j+1]->available = true;
                    childInfo.push_back({i-2, j+1});
                    childCount++;
                }

                //2
                if( i-2 >= 0 && j-1 >= 0)
                {
                    B[i-2][j-1]->available = true;
                    childInfo.push_back({i-2, j-1});
                    childCount++;
                }

                //3
                if( i-1 >= 0 && j-2 >= 0)
                {
                    B[i-1][j-2]->available = true;
                    childInfo.push_back({i-1, j-2});
                    childCount++;
                }

                //4
                if( i+1 < DIMENSION && j-2 >= 0)
                {
                    B[i+1][j-2]->available = true;
                    childInfo.push_back({i+1,j-2});
                    childCount++;
                }

                //5
                if( i+2 < DIMENSION && j+1 < DIMENSION)
                {
                    B[i+2][j+1]->available = true;
                    childInfo.push_back({i+2, j+1});
                    childCount++;
                }

                //6
                if( i+2 < DIMENSION && j-1 >= 0)
                {
                    B[i+2][j-1]->available = true;
                    childInfo.push_back({i+2, j-1});
                    childCount++;
                }

                //7
                if( i-1 >= 0 && j+2 < DIMENSION)
                {
                    B[i-1][j+2]->available = true;
                    childInfo.push_back({i-1, j+2});
                    childCount++;
                }

                //8
                if( i+1 < DIMENSION && j+2 < DIMENSION)
                {
                    B[i+1][j+2]->available = true;
                    childInfo.push_back({i+1, j+2});
                    childCount++;
                }

                pathTree.traverseTilldata(pathTree.root,{B[i][j]->positionX,B[i][j]->positionY}, childCount, childInfo);

            }
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

void wholeBoard::renewAvail()
{
    for(int i=0;i<DIMENSION;i++)
    {
        for(int j=0; j<DIMENSION; j++)
        {
            B[i][j]->selected = false;
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
            if(B[i][j]->selected)
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
            B[i][j]->visited = false;
            B[i][j]->selected = false;
            B[i][j]->available = false;
            B[i][j]->update();
            wholeBoard::score = 0;
            board::count = 1;
        }
    }
}

