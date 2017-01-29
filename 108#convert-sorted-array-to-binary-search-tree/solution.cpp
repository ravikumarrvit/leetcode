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
    
    TreeNode* sortedArrayToBSTRecurse(vector<int> &nums, int low, int high) {
        int mid;
        TreeNode* root;
        if (low > high)
            return NULL;
        mid = low + (high - low)/2;
        root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRecurse(nums, low, mid - 1);
        root->right = sortedArrayToBSTRecurse(nums, mid + 1, high);
        
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        return sortedArrayToBSTRecurse(nums, low, high);
    }
};