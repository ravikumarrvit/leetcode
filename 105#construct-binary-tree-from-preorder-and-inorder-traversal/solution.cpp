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
    TreeNode* createTreeRecursive(vector<int>& preorder, vector<int>& inorder,
                                    int po_start, int io_start, int io_end) {
        TreeNode* root = NULL;
        int in_index;
        
        if (po_start > preorder.size() - 1  || io_start > inorder.size() - 1 || io_start > io_end)
            return root;
        root = new TreeNode(preorder[po_start]);
        for (int i = io_start; i <= io_end; i++) {
            if (inorder[i] == root->val) {
                in_index = i;
                break;
            }
        }
        
        root->left = createTreeRecursive(preorder, inorder, po_start + 1, io_start, in_index - 1);
        root->right = createTreeRecursive(preorder, inorder, po_start + (in_index - io_start) + 1, in_index + 1, io_end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return createTreeRecursive(preorder, inorder, 0, 0, inorder.size()-1);
    }
};