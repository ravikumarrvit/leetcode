/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
    vector<int> inorder;
    int curr_elem_index, inorder_size;
public:
    
    void populate_inorder(TreeNode *root) {
        if (!root)
            return;
        populate_inorder(root->left);
        inorder.push_back(root->val);
        populate_inorder(root->right);
    }
    
    BSTIterator(TreeNode *root) {
        if (!root)
            return;
        inorder.clear();
        curr_elem_index = 0;
        populate_inorder(root);
        inorder_size = inorder.size();
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return (curr_elem_index < inorder_size) ? true : false;
    }

    /** @return the next smallest number */
    int next() {
        int next = inorder[curr_elem_index++];
        return next;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */