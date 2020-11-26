#include "wholeboard.h"

board *wholeBoard::B[DIMENSION][DIMENSION]={};
int wholeBoard::score = 0;

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

            //count the number of avail spots which gives no of child of our node
            //store i,j value of the available spots

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

//for tree structure
struct wholeBoard::coords{
    int x,y;
    coords(int a = 0, int b = 0):x{a},y{b}
    {

    }

};

struct wholeBoard::Node{

    int n; //no of childs
    coords position;
    Node *left = NULL;
    Node *right = NULL;
    Node(int x = 0, int y = 0){
        position.x = x;
        position.y = y;
    }

};

void wholeBoard::sibblings(wholeBoard::Node *sibbling, wholeBoard::coords data, int noOfChild)
{
    if(noOfChild > 0)
    {
        noOfChild--;
        sibbling->right = new Node(data.x,data.y);
        data.x++;
        data.y++;
        sibblings(sibbling->right, data, noOfChild);
    }
}


void wholeBoard::traverseTilldata(Node *root, coords data)
{
    if(root->position.x == data.x && root->position.y == data.y)
    {
        root->left = new Node({root->position.y+1, root->position.y+2}); //random data passed for now
        sibblings(root->left,{root->left->position.y+1, root->left->position.y+2}, 4); //4 to create 4 sibblings
    }

    else if(root->left != NULL)
    {
        traverseTilldata(root->left, data);
    }

    else if(root->right != NULL)
    {
        traverseTilldata(root->right, data);
    }

}


void wholeBoard::deallocate(Node *root, coords popedData)
{
    if(root->position.x == popedData.x && root->position.y == popedData.y)
    {
        deallocateSibs(root->left);
        free(root->left);
    }

    else if(root->left != NULL)
    {
        traverseTilldata(root->left, popedData);
    }
    else if(root->right != NULL)
    {
        traverseTilldata(root->right, popedData);
    }
}

void wholeBoard::deallocateSibs(Node *root)
{
    if(root == NULL)
        return;
    if(root->right == NULL)
            free(root);
    else
        deallocateSibs(root->right);
}

void wholeBoard::traverse(Node *root)
{
    if(root == NULL)
        return;
    if(root->left != NULL){
        //std::cout<<root->position.x;
        //std::cout<<root->position.y;
    }
    traverse(root->left);
    traverse(root->right);
}



