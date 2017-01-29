/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Codec {
    
    void serialize(TreeNode *node, ostringstream &oss) {
        if (!node)
            return;
        oss << node->val << ",";
        serialize(node->left, oss);
        serialize(node->right, oss);
    }
    
    TreeNode* deserialize(const string &data, int &pos, int min_val, int max_val) {
        
        TreeNode *root = NULL;
        int val = 0, current_pos;
        
        if (pos == data.size())
            return root;
        
        current_pos = pos;
        
        while(data[current_pos] != ',') {
            val = (val * 10) + (data[current_pos] - '0');
            current_pos++;
        }
        
        current_pos++;
        
        if (val < min_val || val > max_val)
            return root;
        
        root = new TreeNode(val);
        
        pos = current_pos;
        
        root->left = deserialize(data, pos, min_val, root->val);
        root->right = deserialize(data, pos, root->val, max_val);
        
        return root;
    }
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serialize(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos = 0;
        
        return deserialize(data, pos, INT_MIN, INT_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));