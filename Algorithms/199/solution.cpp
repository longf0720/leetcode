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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> v;
        if(!root) return v;
        //level order
        TreeNode *curr, *last, *nlast;
        curr = last = nlast = root;
        queue<TreeNode *> q;
        while(true) {
            if(q.empty()) {
                q.push(curr);
                nlast = curr;
            }
            else {
                curr = q.front();
                if(curr->left) {
                    q.push(curr->left);
                    nlast = curr->left;
                }
                if(curr->right) { 
                    q.push(curr->right);
                    nlast = curr->right;
                }
                if(curr == last) {
                    v.push_back(curr->val);
                    last = nlast;
                }
                q.pop();
                if(q.empty()) break;
            }
        }
        return v;
    }
};