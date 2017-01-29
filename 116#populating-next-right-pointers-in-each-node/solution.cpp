/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:

    void connectRecurse(TreeLinkNode *root) {
        if (!root || (!root->left && !root->right))
            return;
        root->left->next = root->right;
        if (root->next != NULL)
            root->right->next = root->next->left;
        else
            root->right->next = NULL;
        connectRecurse(root->left);
        connectRecurse(root->right);
    }

    void connect(TreeLinkNode *root) {
        if (!root)
            return;
        root->next = NULL;
        connectRecurse(root);
    }
};