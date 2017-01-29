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
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *temp;
        if (!root)
            return root;
        if (root->val == key) {
            if (!root->right) {
                temp = root->left;
                delete root;
                return temp;
            } else {
                temp = root->right;
                while (temp->left)
                    temp = temp->left;
                swap(root->val, temp->val);
            }
        }
        root->left = deleteNode(root->left, key);
        root->right = deleteNode(root->right, key);
        
        return root;
    }
};