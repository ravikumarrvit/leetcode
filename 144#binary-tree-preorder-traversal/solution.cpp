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

    void preOrderRecurse(TreeNode* root, vector<int> &result) {
        if (!root)
            return;
        result.push_back(root->val);
        preOrderRecurse(root->left, result);
        preOrderRecurse(root->right, result);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        
        // preOrderRecurse(root, result);
        
        stack<TreeNode*> pre_order_stack;
        TreeNode *current;
        
        if (!root)
            return result;
        
        current = root;
        
        while (!pre_order_stack.empty() || current) {
            if (current) {
                result.push_back(current->val);
                pre_order_stack.push(current);
                current = current->left;
            } else {
                current = pre_order_stack.top();
                pre_order_stack.pop();
                current = current->right;
            }
        }
        return result;
    }
};