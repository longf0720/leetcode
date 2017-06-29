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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode *> s;
        while(root || !s.empty()) {
            if(root) {
                s.push(root);
                root = root->left;
            }
            else {
                root = s.top();
                s.pop();
                ret.push_back(root->val);
                root = root->right;
            }
        }
        return ret;
    }

    vector<int> inorderTraversal1(TreeNode* root) {
        vector<int> vector;
        if(!root)
        return vector;
        stack<TreeNode *> stack;
        stack.push(root);
        while(!stack.empty())
        {
            TreeNode *pNode = stack.top();
            if(pNode->left)
            {
                stack.push(pNode->left);
                pNode->left = NULL;
            }
            else
            {
                vector.push_back(pNode->val);
                stack.pop();
                if(pNode->right)
                    stack.push(pNode->right);
            }
        }
        return vector;
    }
};