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
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* temp_node;
        if (!root)
            return root;
        temp_node = root->right;
        root->right = root->left;
        root->left = temp_node;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
};