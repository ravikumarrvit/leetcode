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
    void maxDepthRecurse(TreeNode* root, int level, int &max_depth) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            max_depth = max(max_depth, level);
        } else {
            maxDepthRecurse(root->left, level + 1, max_depth);
            maxDepthRecurse(root->right, level + 1, max_depth);
        }
    }

    int maxDepth(TreeNode* root) {
        int max_depth = INT_MIN;
        if (root == NULL)
            return 0;
        maxDepthRecurse(root, 1, max_depth);
        return max_depth;
    }
};