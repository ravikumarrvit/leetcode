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

    bool isSymmetricRecurse(TreeNode* root, int level, vector<stack<int>> &result, 
                            unordered_map<int, int> &level_map, string dir) {
        if (!root) {
            if (level_map[level] && !result[level].empty()) {
                if (dir == "L")
                    result[level].push(INT_MIN);
                else if (dir == "R" && result[level].top() == INT_MIN)
                    result[level].pop();
                else
                    return false;
            }
            return true;
        }
        if (!level_map[level]) {
            result.resize(result.size() + 1);
            level_map[level] = 1;
        }
        if (dir == "L")
            result[level].push(root->val);
        else if (dir == "R") {
            if (result[level].empty() || result[level].top() != root->val)
                return false;
            else if (result[level].top() == root->val)
                result[level].pop();
        }
            
        return isSymmetricRecurse(root->left, level + 1, result, level_map, dir == "" ? "L" : dir) && isSymmetricRecurse(root->right, level + 1, result, level_map, dir == "" ? "R" : dir);
    }

    bool isSymmetric(TreeNode* root) {
        vector<stack<int>> result;
        unordered_map<int, int> level_map;
        int level = 0;
        
        return isSymmetricRecurse(root, level, result, level_map, "");
    }
};