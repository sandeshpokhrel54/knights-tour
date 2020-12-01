#include "tree.h"
#include "wholeboard.h"
struct tree::coords{
    int x,y;
    coords(int a = 0, int b = 0):x{a},y{b}
    {

    }

};
struct tree::Node{

    int n; //no of childs
    coords position;
    Node *left = NULL;
    Node *right = NULL;
    Node(int x = 0, int y = 0){
        position.x = x;
        position.y = y;
    }

};


tree::tree(int xval, int yval)
{
    root = new tree::Node(xval,yval);
}

void tree::sibblings(tree::Node *sibbling, int noOfChild, std::vector<coords> &childInfo)
{
    if(noOfChild >= 0)
    {

        sibbling->right = new Node(childInfo[noOfChild].x, childInfo[noOfChild].y);
//        std::cout<<childInfo[noOfChild].x<<std::endl;
        noOfChild--;
        childInfo.pop_back();
        sibblings(sibbling->right, noOfChild,childInfo);
    }
}


void tree::traverseTilldata(Node *root, coords data, int noOfChild, std::vector<coords> &childInfo)
{

    if(root->position.x == data.x && root->position.y == data.y)
    {
//        std::cout<<"pasyo lasan "<<noOfChild<<std::endl;
        root->n = noOfChild;
        root->left = new Node(childInfo[noOfChild-1].x, childInfo[noOfChild-1].y);
        childInfo.pop_back();
        sibblings(root->left, root->n - 2 , childInfo);


    }

    else if(root->left != NULL)
    {
//        std::cout<<"left turn"<<std::endl;
        traverseTilldata(root->left, data, noOfChild, childInfo);
    }

    else if(root->right != NULL)
    {
//        std::cout<<"right turn"<<std::endl;
        traverseTilldata(root->right, data, noOfChild, childInfo);
    }

}


void tree::deallocate(Node *root, coords popedData)
{
    if(root->position.x == popedData.x && root->position.y == popedData.y)
    {
        deallocateSibs(root->left);
        free(root->left);
    }

    else if(root->left != NULL)
    {
        deallocate(root->left, popedData);
    }
    else if(root->right != NULL)
    {
        deallocate(root->right, popedData);
    }
}

void tree::deallocateSibs(Node *root)
{
    if(root == NULL)
        return;
    if(root->right == NULL)
            free(root);
    else
        deallocateSibs(root->right);
}

void tree::traverse(Node *root)
{
 //    traversal of all selected nodes
    if(root == NULL)
        return;
    if(root->left != NULL){
        std::cout<<"rootposx-> "<<root->position.x<<" ";
        std::cout<<"rootposy-> "<<root->position.y<<std::endl;
        wholeBoard::B[root->position.x][root->position.y]->visited = true;
        wholeBoard::B[root->position.x][root->position.y]->update();
        delay();

    }

    traverse(root->left);
    traverse(root->right);

// //    traversal of whole tree
//    if(root == NULL).
//    {
//        return;
//    }
//    traverse(root->left);
//    std::cout<<"node x"<<root->position.x<<" ";
//    std::cout<<"node y"<<root->position.y<<std::endl;
//    traverse(root->right);

}




//very heavy function but couldn't find a better alternative
void tree::delay()
{
    QTime dieTime= QTime::currentTime().addMSecs(500);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
