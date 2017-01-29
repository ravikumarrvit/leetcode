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
    
    bool hasPathSumRecurse(TreeNode* root, int remainder) {
        if (!root)
            return false;
        if (!root->left && !root->right) {
            if (root->val == remainder)
                return true;
            else
                return false;
        }
        return hasPathSumRecurse(root->left, remainder - root->val) || 
                hasPathSumRecurse(root->right, remainder - root->val);
    }

    bool hasPathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return false;
        return hasPathSumRecurse(root, sum);
    }
};