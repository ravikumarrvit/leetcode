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

    void postorderRecurse(TreeNode *root, vector<int> &result) {
        if (!root)
            return;
        postorderRecurse(root->left, result);
        postorderRecurse(root->right, result);
        result.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> post_order_stack;
        unordered_map<TreeNode*, int> left_subtree, right_subtree;
        TreeNode *current;
        
        // postorderRecurse(root, result);
        
        if (!root)
            return result;
            
        current = root;
        
        while (!post_order_stack.empty() || current) {
            if (current) {
                post_order_stack.push(current);
                left_subtree[current] = true;
                current = current->left;
            } else {
                current = post_order_stack.top();
                if (!right_subtree[current]) {
                    right_subtree[current] = true;
                    current = current->right;
                } else {
                    post_order_stack.pop();
                    result.push_back(current->val);
                    current = NULL;
                }
            }
        }
        
        return result;
    }
};