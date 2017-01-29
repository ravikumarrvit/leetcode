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

    void minDepthRecurse(TreeNode* root, int level, int &min_depth) {
        if (!root)
            return;
        if (!root->left && !root->right) {
            min_depth = min(min_depth, level);
        } else {
            minDepthRecurse(root->left, level + 1, min_depth);
            minDepthRecurse(root->right, level + 1, min_depth);
        }
    }

    int minDepth(TreeNode* root) {
        int min_depth = INT_MAX;
        if (root == NULL)
            return 0;
        minDepthRecurse(root, 1, min_depth);
        return min_depth;
    }
};