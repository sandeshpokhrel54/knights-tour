#include "tree.h"

tree::tree()
{

}

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

void tree::sibblings(tree::Node *sibbling, tree::coords data, int noOfChild)
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


void tree::traverseTilldata(Node *root, coords data, int noOfChild)
{
    if(root->position.x == data.x && root->position.y == data.y)
    {
        root->n = noOfChild;
        root->left = new Node({root->position.y+1, root->position.y+2}); //random data passed for now
        sibblings(root->left,{root->left->position.y+1, root->left->position.y+2}, root->n-1); //4 to create 4 sibblings everytime
    }

    else if(root->left != NULL)
    {
        traverseTilldata(root->left, data, noOfChild);
    }

    else if(root->right != NULL)
    {
        traverseTilldata(root->right, data, noOfChild);
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
    if(root == NULL)
        return;
    if(root->left != NULL){
        //std::cout<<root->position.x;
        //std::cout<<root->position.y;
    }
    traverse(root->left);
    traverse(root->right);
}



