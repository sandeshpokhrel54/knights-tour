#ifndef BSTREE_CPP
#define BSTREE_CPP
#include "bstree.h"
#include<QDebug>
struct bstree::node
{
    node* lchild;
    int degree;
    int m_index;
    node *rchild;
};

bstree::bstree()
{
    root=nullptr;
}

void bstree::insert(int deg, int d_idx)
{
    node *ptr=root;
    node *preptr=nullptr,*temp;

     if(root==nullptr)
         {
             root=new node;
             root->degree=deg;
             root->m_index=d_idx;
             root->lchild=root->rchild=nullptr;
             return;
          }
          while(ptr!=nullptr)
                {
                    preptr=ptr;
                    if(deg < ptr->degree)
                        ptr=ptr->lchild;
                    else if(deg > ptr->degree)
                        ptr=ptr->rchild;
                    else
                        return;
                }

           temp=new node;
           temp->degree=deg;
           temp->m_index=d_idx;
           temp->lchild=temp->rchild=nullptr;

                if(deg < preptr->degree)
                    preptr->lchild=temp;
                else
                    preptr->rchild=temp;
}

int bstree::smallest()
{
    node *temp=root;
    while(temp->lchild!=nullptr)
         {
             temp=temp->lchild;
         }
    return temp->m_index;
}

void bstree::deletenode(node* node)
{
    if(node==nullptr)
        return;
    deletenode(node->lchild);
    deletenode(node->rchild);
    delete node;
}



bstree::~bstree()
{
    deletenode(root);
}


#endif // BSTREE_CPP
