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

    void sumNumbersRecurse(TreeNode *root, int &sum, int temp_sum) {
        if (!root)
            return;
        
        temp_sum = (temp_sum * 10) + root->val;
        if (!root->left && !root->right)
            sum += temp_sum;
            
        sumNumbersRecurse(root->left, sum, temp_sum);
        sumNumbersRecurse(root->right, sum, temp_sum);
    }

    int sumNumbers(TreeNode* root) {
        int sum = 0, temp_sum = 0;
        
        if (!root)
            return sum;
        
        sumNumbersRecurse(root, sum, temp_sum);
        
        return sum;
    }
};