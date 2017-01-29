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

    void binaryTreePathsRecurse(TreeNode *root, vector<string> &result, string result_elem) {
        if (!root)
            return;
            
        result_elem.append((result_elem.empty()) ? to_string(root->val) : "->" + to_string(root->val));
        
        if (!root->left && !root->right)
            result.push_back(result_elem);
        
        binaryTreePathsRecurse(root->left, result, result_elem);
        binaryTreePathsRecurse(root->right, result, result_elem);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        string result_elem;
        
        if (!root)
            return result;
        
        binaryTreePathsRecurse(root, result, result_elem);
        
        return result;
    }
};