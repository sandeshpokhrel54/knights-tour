#include "wholeboard.h"
#include "tree.cpp"
#include<QDebug>
board *wholeBoard::B[DIMENSION][DIMENSION]={};
int wholeBoard::score = 0;
tree wholeBoard::pathTree;
std::vector<tree::coords> wholeBoard::childInfo = {};
std::stack<tree::coords> wholeBoard::square;

int wholeBoard::moveX[DIMENSION]={1,1,2,2,-1,-1,-2,-2};
int wholeBoard::moveY[DIMENSION]={2,-2,1,-1,2,-2,1,-1};

wholeBoard::wholeBoard() //constructor
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
            if(B[i][j]->selected)
            {

                 pathTree.root = new tree::Node(B[i][j]->positionX, B[i][j]->positionY);
                 square.push(tree::coords(B[i][j]->positionX,B[i][j]->positionY));


                 for(int k=0;k<DIMENSION;k++)
                 {
                     if(isInside(i+moveX[k],j+moveY[k]))
                     {
                          B[i+moveX[k]][j+moveY[k]]->available=true;
                          childInfo.push_back({i,j});
                          childCount++;
                     }
                 }


            pathTree.traverseTilldata(pathTree.root,{B[i][j]->positionX,B[i][j]->positionY}, childCount, childInfo);

            }
            B[i][j]->update();

        }
    }
}
bool wholeBoard::isInside(int x, int y)
{
    if((x>=0 && y>=0) && (x<DIMENSION && y<DIMENSION))
         return true;
    return false;
}
void wholeBoard::deleteSq()
{
    int i,j;
    i=square.top().x;
    j=square.top().y;   //first make available squares of top false  then pop
    for(int k=0;k<DIMENSION;k++)
    {
        if(isInside(i+moveX[k],j+moveY[k]))
        {
             B[i+moveX[k]][j+moveY[k]]->available=false;
             B[i+moveX[k]][j+moveY[k]]->update();

        }
    }
    square.pop();
    if(!square.empty())//if stack is not empty
    {
        i=square.top().x;
        j=square.top().y;
        B[i][j]->selected=true;
        B[i][j]->visited=true;
        B[i][j]->update();

        for(int k=0;k<DIMENSION;k++)  //now make available squares of top true
        {
            if(isInside(i+moveX[k],j+moveY[k]))
            {
                 B[i+moveX[k]][j+moveY[k]]->available=true;
                 B[i+moveX[k]][j+moveY[k]]->update();

            }
        }
    }
    else //if stack is empty
    {
       board::preventselect=false;
       //maybe reset board and delete all data of tree
    }

    //tree node delete here
}
bool wholeBoard::updatePreventselect()
{
    for(int i=0;i<DIMENSION;i++)
    {
        for(int j=0;j<DIMENSION;j++)
        {
            if(B[i][j]->selected)
                return true;

        }
    }
    return false;
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
            board::preventselect=false;
            B[i][j]->update();
        }
    }
}

