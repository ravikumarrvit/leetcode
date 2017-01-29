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

    int max_depth(TreeNode* root, int level) {
        if (!root)
            return level - 1;
        if (!root->left && !root->right)
            return level;
        
        return max(max_depth(root->left, level + 1), max_depth(root->right, level + 1));
    }

    bool isBalancedRecurse(TreeNode* root) {
        if (!root)
            return true;
        if (abs(max_depth(root->left, 0) - max_depth(root->right, 0)) > 1)
            return false;
        return isBalancedRecurse(root->left) && isBalancedRecurse(root->right);
    }

    bool isBalanced(TreeNode* root) {
        if (!root)
            return true;
        return isBalancedRecurse(root);
    }
};