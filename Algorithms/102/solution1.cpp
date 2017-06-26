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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
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
};