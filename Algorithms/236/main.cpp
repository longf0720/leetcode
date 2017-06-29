#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
 * 空节点不认为是叶子结点，
 * 因为二叉树当中只有叶子结点的左右子树才可能是空节点（空二叉树除外）
 */
bool isLeaf(TreeNode *node) {
    if(!node) return false;
    return (!node->left || !node->right);
}

bool preOrder(TreeNode *root, stack<TreeNode *> &res, TreeNode *target) {
    bool found = false;
    res.push(root);
    if(!root) return found;
    if(root->val == target->val) return true;
    found = preOrder(root->left, res, target);
    if(!found) {
       res.pop();
       found = preOrder(root->right, res, target); 
       if(!found) res.pop();
    }
    return found;

}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode *> sp;
    stack<TreeNode *> sq;
    preOrder(root, sp, p);
    preOrder(root, sq, q);
    TreeNode *ans = NULL;
    while(sp.size() != sq.size()) {
        if(sp.size() > sq.size()) sp.pop();
        else if(sp.size() < sq.size()) sq.pop();
    }
    while(!sp.empty() && !sq.empty()) {
        cout<<"sp:"<<sp.top()->val<<" sq:"<<sq.top()->val<<endl;
        if(sp.top()->val != sq.top()->val) {
            sp.pop();
            sq.pop();
        }
        else{
            ans = sp.top();
            break;
        }
    }
    return ans;
}

void create_bitree(TreeNode *&root) {
    int data;
    cin>>data;
    if(0 == data) root=NULL;
    else {
        root = new TreeNode(data);
        create_bitree(root->left);
        create_bitree(root->right);
    }
}

vector<vector<int> > levelOrder(TreeNode* root) {
    vector<vector<int> > ans;
    vector<int> level;
    TreeNode *last = NULL, *cur = NULL, *nlast=NULL;
    queue<TreeNode *> q;
    last = cur = root;
    while(cur || !q.empty()) {
        if(q.empty()) {
            q.push(cur);
            nlast = cur;
        }  else {
            cur = q.front();
            q.pop();
            if(cur->left) {
                q.push(cur->left);
                nlast = cur->left;
            }
            if(cur->right) {
                q.push(cur->right);
                nlast = cur->right;
            }
            level.push_back(cur->val);
            if(cur == last) {
                ans.push_back(level);
                level.clear();
                last = nlast;
            }
            if(q.empty()) break;
        }
    }
    return ans;
}

void print_res(std::vector<vector<int> > v) {
    vector<std::vector<int> >::iterator it = v.begin();
    vector<int>::iterator jt;
    for(;it != v.end(); it++) {
        for(jt = (*it).begin(); jt != (*it).end(); jt++) 
            cout<<(*jt)<<" ";
    }

}

int main() {
    freopen("in.txt", "r", stdin);
    TreeNode *root = NULL, *q  = NULL, *p = NULL;
    create_bitree(root);
    std::vector<vector<int> > v;  
    v = levelOrder(root);
    print_res(v); 
    if(root) {
        p = root->right->left;
        q = root->right->right->left->left;
        cout<<p->val<<","<<q->val<<endl;
    }
    TreeNode *res = lowestCommonAncestor(root, p, q);
    if(res)
        cout<<res->val<<endl;
    return 0;
}
