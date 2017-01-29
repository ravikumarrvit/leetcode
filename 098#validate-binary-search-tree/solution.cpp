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

    bool isValidBSTRecurse(TreeNode* root, long long low, long long high) {
        if (root == NULL)
            return true;
        if (root->val < low || root->val > high)
            return false;
        return isValidBSTRecurse(root->left, low, (long long)root->val - 1) && isValidBSTRecurse(root->right, (long long)root->val + 1, high);
    }

    bool isValidBST(TreeNode* root) {
        long long low = INT_MIN, high = INT_MAX;
        if (root == NULL)
            return true;
        return isValidBSTRecurse(root, low, high);
    }
};