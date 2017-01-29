class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        vector<int> max_money(size);
        
        if (!size)
            return 0;
        
        if (size == 1)
            return nums[0];
        
        for (int i = 0; i < size; i++) {
            max_money[i] = nums[i];
            for (int j = i - 2; j >= 0; j--)
                max_money[i] = max(max_money[i], max_money[j] + nums[i]);
        }
        
        return max(max_money[size - 1], max_money[size - 2]);
    }
};