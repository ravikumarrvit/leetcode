class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> target_remainder;
        vector<int> result(2, -1);
        
        for (int i = 0; i < nums.size(); i++) {
            if (target_remainder[nums[i]]) {
                result[0] = target_remainder[nums[i]] - 1;
                result[1] = i;
                return result;
            } else {
                target_remainder[target - nums[i]] = i + 1;
            }
        }
        
        return result;
    }
};