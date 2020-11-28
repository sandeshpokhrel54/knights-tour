#ifndef BSTREE_H
#define BSTREE_H
class bstree
{
    private:
    public:
    struct node;
    bstree();
    void insert(int deg, int d_idx);
    int smallest();
    void deletenode(node* node);
    ~bstree();
    node* root;

};
#endif // BSTREE_H
