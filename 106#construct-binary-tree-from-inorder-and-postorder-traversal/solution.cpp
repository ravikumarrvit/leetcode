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
    TreeNode* createTreeRecursive(vector<int>& inorder, vector<int>& postorder,
                                    int po_end, int io_start, int io_end) {
        TreeNode* root = NULL;
        int in_index;
        
        if (po_end > postorder.size() - 1 || io_start > inorder.size() - 1 || io_start > io_end)
            return root;
        root = new TreeNode(postorder[po_end]);
        for (int i = io_start; i <= io_end; i++) {
            if (inorder[i] == root->val) {
                in_index = i;
                break;
            }
        }
        
        root->left = createTreeRecursive(inorder, postorder, po_end - (io_end - in_index + 1) , io_start, in_index - 1);
        root->right = createTreeRecursive(inorder, postorder, po_end - 1, in_index + 1, io_end);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return createTreeRecursive(inorder, postorder, postorder.size() - 1, 0, inorder.size() - 1);
    }
};