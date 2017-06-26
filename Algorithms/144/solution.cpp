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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ret;
        if(!root) return ret;
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                ret.push_back(root->val);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                root = root->right;
            }
        }
        return ret;
    }

    vector<int> preorderTraversal1(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ret;
        if(!root) return ret;
        s.push(root);
        while(!s.empty()) {
            root = s.top();
            ret.push_back(root->val);
            s.pop();
            if(root->right) {
                s.push(root->right);
            }
            if(root->left) {
                s.push(root->left);
            }
        }
        return ret;
    }
};
