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

    bool isSameTreeRecurse(TreeNode* p, TreeNode* q) {
        if (!p && !q)
            return true;
        if (!p)
            return false;
        if (!q)
            return false;
        if (p->val != q->val)
            return false;
        return isSameTreeRecurse(p->left, q->left) && isSameTreeRecurse(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return isSameTreeRecurse(p, q);
    }
};