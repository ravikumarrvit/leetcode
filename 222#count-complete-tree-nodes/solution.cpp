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
    int countNodes(TreeNode* root) {
        int left_sub_height = 0, right_sub_height = 0;
        TreeNode *left, *right;
        if (!root)
            return 0;
        left = right = root;
        
        while(left->left) {
            left = left->left;
            left_sub_height++;
        }
        
        while(right->right) {
            right = right->right;
            right_sub_height++;
        }
        
        if (left_sub_height == right_sub_height)
            return pow(2, left_sub_height + 1) - 1;
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};