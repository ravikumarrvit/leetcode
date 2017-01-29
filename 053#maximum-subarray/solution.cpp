class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int dp[n], max_sum = 0;
        
        if (!n)
            return max_sum;
        
        dp[0] = nums[0], max_sum = nums[0];
        
        for (int i = 1; i < n; i++) {
            dp[i] = nums[i] + ((dp[i - 1] > 0) ? dp[i - 1] : 0);
            max_sum = max(max_sum, dp[i]);
        }
        
        return max_sum;
    }
};