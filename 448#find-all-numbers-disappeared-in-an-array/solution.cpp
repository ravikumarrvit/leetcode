class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> result;
        int n = nums.size(), pos;
        
        if (!n)
            return result;
        
        for (int i = 0; i < n; i++) {
            pos = nums[i] - 1;
            while(nums[pos] != nums[i]) {
                swap(nums[pos], nums[i]);
                pos = nums[i] - 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1)
                result.push_back(i + 1);
        }
        
        return result;
    }
};