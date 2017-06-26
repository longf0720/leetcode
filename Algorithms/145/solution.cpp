/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> vh;
        if (!root) return vh;
        stack<TreeNode*> stk0;
        stack<TreeNode*> stk1;
        stk0.push(root);
        
        while(!stk0.empty()) {
            
            TreeNode *tmp = stk0.top();
            stk0.pop();
            
            if (tmp->left) stk0.push(tmp->left);
            if (tmp->right) stk0.push(tmp->right);
            
            stk1.push(tmp);
        }
        
        while(!stk1.empty()) {
            TreeNode* tmp = stk1.top();
            stk1.pop();
            vh.push_back(tmp->val);
        }
        
        return vh;
    }

    vector<int> postorderTraversal1(TreeNode *root) {
        vector<int> v;
        if (!root) return v;
        
        stack<TreeNode *> s;
        s.push(root);
        
        TreeNode *p = NULL;
        while(!s.empty()) {
            p = s.top();
            s.pop();
            v.insert(v.begin(), p->val);
            if (p->left) s.push(p->left);
            if (p->right) s.push(p->right);
        }
        return v;
    }

    vector<int> postorderTraversal2(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ret;
        TreeNode *lastVisited = NULL;
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                root = root->left;
            }
            else {
                TreeNode *top = s.top();
                if(top->right && top->right != lastVisited) {
                    root = top->right;
                }
                else {
                    ret.push_back(top->val);
                    s.pop();
                    lastVisited = top;
                }
            }
        }
        return ret;
    }
};