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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> inorder_stack;
        TreeNode* current = root;
        
        while(!inorder_stack.empty() || current) {
            if (current) {
                inorder_stack.push(current);
                current = current->left;
            } else {
                current = inorder_stack.top();
                if (--k == 0)
                    return current->val;
                inorder_stack.pop();
                current = current->right;
            }
        }
        
        return current->val;
    }
};