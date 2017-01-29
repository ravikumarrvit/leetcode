class Solution {
public:

    void reverse(vector<int>& nums, int start_index, int end_index) {
        while(start_index < end_index)
            swap(nums[start_index++], nums[end_index--]);
    }

    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        
        k = k >= n ? k % n : k;
        
        if (n == 1 || k == 0 || n == k)
            return;
        
        reverse(nums, 0, n - k - 1);
        
        reverse(nums, n - k, n - 1);
        
        reverse(nums, 0, n - 1);
    }
};