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
    TreeNode* invertTree(TreeNode* root) {
		if(!root) return NULL;
		queue<TreeNode *> q;
        while(true) {
            if(q.empty()) q.push(root);
            else {
                TreeNode *cur = q.front();
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                swap(cur->left, cur->right);
                q.pop();
                if(q.empty()) break;
            }    
        }
        return root;
	}

    TreeNode* invertTreeRecur(TreeNode* root) {
        if(!root) return NULL;
        invertTree(root->left);
        invertTree(root->right);
        swap(root->left, root->right);
        return root;
    }
};
