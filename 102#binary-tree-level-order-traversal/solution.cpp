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

    void levelOrderRecurse(TreeNode* root, int level, vector<vector<int>> &result, unordered_map<int, int> &level_map) {
        if (!root)
            return;
        if (!level_map[level]) {
            result.resize(result.size() + 1);
            level_map[level] = 1;
        }
        result[level].push_back(root->val);
        levelOrderRecurse(root->left, level + 1, result, level_map);
        levelOrderRecurse(root->right, level + 1, result, level_map);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        unordered_map<int, int> level_map;
        int level = 0;
        
        levelOrderRecurse(root, level, result, level_map);
        
        return result;
    }
};