/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
#define DEBUG 1
 
class Solution {
public:

    int get_depth(TreeNode *root, int level) {
        if (!root)
            return level - 1;
        if (!root->left && !root->right)
            return level;
        return max(get_depth(root->left, level + 1), get_depth(root->right, level + 1));
    }

    void zigzagLevelOrderRecurse(TreeNode* root, vector<vector<int>> &result, vector<stack<int>> &zigzag_stack, int level) {
        if (!root)
            return;
        if (level % 2 != 0) {
            if (DEBUG)
                cout << "val: " << root->val << endl;
            zigzag_stack[level].push(root->val);
        }
        else
            result[level].push_back(root->val);
            
        zigzagLevelOrderRecurse(root->left, result, zigzag_stack, level + 1);
        zigzagLevelOrderRecurse(root->right, result, zigzag_stack, level + 1);
    }

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<stack<int>> zigzag_stack;
        int depth;
        
        if (root == NULL)
            return result;
        
        depth = get_depth(root, 0);
        result.resize(depth + 1);
        zigzag_stack.resize(depth + 1);
        
        zigzagLevelOrderRecurse(root, result, zigzag_stack, 0);
        
        for (int i = 0; i < depth + 1; i++) {
            while (!zigzag_stack[i].empty()) {
                result[i].push_back(zigzag_stack[i].top());
                zigzag_stack[i].pop();
            }
        }
        
        return result;
    }
};