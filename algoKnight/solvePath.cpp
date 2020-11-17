#include "solvePath.h"
#include<unistd.h>

solvePath::solvePath():moveX{1,1,2,2,-1,-1,-2,-2}  //constructor
  ,moveY{2,-2,1,-1,2,-2,1,-1}
{

}

bool solvePath::findNextMove()  //warnsdeff's algorithm
{
    srand(time(NULL));
    int temp;
    int minimumDegree=N+1;
    int minimumDegreeIndex=-1;

    int start = rand()%N;

    for(int count=0;count<N;count++)
        {
            int i = (start + count)%N;
            nextX=currentX+moveX[i];
            nextY=currentY+moveY[i];
            if( (isEmpty(nextX,nextY))  && ((temp=getDegree(nextX,nextY)) < minimumDegree) )
                {
                    minimumDegreeIndex=i; //choose square index with minimum degree
                    minimumDegree=temp;		//choose minimum degree;

                }
        }
    if(minimumDegreeIndex==-1)
         return false;

    nextX=currentX+moveX[minimumDegreeIndex];
    nextY=currentY+moveY[minimumDegreeIndex];

    //pause sometime before executing
    //......

    wholeBoard::B[nextX][nextY]->visited = wholeBoard::B[currentX][currentY]->visited;
    wholeBoard::B[nextX][nextY]->update();

    currentX=nextX;
    currentY=nextY;

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

bool solvePath::findKnightPath()
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            wholeBoard::B[i][j]->visited=false;
        }
    }
    currentX=startX=0;
    currentY=startY=0;
    wholeBoard::B[currentX][currentY]->visited=true;
    wholeBoard::B[currentX][currentY]->update();
    for(int i=0;i<N*N-1;i++)
        {
            if(findNextMove()==0)
               {
                   return false;
               }
        }
    return true;
}

void solvePath::showSolution()
{
    while (!(findKnightPath()))
        {

        }
}
