class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int local_min, local_max, local_max_prev, local_min_prev;
        int max_prod;
        
        if (nums.size() == 0)
            return 0;
        
        local_min_prev = local_max_prev = max_prod = nums[0];
        
        for (int i = 1; i < nums.size(); i++) {
            local_max = max(max(local_max_prev * nums[i], local_min_prev * nums[i]), nums[i]);
            local_min = min(min(local_min_prev * nums[i], local_max_prev * nums[i]), nums[i]);
            
            max_prod = local_max > max_prod ? local_max : max_prod;
            
            local_max_prev = local_max;
            local_min_prev = local_min;
        }
        
        return max_prod;
    }
};