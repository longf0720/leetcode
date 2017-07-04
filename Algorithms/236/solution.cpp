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
    bool preOrder(TreeNode *root, stack<TreeNode *> &res, TreeNode *target) {
        bool found = false;
        res.push(root);
        if(!root) return found;
        if(root == target) return true;
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
        founded = false;
        preOrder(root, sq, q);
        TreeNode *ans = NULL;
        while(sp.size() != sq.size()) {
            if(sp.size() > sq.size()) sp.pop();
            else if(sp.size() < sq.size()) sq.pop();
        }
        while(!sp.empty() && !sq.empty()) {
            if(sp.top() != sq.top()) {
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
};