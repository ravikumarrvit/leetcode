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

    // void flattenRecurse(TreeNode *root, string dir, stack<TreeNode*> &last_left_node_stack) {
    //     if (!root)
    //         return;
    //     if (dir == "L")
    //         last_left_node_stack.push(root);
    //     if (!root->left && !root->right)
    //         return;
        
    //     flattenRecurse(root->right, (dir == "") ? "R" : dir, last_left_node_stack);
    //     flattenRecurse(root->left, "L", last_left_node_stack);
        
    //     if (!last_left_node_stack.empty() && root->left) {
    //         TreeNode *last_node_on_left, *temp_node;
    //         last_node_on_left = last_left_node_stack.top();
    //         last_node_on_left->right = root->right;
    //         temp_node = root->right;
    //         while (temp_node && temp_node->right != NULL)
    //             temp_node = temp_node->right;
    //         if(temp_node)
    //             last_left_node_stack.push(temp_node);
    //         root->right = root->left;
    //         root->left = NULL;
    //     }
        
    // }
    
    void flattenRecurse(TreeNode *root, string dir, TreeNode *&last_node_on_left) {
        if (!root)
            return;
        if (dir == "L")
            last_node_on_left = root;
        if (!root->left && !root->right)
            return;
            
        flattenRecurse(root->right, (dir == "") ? "R" : dir, last_node_on_left);
        flattenRecurse(root->left, "L", last_node_on_left);
        
        if (last_node_on_left && root->left) { // Very important: check the second condition
            TreeNode *temp_node;
            last_node_on_left->right = root->right;
            temp_node = root->right;
            
            // Need to set the last_node_on_left to the rightmost node of left subtree
            while (temp_node && temp_node->right)
                temp_node = temp_node->right;
            if(temp_node)
                last_node_on_left = temp_node;
            root->right = root->left;
            root->left = NULL;
        }
        
    }

    void flatten(TreeNode* root) {
        TreeNode *last_node_on_left = NULL;
        flattenRecurse(root, "", last_node_on_left);
    }
};