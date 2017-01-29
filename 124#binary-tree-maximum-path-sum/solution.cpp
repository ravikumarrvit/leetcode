/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#define DEBUG 1

class Solution {
public:

    int maxPathSumRecurse(TreeNode *root, int &max_path_sum) {
        int left_sum, right_sum;
        if (!root)
            return 0;
        left_sum = maxPathSumRecurse(root->left, max_path_sum);
        right_sum = maxPathSumRecurse(root->right, max_path_sum);
        
        left_sum = (left_sum < 0) ? 0 : left_sum;
        right_sum = (right_sum < 0) ? 0 : right_sum;
        
        max_path_sum = max(max_path_sum, left_sum + right_sum + root->val);
        
        root->val += max(left_sum, right_sum);
        
        return root->val;
    }

    int maxPathSum(TreeNode* root) {
        int max_path_sum = INT_MIN;
        
        maxPathSumRecurse(root, max_path_sum);
        
        return max_path_sum;
    }
};