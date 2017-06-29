#include <iostream>
#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0),left(NULL),right(NULL) {}
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
    else 
    {
        root = new TreeNode(); // assume enough memory
        root->val = i;
        createTree(root->left);
        createTree(root->right);
    }
}

struct item
{
    TreeNode *n;
    bool left;
    bool right;
    item():n(NULL),left(false),right(false) {}
    item(TreeNode *node):n(node),left(false),right(false) {}
};

void preOrder(TreeNode *root) 
{
    stack<item *> s;
    TreeNode *cur = root;
    while(!s.empty() || !cur)
    {
        if(s.empty())
        {
            s.push_back(obj);
        } 
        else if(cur->left && cur->right)
        {
            cur = s.top();
            s.pop();
        }
        else if(cur->left)
        {
            
            s.push(cur->right);
        }
    }
}




















