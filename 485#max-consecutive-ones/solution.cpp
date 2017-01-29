class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), prev, max_ones = 0, count = 0;
        
        if (!n)
            return n;
        
        for (int i = 0; i < n; i++) {
            if (i != 0 && nums[i] != prev && prev) {
                max_ones = (count > max_ones) ? count : max_ones;
                count = 0;
            } else if (nums[i] == 1) {
                count++;
            }
            prev = nums[i];
        }
        
        if (count)
            max_ones = (count > max_ones) ? count : max_ones;
        
        return max_ones;
    }
};