class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int lis[size];
        
        if (!size || size == 1)
            return size;
        
        lis[0] = 1;
        
        for (int i = 1; i < size; i++) {
            lis[i] = 1;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i])
                    lis[i] = max(lis[i], lis[j] + 1);
            }
        }
        
        return *max_element(lis, lis + size);
    }
};