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

    void inorderTraverseRecurse(TreeNode* root, vector<int> &result) {
        if (!root)
            return;
        inorderTraverseRecurse(root->left, result);
        result.push_back(root->val);
        inorderTraverseRecurse(root->right, result);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        // vector<int> result;
        // if (root == NULL)
        //     return result;
        // inorderTraverseRecurse(root, result);
        // return result;
        
        vector<int> result;
        stack<TreeNode*> inorder_stack;
        TreeNode *current;
        
        if (root == NULL)
            return result;
        
        current = root;
        
        while(!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current = current->left;
            } else {
                current = inorder_stack.top();
                inorder_stack.pop();
                result.push_back(current->val);
                current = current->right;
            }
        }
        
        return result;
    }
};