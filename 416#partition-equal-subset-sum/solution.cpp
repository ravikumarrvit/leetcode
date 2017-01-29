#define DEBUG 1

class Solution {
public:

    // dp based solution
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0), target_sum = sum >> 1;
        vector<int> dp(target_sum + 1, 0);
        
        if (sum & 1)
            return false;
            
        dp[0] = 1;
        
        for (auto n : nums) {
            for (int i = target_sum; i >= n; i--)
                dp[i] = dp[i] || dp[i - n];
        }
            
        return dp[target_sum];
    }

    // bitset based
    // bool canPartition(vector<int>& nums) {
    //     bitset<10001> bits(1);
    //     int sum = accumulate(nums.begin(), nums.end(), 0);
        
    //     if (sum & 1)
    //         return false;
        
    //     for (auto n : nums)
    //         bits |= bits << n;
            
    //     return bits[sum >> 1];
    // }
};