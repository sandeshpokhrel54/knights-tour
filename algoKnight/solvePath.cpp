#include "solvePath.h"
#include<QDebug>
#include "bstree.h"
solvePath::solvePath():moveX{1,1,2,2,-1,-1,-2,-2}  //constructor
  ,moveY{2,-2,1,-1,2,-2,1,-1}
{

    moves=0;
}

bool solvePath::findNextMove()  //warnsdeff's algorithm
{ 
        bstree b_tree;
        int degree;
        int moveIndex=-1;
        int start = rand()%N;
        std::cout<<start<<std::endl;
        for(int count=0;count<N;count++)
            {
               int i = (start + count)%N;
                nextX=currentX+moveX[i];
                nextY=currentY+moveY[i];
                if( isEmpty(nextX,nextY) )
                    {
                       degree=getDegree(nextX,nextY);
                       moveIndex=i;
                       b_tree.insert(degree,moveIndex);
                     }
             }

      moveIndex=b_tree.smallest();

     if(moveIndex==-1)
          return false;

    nextX=currentX+moveX[moveIndex];
    nextY=currentY+moveY[moveIndex];


    wholeBoard::B[nextX][nextY]->visited = wholeBoard::B[currentX][currentY]->visited;
    wholeBoard::B[nextX][nextY]->selected= wholeBoard::B[currentX][currentY]->visited;
    wholeBoard::B[currentX][currentY]->selected = false;
    wholeBoard::B[currentX][currentY]->update();
    wholeBoard::B[nextX][nextY]->update();

    currentX=nextX;
    currentY=nextY;

    moves++;
    wholeBoard::score++;
    if(moves==63)
    {
        timer->stop();

    }
    return true;
}

int solvePath::getDegree(int x, int y)
{
    int deg=0;
    for(int i=0;i<N;i++)
        {
            if(isEmpty(x+moveX[i],y+moveY[i]))
               {
                   deg++;
               }
        }

    return deg;
}

bool solvePath::isEmpty(int x, int y)
{
    if( (isInsideBoard(x,y)) && (wholeBoard::B[x][y]->visited==false) )
           return true;
    return false;
}

bool solvePath::isInsideBoard(int x, int y)
{
    if((x>=0 && y>=0) && (x<N && y<N))
         return true;
    return false;
}

void solvePath::findKnightPath()
{
    srand(time(nullptr));
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            wholeBoard::B[i][j]->visited=false;
        }
    }
    currentX=startX=rand()%N;
    currentY=startY=rand()%N;
    wholeBoard::B[currentX][currentY]->visited=true;
    wholeBoard::B[currentX][currentY]->selected=true;
    wholeBoard::B[currentX][currentY]->update();
    wholeBoard::score++;
    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(findNextMove()));
    timer->start(100);

}

void solvePath::resetPath()
{
    moves=0;
    //timer->stop();
    delete timer;
    timer = NULL;
}
