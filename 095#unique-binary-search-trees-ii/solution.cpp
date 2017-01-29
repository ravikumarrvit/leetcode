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

    vector<TreeNode*> generateTreesRecurse(int start, int end) {
        vector<TreeNode*> result, left_subtree, right_subtree;
        TreeNode* root;
        
        if (start > end) {
            result.push_back(NULL);
            return result;
        }
        
        for (int i = start; i <= end; i++) {
            
            left_subtree = generateTreesRecurse(start, i - 1);
            right_subtree = generateTreesRecurse(i + 1, end);
            
            for (auto left_st_node : left_subtree) {
                for (auto right_st_node : right_subtree) {
                    root = new TreeNode(i);
                    root->left = left_st_node;
                    root->right = right_st_node;
                    result.push_back(root);
                }
            }
        }
        
        return result;
    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> result;
        if (n < 1)
            return result;
        result = generateTreesRecurse(1, n);
        
        return result;
    }
};