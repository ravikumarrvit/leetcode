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

    void rightSideViewRecurse(TreeNode *root, vector<int> &result, int level) {
        if (!root)
            return;
        if (result.size() < level) {
            result.resize(level);
            result[level - 1] = root->val;
        }
        
        rightSideViewRecurse(root->right, result, level + 1);
        rightSideViewRecurse(root->left, result, level + 1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        
        if (!root)
            return result;
        
        rightSideViewRecurse(root, result, 1);
        
        return result;
    }
};