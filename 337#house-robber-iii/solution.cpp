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

    int robRecurse(TreeNode* root, int &left, int &right) {
        if (!root)
            return 0;
        
        int left_left = 0, left_right = 0, right_left = 0, right_right = 0;
        left = robRecurse(root->left, left_left, left_right);
        right = robRecurse(root->right, right_left, right_right);
        
        return max(root->val + left_left + left_right + right_left + right_right, left + right);
    }

    int rob(TreeNode* root) {
        int left, right;
        return robRecurse(root, left, right);
    }
};