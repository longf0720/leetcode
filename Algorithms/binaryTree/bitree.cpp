#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL){}
};

void visit(TreeNode *node)
{
    if(!node)
        return;
    cout<<node->val<<" ";
}

void createTree(TreeNode *r&oot)
{
    int i;
    cin>>i;
    if(0 == i)
        root = NULL;
    else {
        root = new TreeNode(); // assume enough memory
        root->val = i;
        createTree(root->left);
        createTree(root->right);
    }
}