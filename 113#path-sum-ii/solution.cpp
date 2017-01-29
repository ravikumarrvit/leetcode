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

    void pathSumRecurse(TreeNode *root, vector<vector<int>> &result, vector<int> result_elem, int remainder) {
        if (!root)
            return;
        if (root->val == remainder && !root->left && !root->right) {
            result_elem.push_back(root->val);
            result.push_back(result_elem);
        }
        result_elem.push_back(root->val);
        pathSumRecurse(root->left, result, result_elem, remainder - root->val);
        pathSumRecurse(root->right, result, result_elem, remainder - root->val);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        vector<int> result_elem;
        
        if (!root)
            return result;
        
        pathSumRecurse(root, result, result_elem, sum);
        
        return result;
    }
};