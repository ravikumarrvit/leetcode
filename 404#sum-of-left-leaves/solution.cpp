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

    void sumOfLeftLeavesRecurse(TreeNode *root, int &sum, char dir) {
        if (!root)
            return;
        if (dir == 'L' && !root->left && !root->right)
            sum += root->val;
        
        sumOfLeftLeavesRecurse(root->left, sum, 'L');
        sumOfLeftLeavesRecurse(root->right, sum, 'R');
        
    }

    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        char dir = 'N';
        
        sumOfLeftLeavesRecurse(root, sum, dir);
        
        return sum;
    }
};