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

    void levelOrderBottomRecurse(TreeNode* root, vector<vector<int>> &result, int level, int max_depth) {
        if (!root)
            return;
        result[max_depth - level].push_back(root->val);
        levelOrderBottomRecurse(root->left, result, level + 1, max_depth);
        levelOrderBottomRecurse(root->right, result, level + 1, max_depth);
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int max_depth = 0, level = 0;
        vector<vector<int>> result;
        
        if (root == NULL)
            return result;
        
        maxDepthRecurse(root, level, max_depth);
        result.resize(max_depth + 1);
        
        if (DEBUG)
            cout << "max_depth: " << max_depth << endl;
        
        levelOrderBottomRecurse(root, result, level, max_depth);
        
        return result;
    }
};