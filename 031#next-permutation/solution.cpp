class Solution {
public:

    void reverse_sort(vector<int>& nums, int start, int end) {
        while(start < end)
            swap(nums[start++], nums[end--]);
    }

    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), i, swap_index;
        
        if (n < 1)
            return;
        
        for (i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i])
                break;
        }
        
        if (i == 0) {
            reverse_sort(nums, 0, n - 1);
            return;
        }
        
        swap_index = i - 1;
        
        for (int j = n - 1; j >= i; j--) {
            if (nums[j] > nums[swap_index]) {
                swap(nums[j], nums[swap_index]);
                break;
            }
        }
        
        reverse_sort(nums, swap_index + 1, n - 1);
    }
};