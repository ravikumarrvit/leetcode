class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size(), pos;
        vector<int> result;
        
        for (int i = 0; i < n; i++) {
            pos = nums[i] - 1;
            while (nums[pos] != nums[i]) {
                swap(nums[pos], nums[i]);
                pos = nums[i] - 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                result.push_back(nums[i]);
        }
        
        return result;
    }
};