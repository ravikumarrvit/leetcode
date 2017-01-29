/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
#define DEBUG 1

class Solution {
public:
    
    void connectRecurse(TreeLinkNode *node) {
        TreeLinkNode *next_addr, *temp_node;
        
        if (!node)
            return;
        
        if (node->left) {
            if (node->right)
                node->left->next = node->right;
        }
        
        if (node->next) {
            temp_node = node->next;
            while(temp_node) {
                next_addr = (temp_node->left) ? (temp_node->left) : (temp_node->right);
                if (!next_addr)
                    temp_node = temp_node->next;
                else
                    break;
            }
        } else {
            next_addr = NULL;
        }
            
        if (node->right)
            node->right->next = next_addr;
        else if (node->left && !node->right)
            node->left->next = next_addr;
        
        connectRecurse(node->right);
        connectRecurse(node->left);
    }
    
    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        root->next = NULL;
        connectRecurse(root);
    }
};