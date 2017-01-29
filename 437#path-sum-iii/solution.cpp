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

    int pathSumCount(TreeNode *root, int accumulated_sum, int &sum) {
        if (!root)
            return 0;
        accumulated_sum += root->val;
        return (accumulated_sum == sum) + pathSumCount(root->left, accumulated_sum, sum) + pathSumCount(root->right, accumulated_sum, sum);
    }

    int pathSum(TreeNode* root, int sum) {
        if (!root)
            return 0;
        
        return pathSumCount(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
};